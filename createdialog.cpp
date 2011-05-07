#include "createdialog.h"
#include "ui_createdialog.h"

CreateDialog::CreateDialog(QWidget *parent, QSqlRelationalTableModel *modelP, bool create, int index) :
        QDialog(parent),
        ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
    model = modelP;
    /* Determining the reference number */
    QDateTime now = QDateTime::currentDateTime();
    if(create){
        QString nName = "", nRef = "#"+QString::number(now.date().year());
        // correct the missing tailing zero for months inferior to october.
        nRef.append(now.date().month()<10?QString("0").append(QString::number(now.date().month())):QString::number(now.date().month()));
        nRef.append(now.date().day()<10?QString("0").append(QString::number(now.date().day())):QString::number(now.date().day()));
        nRef.append("-");
        nRef.append(QString::number(backbone::instance()->count("ref","items",nRef)));
        nName.append(tr("New item"));
        nName.append(QString::number(backbone::instance()->count("name","addresses",nName)));
#ifdef DEBUG
        qDebug() << "Final ref = {" << nRef <<"}";
#endif
        ui->refLineEdit->setText(nRef);
        /* Modify dates */
        ui->entryDateEdit->setDateTime(now);
        ui->recordDateEdit->setDateTime(now);
        /* Insert new information */
        /*backbone::instance()->execMQueries("INSERT INTO items (ref, name, entrydate, recorddate, description, location_id, status_id) "
                                           "VALUES (:r, :n, :e, :re, :d, :l, :s)");*/
        backbone::instance()->query.prepare("INSERT INTO items (ref, name, entrydate, description, location_id, status_id) "
                                            "VALUES ('"+nRef+"', '"+nName+"', '"+ui->entryDateEdit->text()+"', '"+tr("No description")+"', '0', '0')");
        qDebug() << backbone::instance()->execQ();
        model->select();
    }
    ui->recordDateEdit->hide();
    ui->dateOnItemLabel->hide();

    /* Set up status model */
    ui->statusCB->clear();
    qDebug() << "status_id = " << model->fieldIndex("status_id");
    int statusFieldId = 9;//This returns -1 for an unknown reason: model->fieldIndex("status_id"); it does exist in the table though...
    statusRelModel = model->relationModel(statusFieldId);
    ui->statusCB->setModel(statusRelModel);
    ui->statusCB->setModelColumn(statusRelModel->fieldIndex("name"));
    /* Set up location model */
    ui->locationCB->clear();
    qDebug() << "location_id = " << model->fieldIndex("location_id");
    int locationFieldId = 8;//This returns -1 for an unknown reason: model->fieldIndex("status_id"); it does exist in the table though...
    locationRelModel = model->relationModel(locationFieldId);
    ui->locationCB->setModel(locationRelModel);
    ui->locationCB->setModelColumn(locationRelModel->fieldIndex("name"));
    /* Data mapping */
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->nameLineEdit, model->fieldIndex("name"));
    mapper->addMapping(ui->refLineEdit, model->fieldIndex("ref"));
    mapper->addMapping(ui->statusCB, statusFieldId);
    mapper->addMapping(ui->locationCB, locationFieldId);
    mapper->addMapping(ui->recordDateEdit, model->fieldIndex("recorddate"));
    mapper->addMapping(ui->entryDateEdit, model->fieldIndex("entrydate"));
    mapper->addMapping(ui->descriptionTextEdit, model->fieldIndex("description"));
    if(create){
        mapper->toFirst();
    }else{
        mapper->setCurrentIndex(index);
    }
    /* Signals */
    connect(ui->overrideCheckBox,SIGNAL(clicked()),this,SLOT(overrideRef()));
    connect(ui->dateItemCheckBox,SIGNAL(clicked()),this,SLOT(dateItem()));
}

CreateDialog::~CreateDialog()
{
    delete ui;
}

void CreateDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CreateDialog::accept()
{
    if(ui->nameLineEdit->text().length() < 5){
        QMessageBox::critical(0, tr("Error"),tr("The name must be at least 5 characters long."), QMessageBox::Cancel);
        return;
    }else if(ui->locationCB->currentIndex() < 0){
        QMessageBox::critical(0, tr("Error"),tr("The item must be in a location."), QMessageBox::Cancel);
        return;
    }else if(ui->statusCB->currentIndex() < 0){
        QMessageBox::critical(0, tr("Error"),tr("The item must have a status."), QMessageBox::Cancel);
        return;
    }
#ifdef DEBUG
    qDebug() <<
#endif
            model->submitAll();
#ifdef DEBUG
    qDebug() <<
#endif
            mapper->submit();
#ifdef DEBUG
    qDebug() << backbone::instance()->db.lastError();
    qDebug() << model->lastError();
#endif
    this->close();
}

void CreateDialog::overrideRef()
{
    ui->refLineEdit->setReadOnly(!ui->refLineEdit->isReadOnly());
}

void CreateDialog::dateItem()
{
    ui->recordDateEdit->setVisible(ui->dateItemCheckBox->isChecked());
    ui->dateOnItemLabel->setVisible(ui->dateItemCheckBox->isChecked());
}
