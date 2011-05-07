#include "createlocationdialog.h"
#include "ui_createlocationdialog.h"

CreateLocationDialog::CreateLocationDialog(QWidget *parent, QSqlRelationalTableModel *modelP, bool create, int index) :
        QDialog(parent),
        ui(new Ui::CreateLocationDialog)
{
    ui->setupUi(this);
    model = modelP;
    /* Determining the reference number */
    QDateTime now = QDateTime::currentDateTime();
    if(create){
        QString nName = "", nRef = tr("Ref");
        nName.append(tr("New location"));
        nName.append(QString::number(backbone::instance()->count("name","addresses",nName)));
        nRef.append(QString::number(backbone::instance()->count("ref","addresses",nRef)));
        /* Modify dates */
        ui->closingDateEdit->setDateTime(now);
        ui->creationDateEdit->setDateTime(now);
        /* Insert new information */
        backbone::instance()->execMQueries("INSERT INTO locations (ref, name, creationdate, description, address_id, location_id, status_id) "
                                            "VALUES ('"+nRef+"', '"+nName+"', '"+ui->creationDateEdit->text()+"', '"+tr("No description")+"', '0', '0', '0')");
        model->select();
    }

    /* Hide closing location UIs */
    ui->closingDateEdit->setVisible(false);
    ui->closingLabel->setVisible(false);
    /* Set up address model */
    ui->addressCB->clear();
    qDebug() << "address_id = " << model->fieldIndex("location_id");
    int addressFieldId = 7;//This returns -1 for an unknown reason: model->fieldIndex("status_id"); it does exist in the table though...
    addressRelModel = model->relationModel(addressFieldId);
    ui->addressCB->setModel(addressRelModel);
    ui->addressCB->setModelColumn(addressRelModel->fieldIndex("name"));
    /* Set up location model */
    ui->locationCB->clear();
    qDebug() << "location_id = " << model->fieldIndex("location_id");
    int locationFieldId = 8;//This returns -1 for an unknown reason: model->fieldIndex("status_id"); it does exist in the table though...
    locationRelModel = model->relationModel(locationFieldId);
    ui->locationCB->setModel(locationRelModel);
    ui->locationCB->setModelColumn(locationRelModel->fieldIndex("name"));
    /* Set up status model */
    ui->statusCB->clear();
    qDebug() << "status_id = " << model->fieldIndex("status_id");
    int statusFieldId = 9;//This returns -1 for an unknown reason: model->fieldIndex("status_id"); it does exist in the table though...
    statusRelModel = model->relationModel(statusFieldId);
    ui->statusCB->setModel(statusRelModel);
    ui->statusCB->setModelColumn(statusRelModel->fieldIndex("name"));

    /* Data mapping */
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->nameLineEdit, model->fieldIndex("name"));
    mapper->addMapping(ui->refLineEdit, model->fieldIndex("ref"));
    mapper->addMapping(ui->statusCB, statusFieldId);
    mapper->addMapping(ui->locationCB, locationFieldId);
    mapper->addMapping(ui->addressCB, addressFieldId);
    mapper->addMapping(ui->creationDateEdit, model->fieldIndex("creationdate"));
    mapper->addMapping(ui->closingDateEdit, model->fieldIndex("closingdate"));
    mapper->addMapping(ui->descriptionTextEdit, model->fieldIndex("description"));
    if(create){
        mapper->toFirst();
    }else{
        mapper->setCurrentIndex(index);
    }
    /* Signals */
    connect(ui->closedLocationCheckBox,SIGNAL(clicked()),this,SLOT(closeLocation()));
}

CreateLocationDialog::~CreateLocationDialog()
{
    delete ui;
}

void CreateLocationDialog::changeEvent(QEvent *e)
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

void CreateLocationDialog::closeLocation()
{
    ui->closingDateEdit->setVisible(ui->closedLocationCheckBox->isChecked());
    ui->closingLabel->setVisible(ui->closedLocationCheckBox->isChecked());
}

void CreateLocationDialog::accept()
{
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
