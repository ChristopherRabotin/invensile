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
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(submit()));
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

void CreateDialog::submit()
{
    QSqlQuery q;
    q.exec("SELECT ref FROM 'locations' WHERE id='1'");
    qDebug() << q.nextResult();
}
