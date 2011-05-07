#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->hide();
    ui->actionClose->setDisabled(true);
    ui->actionRefresh_views->setDisabled(true);
    // connect(ui->addButton, SIGNAL(clicked()),this,SLOT(addContact()));
    connect(ui->actionNew, SIGNAL(triggered()),this,SLOT(newDb()));
    connect(ui->actionOpen, SIGNAL(triggered()),this,SLOT(openDb()));
    connect(ui->actionClose, SIGNAL(triggered()),this,SLOT(closeDb()));
    connect(ui->actionRefresh_views, SIGNAL(triggered()),this,SLOT(updateViews()));
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
    connect(ui->newAddressButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newItemButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newLocationButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newStatusButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(ui->newTagButton,SIGNAL(clicked()),createMapper,SLOT (map()));
    connect(createMapper,SIGNAL(mapped(int)),this,SLOT(create(int)));
    //connect(ui->newItemButton,SIGNAL(clicked()),this,SLOT(create(int)));
}

MainWindow* MainWindow::instance()
{
   static MainWindow* _setupObj= new MainWindow();
   return _setupObj;
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

QSqlRelationalTableModel *MainWindow::modelViewSetup(QSqlRelationalTableModel *model, QTableView *view, QString table, QStringList headers, QList<int> relationCol, QList<QStringList> relationInfo, int sortedCol)
{
    model = new QSqlRelationalTableModel(this, backbone::instance()->db);
    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // it's the same edit strategy for all views
    QListIterator<int> relationColIt(relationCol);
    QListIterator<QStringList> relationInfoIt(relationInfo);
    QStringList tempRel;
    while(relationColIt.hasNext() && relationInfoIt.hasNext()){
        tempRel = relationInfoIt.next();
        model->setRelation(relationColIt.next(),QSqlRelation(tempRel.at(0),tempRel.at(1),tempRel.at(2)));
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

QSqlRelationalTableModel *MainWindow::modelViewSetupSimple(QSqlRelationalTableModel *model, QTableView *view, QString table, QStringList headers, int relationCol, QStringList relationInfo, int sortedCol)
{
    model = new QSqlRelationalTableModel(this, backbone::instance()->db);
    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // it's the same edit strategy for all views
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
    backbone::instance()->query.exec("SELECT id,data FROM information WHERE name = 'program_version'");
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
    ui->actionRefresh_views->setEnabled(true);
    /* Defining the models */

    /* Item Model and view */
    QStringList itemHeaders, itemsRelationInfo1,itemsRelationInfo2;
    QList<QStringList> itemsRelationInfoL;
    QList<int> itemRelationCol;
    itemHeaders << tr("ID") << tr("Reference") << tr("Name") << tr("Entry date") << tr("Record date") << tr("Description") << tr("Access date") << tr("QR Code") << tr("Location") << tr("Status");
    itemsRelationInfo1 << "locations" << "id" << "name";
    itemsRelationInfo2 << "statuses" << "id" << "name";
    itemRelationCol << 8 << 9;
    itemsRelationInfoL << itemsRelationInfo1 << itemsRelationInfo2;
    itemModel = modelViewSetup(itemModel,ui->itemsView,"items",itemHeaders,itemRelationCol,itemsRelationInfoL,3);

    /* Location Model and view */
    QStringList locationHeaders, locationsRelationInfo1,locationsRelationInfo2, locationsRelationInfo3;
    QList<QStringList> locationsRelationInfoL;
    QList<int> locationRelationCol;
    locationRelationCol << 7 << 8 << 9;
    locationsRelationInfo1 << "addresses" << "id" << "name";
    locationsRelationInfo2 << "locations" << "id" << "name";
    locationsRelationInfo3 << "statuses" << "id" << "name";
    locationsRelationInfoL << locationsRelationInfo1 << locationsRelationInfo2 << locationsRelationInfo3;
    locationHeaders << tr("ID") << tr("Reference") << tr("Name") << tr("Creation date") << tr("Closing date") << tr("Access date") << tr("Description") << tr("Address") << tr("Location") << tr("Status") ;
    locationModel = modelViewSetup(locationModel,ui->locationsView,"locations",locationHeaders,locationRelationCol,locationsRelationInfoL,3);

    /* Address Model and view */
    QStringList addressHeaders, addressesRelationInfo;
    addressHeaders << tr("ID") << tr("Name") << tr("Country") << tr("Town") << tr("Postal code") << tr("Street") << tr("Reference") << tr("Status");
    addressesRelationInfo << "statuses" << "id" << "name";
    addressModel = modelViewSetupSimple(addressModel,ui->addressesView,"addresses",addressHeaders,7,addressesRelationInfo,1);

    /* Tag Model and view */
    QStringList tagHeaders, tagsRelationInfo;
    tagHeaders << tr("ID") << tr("Name");
    tagsRelationInfo << ""; // we don't put anything here because there is not relation.
    tagModel = modelViewSetupSimple(tagModel,ui->tagsView,"tags",addressHeaders,-1,addressesRelationInfo,1);
    /* Status Model and view */
    QStringList statusHeaders, statusesRelationInfo;
    statusHeaders << tr("ID") << tr("Name") << tr("Background color") << tr("Foreground color");
    statusesRelationInfo << ""; // we don't put anything here because there is not relation.
    statusModel = modelViewSetupSimple(statusModel,ui->statusesView,"statuses",statusHeaders,-1,statusesRelationInfo,1);
    /* Search Model and view */
    QStringList searchHeaders, searchRelationInfo;
    searchHeaders << tr("Reference") << tr("Name") << tr("Type");
    searchRelationInfo << ""; // we don't put anything here because there is not relation.
    searchModel = modelViewSetupSimple(searchModel,ui->searchView,"items,locations,addresses",searchHeaders,-1,searchRelationInfo,1);
}

void MainWindow::newDb()
{
    QString dbFile = QFileDialog::getSaveFileName(this,tr("Choose Invensile database filename"), QDir::currentPath(),tr("Invensile database (*.invdb)"));
    if (backbone::instance()->newDb(dbFile)){
        onDbLoad();
    }else{
        QMessageBox::critical(0, tr("Cannot open database"),tr("Unable to establish a database connection."), QMessageBox::Cancel);
        return;
    }
}
void MainWindow::openDb()
{
    QString dbFile = QFileDialog::getOpenFileName(this,tr("Open Invensile database"), QDir::currentPath(),tr("Invensile databases (*.invdb)"));
    if (backbone::instance()->openDb(dbFile)){
        onDbLoad();
    }else{
        QMessageBox::critical(0, tr("Cannot open database"),tr("Unable to establish a database connection."), QMessageBox::Cancel);
        return;
    }
}
void MainWindow::closeDb()
{
    if(backbone::instance()->db.isOpen()){
        int rtn = QMessageBox::question(this,tr("Confirm closing file"),tr("Are you sure you wish to close this Invensile file?"),QMessageBox::Yes | QMessageBox::No);
        if(rtn == 0x00004000){
            backbone::instance()->closeDb();
            ui->centralWidget->hide();
            ui->actionClose->setEnabled(false);
        }
    }
}

void MainWindow::modify()
{

}
void MainWindow::create(int createWhat)
{
    switch(createWhat){
    case 0:
        createAddressDialog = new CreateAddressDialog(this,addressModel);
        createAddressDialog->show();
        break;
    case 1:
        createDialog = new CreateDialog(this,itemModel);
        createDialog->show();
        break;
    case 2:
        createLocationDialog = new CreateLocationDialog(this,locationModel);
        createLocationDialog->show();
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
    case 5:
        name = "addresses,locations,items"; model = searchModel; filter = ui->filterSearchEdit->text();
        query << "name" << "ref";
        break;
    }

    /* The following line prevent SQL injections */
    filter.replace("'","\'");
    QStringListIterator qIt(query);
    while(qIt.hasNext()){
        filterQuery.append(name+"."+qIt.next()+ " LIKE '%"+filter+"%' OR ");
    }
    filterQuery.chop(3); // remove the trailing 'OR '
#ifdef DEBUG
    qDebug() << "Filtering"<< name << "with [" << filterQuery << "]";
#endif
    model->setFilter(filterQuery);;
#ifdef DEBUG
    qDebug() << "Error [" << model->query().lastError().text() << "]";
#endif
}

void MainWindow::updateViews(){
#ifdef DEBUG
    qDebug() << "Updating views.";
#endif
    itemModel->select();
    addressModel->select();
    tagModel->select();
    statusModel->select();
    locationModel->select();
}
