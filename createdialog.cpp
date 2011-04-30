#include "createdialog.h"
#include "ui_createdialog.h"

CreateDialog::CreateDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
    /* Determining the reference number */
    QDateTime now = QDateTime::currentDateTime();
    QString ref = "#"+QString::number(now.date().year());
    // correct the missing tailing zero for months inferior to october.
    ref.append(now.date().month()<10?QString("0").append(QString::number(now.date().month())):QString::number(now.date().month()));
    ref.append(QString::number(now.date().day())+"-");
    backbone::instance()->query.exec("SELECT COUNT(ref) FROM items WHERE ref LIKE '"+ref+"%'");
    int numRef = 1;
    if (backbone::instance()->query.next()) {
        numRef = backbone::instance()->query.value(0).toString().toInt()+1;
    }
    ref.append(QString::number(numRef));
#ifdef DEBUG
    qDebug() << "Final ref = {" << ref <<"}";
#endif
    ui->refLineEdit->setText(ref);
    /* Modify dates */
    ui->entryDateEdit->setDateTime(now);
    ui->recordDateEdit->setDateTime(now);
    ui->recordDateEdit->hide();
    ui->dateOnItemLabel->hide();
    /* Set up location model */
    ui->locationCB->clear();
    QSqlRelationalTableModel *locationModel = new QSqlRelationalTableModel(this, backbone::instance()->db);
    locationModel->setTable("items");
    locationModel->setRelation(8,QSqlRelation("locations", "id", "name"));
    locationModel->select();
    ui->locationCB->setModel(locationModel);
    /* Set up status model */
    ui->statusCB->clear();
    QSqlRelationalTableModel *statusModel = new QSqlRelationalTableModel(this, backbone::instance()->db);
    statusModel->setTable("items");
    statusModel->setRelation(9,QSqlRelation("statuses", "id", "name"));
    statusModel->select();
    qDebug() << "Status valid " << statusModel->relation(9).isValid();
    ui->statusCB->setModel(statusModel);
    /* Signals */
    connect(ui->overrideCheckBox,SIGNAL(clicked()),this,SLOT(overrideRef()));
    connect(ui->dateItemCheckBox,SIGNAL(clicked()),this,SLOT(dateItem()));
    /* The following signal is not necessary because both functions are already connected. */
    //connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
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
    backbone::instance()->query.prepare("INSERT INTO items (ref, name, entrydate, recorddate, description, location_id, status_id) "
                                        "VALUES (:r, :n, :e, :re, :d, :l, :s)");
    backbone::instance()->query.bindValue(":r", ui->refLineEdit->text());
    backbone::instance()->query.bindValue(":n", ui->nameLineEdit->text());
    backbone::instance()->query.bindValue(":e", ui->entryDateEdit->text());
    backbone::instance()->query.bindValue(":re", ui->recordDateEdit->text());
    backbone::instance()->query.bindValue(":d", ui->descriptionTextEdit->toPlainText());
    backbone::instance()->query.bindValue(":l", ui->locationCB->currentText());
    backbone::instance()->query.bindValue(":s", ui->statusCB->currentText());
    backbone::instance()->query.exec();
#ifdef DEBUG
    qDebug() << ":r = {" << ui->refLineEdit->text() << "}\n:n = {" << ui->nameLineEdit->text() << "}\n:e = {"<<
            ui->entryDateEdit->text()<<"}\n:re = {" << ui->recordDateEdit->text() << "}\n:d = {" <<
            ui->descriptionTextEdit->toPlainText() << "}\n:l = {" <<
            ui->locationCB->currentText() << "}\n:s = {" <<
            ui->statusCB->currentText() << "}";
    qDebug() << "Error = {" << backbone::instance()->query.lastError().text() << "}";
    qDebug() << "Latest query = {" << backbone::instance()->query.executedQuery() << "}";
#endif
    if(backbone::instance()->query.lastError().isValid()){
        QMessageBox::critical(0, tr("Error"),backbone::instance()->query.lastError().text(), QMessageBox::Cancel);
        return;
    }
    this->close();
}

void CreateDialog::overrideRef()
{
    ui->refLineEdit->setReadOnly(!ui->refLineEdit->isReadOnly());
    //(ui->refLineEdit->isEnabled())?ui->refLineEdit->setDisabled(true):ui->refLineEdit->setEnabled(true);
}

void CreateDialog::dateItem()
{
    ui->recordDateEdit->setVisible(ui->dateItemCheckBox->isChecked());
    ui->dateOnItemLabel->setVisible(ui->dateItemCheckBox->isChecked());
}
