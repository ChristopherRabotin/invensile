#include "createdialog.h"
#include "ui_createdialog.h"

CreateDialog::CreateDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
    ui->entryDateEdit->setDisplayFormat("yyyy.mm.dd");
    ui->recordDateEdit->setDisplayFormat("yyyy.mm.dd");
    ui->entryDateEdit->setCalendarPopup(true);
    ui->recordDateEdit->setCalendarPopup(true);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
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
    backbone::instance()->query.prepare("INSERT INTO items (ref, name, entrydate, recorddate, description, location_id) "
                                        "VALUES (:r, :n, :e, :re, :d, :l)");
    backbone::instance()->query.bindValue(":r", "1001");
    backbone::instance()->query.bindValue(":n", ui->nameLineEdit->text());
    backbone::instance()->query.bindValue(":e", ui->entryDateEdit->text());
    backbone::instance()->query.bindValue(":re", ui->recordDateEdit->text());
    backbone::instance()->query.bindValue(":d", ui->descriptionTextEdit->toPlainText());
    backbone::instance()->query.bindValue(":l", "1");
    backbone::instance()->query.exec();
#ifdef DEBUG
    qDebug() << ":r = {1001}" << "\n:n = {" << ui->nameLineEdit->text() << "}\n:e = {"<<
            ui->entryDateEdit->text()<<"}\n:re = {" << ui->recordDateEdit->text() << "}\n:d = " <<
            ui->descriptionTextEdit->toPlainText() << "}";
    qDebug() << "Error = {" << backbone::instance()->query.lastError().text() << "}";
    qDebug() << "Latest query = {" << backbone::instance()->query.executedQuery() << "}";
#endif
    this->close();
}
