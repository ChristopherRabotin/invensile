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
    /* filter signal mapper */
    QSignalMapper *filterMapper = new QSignalMapper(this);
    filterMapper->setMapping(ui->filterAddressEdit,0);
    filterMapper->setMapping(ui->filterItemsEdit,1);
    filterMapper->setMapping(ui->filterLocationsEdit,2);
    filterMapper->setMapping(ui->filterStatusesEdit,3);
    filterMapper->setMapping(ui->filterTagsEdit,4);
    
    connect(ui->filterAddressEdit,SIGNAL(textChanged(QString)),filterMapper,SLOT (map()));
    connect(ui->filterItemsEdit,SIGNAL(textEdited(QString)),filterMapper,SLOT (map()));
    connect(ui->filterLocationsEdit,SIGNAL(textEdited(QString)),filterMapper,SLOT (map()));
    connect(ui->filterStatusesEdit,SIGNAL(textEdited(QString)),filterMapper,SLOT (map()));
    connect(ui->filterTagsEdit,SIGNAL(textEdited(QString)),filterMapper,SLOT (map()));
    connect(filterMapper,SIGNAL(mapped(int)),this,SLOT(filterView(int)));
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
    QSqlQuery q;
    if(!q.exec("SELECT data FROM information WHERE name = 'program_version'")){
        sqlErrorMsg("Program version query", q.lastError());
    }else{
        ui->label_Program_version->setText(ui->label_Program_version->text()+q.value(0).toString());
    }
    if(!q.exec("SELECT data FROM information WHERE name = 'latest_modification_date'")){
        sqlErrorMsg("Latest modification query", q.lastError());
    }else{
        ui->label_LatestModification->setText(ui->label_LatestModification->text()+q.value(0).toString());
    }

    ui->centralWidget->show();
    ui->actionClose->setEnabled(true);
    /* Defining the models */
    /* Item Model and view */
    itemModel = new QSqlRelationalTableModel(this, db);
    itemModel->setTable("items");
    itemModel->setEditStrategy(QSqlTableModel::OnRowChange);
    itemModel->select();
    itemModel->setRelation(8,QSqlRelation("locations","id","name"));
    itemModel->removeColumn(0);
    itemModel->removeColumns(3,4); // don't show the ID, record date, description, accessdate and qrcode
    itemModel->setHeaderData(0, Qt::Horizontal, tr("Reference"));
    itemModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    itemModel->setHeaderData(2, Qt::Horizontal, tr("Entry date"));
    itemModel->setHeaderData(3, Qt::Horizontal, tr("Location name"));
    ui->itemsView->setItemDelegate(new QSqlRelationalDelegate(ui->itemsView));
    ui->itemsView->setModel(itemModel);
    /* Location Model and view */
    locationModel = new QSqlRelationalTableModel(this, db);
    locationModel->setTable("locations");
    locationModel->setEditStrategy(QSqlTableModel::OnRowChange);
    locationModel->select();
    itemModel->setRelation(7,QSqlRelation("addresses","id","name"));
    locationModel->removeColumn(0);
    locationModel->removeColumns(4,2); // don't show the description and accessdate
    locationModel->setHeaderData(0, Qt::Horizontal, tr("Reference"));
    locationModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    locationModel->setHeaderData(2, Qt::Horizontal, tr("Creation date"));
    locationModel->setHeaderData(3, Qt::Horizontal, tr("Closing date"));
    locationModel->setHeaderData(4, Qt::Horizontal, tr("Address name"));
    ui->locationsView->setItemDelegate(new QSqlRelationalDelegate(ui->locationsView));
    ui->locationsView->setModel(locationModel);
    /* Address Model and view */
    addressModel = new QSqlRelationalTableModel(this, db);
    addressModel->setTable("addresses");
    addressModel->setEditStrategy(QSqlTableModel::OnRowChange);
    addressModel->select();
    addressModel->removeColumn(0);
    addressModel->removeColumns(1,4); // don't show anything but the name and reference
    addressModel->setHeaderData(1, Qt::Horizontal, tr("Reference"));
    addressModel->setHeaderData(0, Qt::Horizontal, tr("Name"));
    ui->addressesView->setModel(addressModel);
    /* Tag Model and view */
    tagModel = new QSqlRelationalTableModel(this, db);
    tagModel->setTable("tags");
    tagModel->setEditStrategy(QSqlTableModel::OnRowChange);
    tagModel->select();
    tagModel->removeColumn(0); // don't show the ID
    tagModel->setHeaderData(0, Qt::Horizontal, tr("Name"));
    ui->tagsView->setModel(tagModel);
    /* Status Model and view */
    statusModel = new QSqlRelationalTableModel(this, db);
    statusModel->setTable("statuses");
    statusModel->setEditStrategy(QSqlTableModel::OnRowChange);
    statusModel->select();
    statusModel->removeColumn(0); // don't show the ID
    statusModel->setHeaderData(0, Qt::Horizontal, tr("Name"));
    // TODO FIND WHY THE FOLLOWING LINE CAN'T COMPILE:
    // virtual function setModel private within this context.
    //ui->statusesView->setModel(statusModel);
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
    qList.append("CREATE TABLE 'items' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(20) NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'entrydate' DATETIME NOT NULL , 'recorddate' DATETIME NOT NULL , 'description' TEXT NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'qrcode' BLOB, 'location_id' INTEGER NOT NULL, FOREIGN KEY(location_id) REFERENCES locations(id) )");
    qList.append("CREATE TABLE 'tag_item_links' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'tag_id' INTEGER NOT NULL, 'item_id' INTEGER NOT NULL, FOREIGN KEY(item_id) REFERENCES items(id))");
    qList.append("CREATE TABLE 'tag_location_links' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'tag_id' INTEGER NOT NULL, 'location_id' INTEGER NOT NULL, FOREIGN KEY(location_id) REFERENCES locations(id))");
    qList.append("INSERT INTO 'status' (name, fgcolor) VALUES ('Valid','00aa00')");
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

void MainWindow::filterView(int filterNumber){
    QString name; QSqlTableModel *model; QString filter, filterQuery = ""; QStringList query;
    switch(filterNumber){
    case 0:
        name = "addresses"; model = addressModel; filter = ui->filterAddressEdit->text();
        query << "ref" << "name" << "country" << "town" << "description";
        break;
    case 1:
        name = "items"; model = itemModel; filter = ui->filterItemsEdit->text();
        query << "ref" << "name" << "description" << "location_id" << "entrydate" << "recorddate";
        break;
    case 2:
        name = "locations"; model = locationModel; filter = ui->filterLocationsEdit->text();
        query << "ref" << "name" << "description" << "address_id" << "creationdate" << "closingdate";
        break;
    case 3:
        name = "statuses"; model = statusModel; filter = ui->filterStatusesEdit->text();
        query << "name";
        break;
    case 4:
        name = "tags"; model = tagModel; filter = ui->filterTagsEdit->text();
        query << "name";
        break;
    }

    QStringListIterator qIt(query);
    while(qIt.hasNext()){
        filterQuery.append(qIt.next()+ " LIKE '%"+filter+"%' OR ");
    }
    filterQuery.chop(3); // remove the trailing 'OR '
#ifdef DEBUG
    qDebug() << "Filtering"<< name << "with [" << filterQuery << "]";
#endif
    model->setFilter(filterQuery);

}
