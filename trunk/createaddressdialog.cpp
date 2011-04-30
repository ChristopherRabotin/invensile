#include "createaddressdialog.h"
#include "ui_createaddressdialog.h"

CreateAddressDialog::CreateAddressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAddressDialog)
{
    ui->setupUi(this);
    /* Set up status model */
    ui->statusCB->clear();
    QSqlRelationalTableModel *statusModel = new QSqlRelationalTableModel(this, backbone::instance()->db);
    statusModel->setTable("addresses");
    statusModel->setRelation(0,QSqlRelation("statuses", "id", "name"));
    statusModel->select();
    ui->statusCB->setModel(statusModel);
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
    }else if(ui->refLineEdit->text().length() > 10){
        QMessageBox::critical(0, tr("Error"),tr("The reference may not be more than 10 characters long."), QMessageBox::Cancel);
        return;
    }else if(ui->statusCB->currentIndex() < 0){
        QMessageBox::critical(0, tr("Error"),tr("The item must have a status."), QMessageBox::Cancel);
        return;
    }
    backbone::instance()->query.prepare("INSERT INTO addresses (ref, name, country, town, postal_code, street, status_id) "
                                        "VALUES (:r, :n, :c, :t, :p, :st, :s)");
    backbone::instance()->query.bindValue(":r", ui->refLineEdit->text());
    backbone::instance()->query.bindValue(":n", ui->nameLineEdit->text());
    backbone::instance()->query.bindValue(":c", ui->countryLineEdit->text());
    backbone::instance()->query.bindValue(":t", ui->townLineEdit->text());
    backbone::instance()->query.bindValue(":p", ui->postalCodeLineEdit->text());
    backbone::instance()->query.bindValue(":st", ui->streetLineEdit->text());
    backbone::instance()->query.bindValue(":s", ui->statusCB->currentText());
    backbone::instance()->query.exec();
#ifdef DEBUG
    qDebug() << "Error = {" << backbone::instance()->query.lastError().text() << "}";
    qDebug() << "Latest query = {" << backbone::instance()->query.executedQuery() << "}";
#endif
    if(backbone::instance()->query.lastError().isValid()){
        QMessageBox::critical(0, tr("Error"),backbone::instance()->query.lastError().text(), QMessageBox::Cancel);
        return;
    }
    this->close();
}
