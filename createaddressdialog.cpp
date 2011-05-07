#include "createaddressdialog.h"
#include "ui_createaddressdialog.h"

CreateAddressDialog::CreateAddressDialog(QWidget *parent, QSqlRelationalTableModel *modelP, bool create, int index) :
    QDialog(parent),
    ui(new Ui::CreateAddressDialog)
{
    ui->setupUi(this);

    model = modelP;

    if(create){
        /* Insert new information */
        QString nName = "", nRef = tr("Ref");
        nName.append(tr("New address"));
        nName.append(QString::number(backbone::instance()->count("name","addresses",nName)));
        nRef.append(QString::number(backbone::instance()->count("ref","addresses",nRef)));
        backbone::instance()->execMQueries("INSERT INTO 'addresses' (name,ref,status_id) VALUES ('"+nName+"','"+nRef+"','0');");
        model->select();
    }
    /* Set up status model */
    ui->statusCB->clear();
    int statusFieldId = 7;//This returns -1 for an unknown reason: model->fieldIndex("status_id"); it does exist in the table though...
    relModel = model->relationModel(statusFieldId);
    ui->statusCB->setModel(relModel);
    ui->statusCB->setModelColumn(relModel->fieldIndex("name"));
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->refLineEdit, model->fieldIndex("ref"));
    mapper->addMapping(ui->nameLineEdit, model->fieldIndex("name"));
    mapper->addMapping(ui->statusCB, statusFieldId);
    mapper->addMapping(ui->countryLineEdit, model->fieldIndex("country"));
    mapper->addMapping(ui->townLineEdit, model->fieldIndex("town"));
    mapper->addMapping(ui->postalCodeLineEdit, model->fieldIndex("postal_code"));
    mapper->addMapping(ui->streetLineEdit, model->fieldIndex("street"));
    if(create){
        mapper->toFirst();
    }else{
        mapper->setCurrentIndex(index);
    }

    /* Focus values connect */
    connect(ui->refLineEdit,SIGNAL(editingFinished()),this,SLOT(checkValues()));
    connect(ui->nameLineEdit,SIGNAL(editingFinished()),this,SLOT(checkValues()));
}

CreateAddressDialog::~CreateAddressDialog()
{
    delete ui;
}

void CreateAddressDialog::changeEvent(QEvent *e)
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

void CreateAddressDialog::accept()
{
    //checkValues();
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

void CreateAddressDialog::checkValues(){
    model->select();
    /* The following should not happen because of input mask restriction. */
    if(ui->nameLineEdit->text().length() < 5){
        QMessageBox::critical(0, tr("Error"),tr("The name must be at least 5 characters long."), QMessageBox::Cancel);
        ui->nameLineEdit->setFocus();
    }else if(ui->nameLineEdit->text().length() > 50){
        QMessageBox::critical(0, tr("Error"),tr("The name must be less than 50 characters long."), QMessageBox::Cancel);
        ui->nameLineEdit->setFocus();
    }else if(ui->refLineEdit->text().length() < 3 || ui->refLineEdit->text().length() > 10){
        QMessageBox::critical(0, tr("Error"),tr("The reference must be between 3 and 10 characters long."), QMessageBox::Cancel);
        ui->refLineEdit->setFocus();
    }else if(ui->statusCB->currentIndex() < 0){
        QMessageBox::critical(0, tr("Error"),tr("The item must have a status."), QMessageBox::Cancel);
        ui->statusCB->setFocus();
    }
}
