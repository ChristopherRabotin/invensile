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
    /*QSqlQuery q;
    if(!q.exec("SELECT id,data FROM information WHERE name = 'program_version'")){
        sqlErrorMsg("Program version query", q.lastError());
    }else{
        ui->label_Program_version->setText(ui->label_Program_version->text()+q.value(1).toString());
    }
    if(!q.exec("SELECT id,data FROM information WHERE name = 'latest_modification_date'")){
        sqlErrorMsg("Latest modification query", q.lastError());
    }else{
        ui->label_LatestModification->setText(ui->label_LatestModification->text()+q.value(1).toString());
    }*/

    ui->centralWidget->show();
    ui->actionClose->setEnabled(true);
    /* Defining the models */
    /* Item Model and view */
    itemModel = new QSqlRelationalTableModel(this, db);
    itemModel->setTable("items");
    itemModel->setEditStrategy(QSqlTableModel::OnRowChange);
    itemModel->setRelation(8,QSqlRelation("locations","id","name"));
    itemModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    itemModel->setHeaderData(1, Qt::Horizontal, tr("Reference"));
    itemModel->setHeaderData(2, Qt::Horizontal, tr("Name"));
    itemModel->setHeaderData(3, Qt::Horizontal, tr("Entry date"));
    itemModel->setHeaderData(4, Qt::Horizontal, tr("Record date"));
    itemModel->setHeaderData(5, Qt::Horizontal, tr("Description"));
    itemModel->setHeaderData(6, Qt::Horizontal, tr("Access date"));
    itemModel->setHeaderData(7, Qt::Horizontal, tr("QR Code"));
    itemModel->setHeaderData(8, Qt::Horizontal, tr("Address"));
    itemModel->select();
    itemModel->setSort(3,Qt::AscendingOrder);
    ui->itemsView->setItemDelegate(new QSqlRelationalDelegate(ui->itemsView));
    ui->itemsView->setModel(itemModel);
    ui->itemsView->setSortingEnabled(true);
    ui->itemsView->setColumnHidden(0,true); // hide the ID column
    /* Location Model and view */
    locationModel = new QSqlRelationalTableModel(this, db);
    locationModel->setTable("locations");
    locationModel->setEditStrategy(QSqlTableModel::OnRowChange);
    locationModel->setRelation(7,QSqlRelation("addresses","id","name"));
    locationModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    locationModel->setHeaderData(1, Qt::Horizontal, tr("Reference"));
    locationModel->setHeaderData(2, Qt::Horizontal, tr("Name"));
    locationModel->setHeaderData(3, Qt::Horizontal, tr("Creation date"));
    locationModel->setHeaderData(4, Qt::Horizontal, tr("Closing date"));
    locationModel->setHeaderData(5, Qt::Horizontal, tr("Access date"));
    locationModel->setHeaderData(6, Qt::Horizontal, tr("Description"));
    locationModel->setHeaderData(7, Qt::Horizontal, tr("Address"));
    locationModel->select();
    locationModel->setSort(3,Qt::AscendingOrder);
    ui->locationsView->setItemDelegate(new QSqlRelationalDelegate(ui->locationsView));
    ui->locationsView->setModel(locationModel);
    ui->locationsView->setSortingEnabled(true);
    ui->locationsView->setColumnHidden(0,true); // hide the ID column
    /* Address Model and view */
    addressModel = new QSqlRelationalTableModel(this, db);
    addressModel->setTable("addresses");
    addressModel->setEditStrategy(QSqlTableModel::OnRowChange);
    addressModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    addressModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    addressModel->setHeaderData(2, Qt::Horizontal, tr("Country"));
    addressModel->setHeaderData(3, Qt::Horizontal, tr("Town"));
    addressModel->setHeaderData(4, Qt::Horizontal, tr("Postal code"));
    addressModel->setHeaderData(5, Qt::Horizontal, tr("Street"));
    addressModel->setHeaderData(6, Qt::Horizontal, tr("Reference"));
    addressModel->select();
    addressModel->setSort(1,Qt::AscendingOrder);
    ui->addressesView->setModel(addressModel);
    ui->addressesView->setSortingEnabled(true);
    ui->addressesView->setColumnHidden(0,true); // hide the ID column
    /* Tag Model and view */
    tagModel = new QSqlRelationalTableModel(this, db);
    tagModel->setTable("tags");
    tagModel->setEditStrategy(QSqlTableModel::OnRowChange);
    tagModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    tagModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    tagModel->select();
    tagModel->setSort(1,Qt::AscendingOrder);
    ui->tagsView->setModel(tagModel);
    ui->tagsView->setSortingEnabled(true);
    ui->tagsView->setColumnHidden(0,true); // hide the ID column
    /* Status Model and view */
    statusModel = new QSqlRelationalTableModel(this, db);
    statusModel->setTable("statuses");
    statusModel->setEditStrategy(QSqlTableModel::OnRowChange);
    statusModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    statusModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    statusModel->setHeaderData(2, Qt::Horizontal, tr("Background color"));
    statusModel->setHeaderData(3, Qt::Horizontal, tr("Foreground color"));
    statusModel->select();
    statusModel->setSort(1,Qt::AscendingOrder);
    ui->statusesView->setModel(statusModel);
    ui->statusesView->setSortingEnabled(true);
    ui->statusesView->setColumnHidden(0,true); // hide the ID column
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
    qList.append("CREATE TABLE 'statuses' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'bgcolor' VARCHAR(6) NOT NULL DEFAULT ffffff, 'fgcolor' VARCHAR(6) NOT NULL DEFAULT 000000)");
    qList.append("CREATE TABLE 'addresses' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'country' VARCHAR(25), 'town' VARCHAR(50), 'postal_code' VARCHAR(10), 'street' TEXT check(typeof('street') = 'text') , 'ref' VARCHAR(5) NOT NULL )");
    qList.append("CREATE TABLE 'information' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' varchar(10) NOT NULL UNIQUE , 'data' TEXT NOT NULL check(typeof('data') = 'text') )");
    qList.append("CREATE TABLE 'locations' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(10) NOT NULL UNIQUE , 'name' VARCHAR(20) NOT NULL UNIQUE , 'creationdate' DATETIME NOT NULL , 'closingdate' DATETIME NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'description' TEXT NOT NULL , address_id INTEGER NOT NULL, FOREIGN KEY(address_id) REFERENCES addresses(id))");
    qList.append("CREATE TABLE 'items' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(20) NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'entrydate' DATETIME NOT NULL , 'recorddate' DATETIME NOT NULL , 'description' TEXT NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'qrcode' BLOB, 'location_id' INTEGER NOT NULL, FOREIGN KEY(location_id) REFERENCES locations(id) )");
    qList.append("CREATE TABLE 'tag_item_links' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'tag_id' INTEGER NOT NULL, 'item_id' INTEGER NOT NULL, FOREIGN KEY(item_id) REFERENCES items(id))");
    qList.append("CREATE TABLE 'tag_location_links' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'tag_id' INTEGER NOT NULL, 'location_id' INTEGER NOT NULL, FOREIGN KEY(location_id) REFERENCES locations(id))");
    qList.append("INSERT INTO 'statuses' (name, fgcolor) VALUES ('Valid','00aa00')");
    qList.append("INSERT INTO 'statuses' (name, fgcolor) VALUES ('Destroyed','777777')");
    qList.append("INSERT INTO 'statuses' (name, bgcolor, fgcolor) VALUES ('Lost','ff0000','000000')");
    /* to use color: QColor::name() , get the value and prepend with '#' */
    qList.append("INSERT INTO 'information' (name,data) VALUES ('database_version','0.1')");
    qList.append("INSERT INTO 'information' (name,data) VALUES ('latest_access_date',date('now'))");
    qList.append("INSERT INTO 'information' (name,data) VALUES ('latest_modification_date',date('now'));");
    qList.append("INSERT INTO 'information' (name,data) VALUES ('creation_date',date('now'));");
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
    QString name; QSqlRelationalTableModel *model; QString filter, filterQuery = ""; QStringList query;
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

    /* The following line prevent SQL injections */
    filter.replace("'","\'");
    QStringListIterator qIt(query);
    while(qIt.hasNext()){
        filterQuery.append(name+"."+qIt.next()+ " LIKE '%"+filter+"%' OR ");
    }
    filterQuery.chop(3); // remove the trailing 'OR '
//    filterQuery = "ref LIKE %";
#ifdef DEBUG
    qDebug() << "Filtering"<< name << "with [" << filterQuery << "]";
#endif
    model->setFilter(filterQuery);;
#ifdef DEBUG
    qDebug() << "Error [" << model->query().lastError().text() << "]";
#endif
}
