#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->hide();
    ui->actionClose->setDisabled(true);
    // connect(ui->addButton, SIGNAL(clicked()),this,SLOT(addContact()));
    connect(ui->actionNew, SIGNAL(triggered()),this,SLOT(newDb()));
    connect(ui->actionOpen, SIGNAL(triggered()),this,SLOT(openDb()));
    connect(ui->actionClose, SIGNAL(triggered()),this,SLOT(closeDb()));
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

/**
 * This function allows for debugguing and notifying the user something wrong happened while executing an SQL operation.
 */
void MainWindow::sqlErrorMsg(QString query, QSqlError error){
    qDebug() << "<" << QDate::currentDate() << "> Error in SQL query execution: [" << query << "]\n Message is {"<< error.text() <<"}";
    QMessageBox::critical(this,tr("Error in SQL query!"),tr("There was an error while trying to execution a query. Please report a bug by including the debug message."));
}

/**
 * This function shall be called while executing multiple SQL queries in a row.
 * @return bool
 */
bool MainWindow::execMQueries(QString query)
{
    QSqlQuery q;
    bool rtn = q.exec(query);
    if(!rtn){
        sqlErrorMsg(query, q.lastError());
        return rtn;
    }
    return rtn;
}

/**
 * This function is called once a database file has been opened or is created.
 * It loads the central widget and the SQL model.
 */
void MainWindow::onDbLoad()
{
    QSqlQuery q(db);
    qDebug() << "here";
    if(!q.exec("SELECT data FROM information WHERE name = 'program_version'")){
        sqlErrorMsg("Program version query", q.lastError());
    }else{
        qDebug() << "error = [" << q.next() << "] (" << q.value(0) <<")";
        ui->label_Program_version->setText(ui->label_Program_version->text()+q.value(0).toString());
    }
    if(!q.exec("SELECT data FROM information WHERE name = 'latest_modification_date'")){
        sqlErrorMsg("Latest modification query", q.lastError());
    }else{
        qDebug() << "error = [" << q.next() << "]";
        ui->label_LatestModification->setText(ui->label_LatestModification->text()+q.value(0).toString());
    }

    ui->centralWidget->show();
    ui->actionClose->setEnabled(true);
    /* Defining the models */
}

void MainWindow::newDb()
{
    QString dbFile = QFileDialog::getSaveFileName(this,tr("Choose Invensile database filename"), QDir::currentPath(),tr("Invensile database (*.invdb)"));
    /* now we create the database file */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);
    if (!db.open()) {
        QMessageBox::critical(0, tr("Cannot open database"),tr("Unable to establish a database connection."), QMessageBox::Cancel);
        return;
    }
    /* We prepare the queries. */
    QStringList qList;
    qList.append("PRAGMA foreignkey = ON");
    qList.append("CREATE TABLE 'tags' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(20) NOT NULL )");
    qList.append("CREATE TABLE 'status' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'bgcolor' VARCHAR(6) NOT NULL DEFAULT ffffff, 'fgcolor' VARCHAR(6) NOT NULL DEFAULT 000000)");
    qList.append("CREATE TABLE 'addresses' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'country' VARCHAR(25), 'town' VARCHAR(50), 'postal_code' VARCHAR(10), 'street' TEXT check(typeof('street') = 'text') , 'ref' VARCHAR(5) NOT NULL )");
    qList.append("CREATE TABLE 'information' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' varchar(10) NOT NULL UNIQUE , 'data' TEXT NOT NULL check(typeof('data') = 'text') )");
    qList.append("CREATE TABLE 'locations' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(10) NOT NULL UNIQUE , 'name' VARCHAR(20) NOT NULL UNIQUE , 'creationdate' DATETIME NOT NULL , 'closingdate' DATETIME NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'description' TEXT NOT NULL , address_id INTEGER NOT NULL, FOREIGN KEY(address_id) REFERENCES addresses(id))");
    qList.append("CREATE TABLE 'items' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(20) NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'entrydate' DATETIME NOT NULL , 'recorddate' DATETIME NOT NULL , 'description' TEXT NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'qrcode' BLOB, 'location' INTEGER NOT NULL, FOREIGN KEY(location) REFERENCES locations(id) )");
    qList.append("INSERT INTO 'status' (name, fgcolor) VALUES ('valid','00aa00')");
    qList.append("INSERT INTO 'status' (name, fgcolor) VALUES ('Destroyed','777777')");
    qList.append("INSERT INTO 'status' (name, bgcolor, fgcolor) VALUES ('Lost','ff0000','000000')");
    /* to use color: QColor::name() , get the value and prepend with '#' */
    qList.append("INSERT INTO 'information' (name,data) VALUES ('program_version','0.1')");
    qList.append("INSERT INTO 'information' (name,data) VALUES ('latest_access_date',date('now'))");
    qList.append("INSERT INTO 'information' (name,data) VALUES ('latest_modification_date',date('now')); ");
    /* Execute the queries. */
    bool isStillValid = true;
    QStringListIterator qListIt(qList);
    while(isStillValid && qListIt.hasNext()){
        isStillValid = execMQueries(qListIt.next());
    }
    if (isStillValid){
        onDbLoad();
    }
}
void MainWindow::openDb()
{
    QString dbFile = QFileDialog::getOpenFileName(this,tr("Open Invensile database"), QDir::currentPath(),tr("Invensile databases (*.invdb)"));
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);
    if (!db.open()) {
        QMessageBox::critical(0, tr("Cannot open database"),tr("Unable to establish a database connection."), QMessageBox::Cancel);
        return;
    }
    QStringList qList;
    qList.append("PRAGMA foreignkey = ON");
    qList.append("UPDATE 'information' SET data=date(\"now\") WHERE name='latest_access_date'");
    /* Execute the queries. */
    bool isStillValid = true;
    QStringListIterator qListIt(qList);
    while(isStillValid && qListIt.hasNext()){
        isStillValid = execMQueries(qListIt.next());
    }
    if (isStillValid){
       onDbLoad();
    }
}
void MainWindow::closeDb()
{
    if(db.isOpen()){
        int rtn = QMessageBox::question(this,tr("Confirm closing file"),tr("Are you sure you wish to close this Invensile file?"),QMessageBox::Yes | QMessageBox::No);
        if(rtn == 0x00004000){
            db.close();
            ui->centralWidget->hide();
            ui->actionClose->setEnabled(false);
        }
    }
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
