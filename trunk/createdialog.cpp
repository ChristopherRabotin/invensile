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
    /* Set up location model */
    ui->locationCB->clear();
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this, backbone::instance()->db);
    model->setTable("items");
    model->setRelation(0,QSqlRelation("locations", "id", "name"));
    model->select();
    ui->locationCB->setModel(model);
    /* Signals */
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
    }
    backbone::instance()->query.prepare("INSERT INTO items (ref, name, entrydate, recorddate, description, location_id) "
                                        "VALUES (:r, :n, :e, :re, :d, :l)");
    backbone::instance()->query.bindValue(":r", ui->refLineEdit->text());
    backbone::instance()->query.bindValue(":n", ui->nameLineEdit->text());
    backbone::instance()->query.bindValue(":e", ui->entryDateEdit->text());
    backbone::instance()->query.bindValue(":re", ui->recordDateEdit->text());
    backbone::instance()->query.bindValue(":d", ui->descriptionTextEdit->toPlainText());
    backbone::instance()->query.bindValue(":l", "1");
    backbone::instance()->query.exec();
#ifdef DEBUG
    qDebug() << ":r = {1001}" << "\n:n = {" << ui->nameLineEdit->text() << "}\n:e = {"<<
            ui->entryDateEdit->text()<<"}\n:re = {" << ui->recordDateEdit->text() << "}\n:d = {" <<
            ui->descriptionTextEdit->toPlainText() << "}";
    qDebug() << "Error = {" << backbone::instance()->query.lastError().text() << "}";
    qDebug() << "Latest query = {" << backbone::instance()->query.executedQuery() << "}";
#endif
    this->close();
}
