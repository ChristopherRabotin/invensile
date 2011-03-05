#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->addButton, SIGNAL(clicked()),this,SLOT(addContact()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::newDb()
{
    QString dbFile = QFileDialog::getExistingDirectory(this,
                                   tr("Select directory"), QDir::currentPath());
        /* now we create the database file */


   db.setDatabaseName(dbFile);
        if (!db.open()) {
            QMessageBox::critical(0, tr("Cannot open database"),
                tr("Unable to establish a database connection."), QMessageBox::Cancel);
            return;
        }

        QSqlQuery query;
        query.exec("PRAGMA foreignkey = ON");

        /* to use color: QColor::name() , get the value and prepend with '#' */
}
void MainWindow::openDb()
{

}
void MainWindow::closeDb()
{

}
void MainWindow::exportInventory()
{

}
void MainWindow::modify()
{

}
void MainWindow::create()
{

}
void MainWindow::preferences()
{

}
void MainWindow::about()
{

}
