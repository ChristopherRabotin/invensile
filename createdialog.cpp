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
    qDebug() << "b";

    query.prepare("INSERT INTO 'items' (ref, name, entrydate, recorddate, description, location_id) "
                  "VALUES ('test', 'nam', 'entrydat', 'recorddat', 'descriptio', 'location_i')");
    /*query.prepare("INSERT INTO items (ref, name, entrydate, recorddate, description, location_id) "
                   "VALUES (:ref, :name, :entrydate, :recorddate, :description, :location_id)");
     query.bindValue(":ref", 1001);
     query.bindValue(":name", ui->nameLineEdit->text());
     query.bindValue(":entrydate", ui->entryDateEdit->text());
     query.bindValue(":recorddate", ui->recordDateEdit->text());
     query.bindValue(":description", ui->descriptionTextEdit->toPlainText());
     query.bindValue(":location_id", "0");*/
    //qDebug()<<query.exec();
    //qDebug() << query.exec();
    query.exec();
    qDebug() << query.executedQuery();

}
