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
    
    /* filter mapping */
    connect(ui->filterAddressEdit,SIGNAL(textChanged(QString)),filterMapper,SLOT (map()));
    connect(ui->filterItemsEdit,SIGNAL(textChanged(QString)),filterMapper,SLOT (map()));
    connect(ui->filterLocationsEdit,SIGNAL(textChanged(QString)),filterMapper,SLOT (map()));
    connect(ui->filterStatusesEdit,SIGNAL(textChanged(QString)),filterMapper,SLOT (map()));
    connect(ui->filterTagsEdit,SIGNAL(textChanged(QString)),filterMapper,SLOT (map()));
    connect(filterMapper,SIGNAL(mapped(int)),this,SLOT(filterView(int)));

    /* create signal mapper */
    QSignalMapper *createMapper = new QSignalMapper(this);
    createMapper->setMapping(ui->newAddressButton,0);
    createMapper->setMapping(ui->newItemButton,1);
    createMapper->setMapping(ui->newLocationButton,2);
    createMapper->setMapping(ui->newStatusButton,3);
    createMapper->setMapping(ui->newTagButton,4);
    /* Create mapping */
    /* filter mapping */
    //connect(ui->newAddressButton,SIGNAL(clicked())),createMapper,SLOT (map());
    connect(ui->newItemButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newLocationButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newStatusButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newTagButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(createMapper,SIGNAL(mapped(int)),this,SLOT(create(int)));
    //connect(ui->newItemButton,SIGNAL(clicked()),this,SLOT(create(int)));

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

QSqlRelationalTableModel *MainWindow::modelViewSetup(QSqlRelationalTableModel *model, QTableView *view, QString table, QStringList headers, int relationCol, QStringList relationInfo, int sortedCol)
{
    model = new QSqlRelationalTableModel(this, db);
    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnRowChange); // it's the same edit strategy for all views
    if(relationInfo.length() == 3){
        model->setRelation(relationCol,QSqlRelation(relationInfo.at(0),relationInfo.at(1),relationInfo.at(2)));
    }
    model->setSort(sortedCol, Qt::AscendingOrder); // all columns are to be sorted in an Ascended fashion
    for (int i = 0; i < headers.size(); i++){ // populate the headers
        model->setHeaderData(i, Qt::Horizontal, headers.at(i));
    }
    model->select(); // all tables are in select mode

    view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->setModel(model);
    view->setSortingEnabled(true);
    view->setColumnHidden(0,true); // hide the ID column for all tables
    return model;
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
    QStringList itemHeaders, itemsRelationInfo;
    itemHeaders << tr("ID") << tr("Reference") << tr("Name") << tr("Entry date") << tr("Record date") << tr("Description") << tr("Access date") << tr("QR Code") << tr("Location");
    itemsRelationInfo << "locations" << "id" << "name";
    itemModel = modelViewSetup(itemModel,ui->itemsView,"items",itemHeaders,8,itemsRelationInfo,3);
    /* Location Model and view */
    QStringList locationHeaders, locationsRelationInfo;
    locationHeaders << tr("ID") << tr("Reference") << tr("Name") << tr("Creation date") << tr("Closing date") << tr("Access date") << tr("Description") << tr("Address");
    locationsRelationInfo << "addresses" << "id" << "name";
    locationModel = modelViewSetup(locationModel,ui->locationsView,"locations",locationHeaders,7,locationsRelationInfo,3);
    /* Address Model and view */
    QStringList addressHeaders, addressesRelationInfo;
    addressHeaders << tr("ID") << tr("Name") << tr("Country") << tr("Town") << tr("Postal code") << tr("Street") << tr("Reference");
    addressesRelationInfo << ""; // we don't put anything here because there is not relation.
    addressModel = modelViewSetup(addressModel,ui->addressesView,"addresses",addressHeaders,-1,addressesRelationInfo,1);
    /* Tag Model and view */
    QStringList tagHeaders, tagsRelationInfo;
    tagHeaders << tr("ID") << tr("Name");
    tagsRelationInfo << ""; // we don't put anything here because there is not relation.
    tagModel = modelViewSetup(tagModel,ui->tagsView,"tags",addressHeaders,-1,addressesRelationInfo,1);
    /* Status Model and view */
    QStringList statusHeaders, statusesRelationInfo;
    statusHeaders << tr("ID") << tr("Name") << tr("Background color") << tr("Foreground color");
    statusesRelationInfo << ""; // we don't put anything here because there is not relation.
    statusModel = modelViewSetup(statusModel,ui->statusesView,"statuses",statusHeaders,-1,statusesRelationInfo,1);
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
void MainWindow::create(int createWhat)
{
    switch(createWhat){
    case 1:
        //q.exec("INSERT INTO 'items' (ref,name,entrydate,recorddate,location_id) VALUES ('')")
        createDialog = new CreateDialog();
        createDialog->show();
        break;
    }
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
        query << "ref" << "name" << "country" << "town" << "postal_code" << "street";
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
