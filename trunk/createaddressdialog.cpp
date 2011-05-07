#include "createaddressdialog.h"
#include "ui_createaddressdialog.h"

CreateAddressDialog::CreateAddressDialog(QWidget *parent, QSqlRelationalTableModel *model) :
    QDialog(parent),
    ui(new Ui::CreateAddressDialog)
{
    ui->setupUi(this);

    /* Set up status model */
    ui->statusCB->clear();
    localModel = model;
    int statusFieldId = 7;//This returns -1 for an unknown reason: localModel->fieldIndex("status_id"); it does exist in the table though...
    relModel = localModel->relationModel(statusFieldId);
    ui->statusCB->setModel(relModel);
    ui->statusCB->setModelColumn(relModel->fieldIndex("name"));
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(localModel);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->refLineEdit, localModel->fieldIndex("ref"));
    mapper->addMapping(ui->nameLineEdit, localModel->fieldIndex("name"));
    mapper->addMapping(ui->statusCB, statusFieldId);
    mapper->addMapping(ui->countryLineEdit, localModel->fieldIndex("country"));
    mapper->addMapping(ui->townLineEdit, localModel->fieldIndex("town"));
    mapper->addMapping(ui->postalCodeLineEdit, localModel->fieldIndex("postal_code"));
    mapper->addMapping(ui->streetLineEdit, localModel->fieldIndex("street"));
    mapper->toFirst();

    connect(ui->previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(ui->nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
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
    if(ui->nameLineEdit->text().length() < 5){
        QMessageBox::critical(0, tr("Error"),tr("The name must be at least 5 characters long."), QMessageBox::Cancel);
        return;
    }else if(ui->nameLineEdit->text().length() > 50){
        QMessageBox::critical(0, tr("Error"),tr("The name must be less than 50 characters long."), QMessageBox::Cancel);
        return;
    }else if(ui->refLineEdit->text().length() < 3 || ui->refLineEdit->text().length() > 10){
        QMessageBox::critical(0, tr("Error"),tr("The reference must be between 3 and 10 characters long."), QMessageBox::Cancel);
        return;
    }else if(ui->statusCB->currentIndex() < 0){
        QMessageBox::critical(0, tr("Error"),tr("The item must have a status."), QMessageBox::Cancel);
        return;
    }
#ifdef DEBUG
    qDebug() <<
#endif
            mapper->submit();
    this->close();
}

void CreateAddressDialog::updateButtons(int row)
{
    ui->previousButton->setEnabled(row > 0);
    ui->nextButton->setEnabled(row < localModel->rowCount() - 1);
}
