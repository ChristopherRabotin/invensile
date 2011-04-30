#include "createlocationdialog.h"
#include "ui_createlocationdialog.h"

CreateLocationDialog::CreateLocationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateLocationDialog)
{
    ui->setupUi(this);
    /* Modify dates */
    QDateTime now = QDateTime::currentDateTime();
    ui->closingDateEdit->setDateTime(now);
    ui->creationDateEdit->setDateTime(now);
    /* Hide closing location UIs */
    ui->closingDateEdit->setVisible(false);
    ui->closingLabel->setVisible(false);
    /* Set up location model */
    ui->addressCB->clear();
    QSqlRelationalTableModel *addressModel = new QSqlRelationalTableModel(this, backbone::instance()->db);
    addressModel->setTable("addresses");
    addressModel->setRelation(0,QSqlRelation("addresses", "id", "name"));
    addressModel->select();
    ui->addressCB->setModel(addressModel);
    /* Set up location model */
    ui->locationCB->clear();
    QSqlRelationalTableModel *locationModel = new QSqlRelationalTableModel(this, backbone::instance()->db);
    locationModel->setTable("locations");
    locationModel->setRelation(0,QSqlRelation("locations", "id", "name"));
    locationModel->select();
    ui->locationCB->setModel(locationModel);
    /* Set up status model */
    ui->statusCB->clear();
    QSqlRelationalTableModel *statusModel = new QSqlRelationalTableModel(this, backbone::instance()->db);
    statusModel->setTable("statuses");
    statusModel->setRelation(0,QSqlRelation("statuses", "id", "name"));
    statusModel->select();
    ui->statusCB->setModel(statusModel);
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
    qDebug() << "accepted!";
}
