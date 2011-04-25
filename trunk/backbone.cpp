#include "backbone.h"

backbone::backbone()
{
}
bool backbone::newDb(QString dbFile)
{
    /* now we create the database file */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);
    if (!db.open()) {
        return false;
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
    return isStillValid;
}
bool backbone::openDb(QString dbFile)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFile);
    if (!db.open()) {
        return false;
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
    return isStillValid;
}

void backbone::closeDb()
{
    db.close();
}

/**
 * This function must be called while executing multiple SQL queries in a row.
 * @return bool
 */
bool backbone::execMQueries(QString query)
{
    QSqlQuery q(db);
    bool rtn = q.exec(query);
    if(!rtn){
        qDebug() << "<" << QDate::currentDate() << "> Error in SQL query execution: [" << query << "]\n Message is {"<< q.lastError().text() <<"}";
        return rtn;
    }
    return rtn;
}

backbone* backbone::instance()
{
   static backbone* _setupObj= new backbone();
   return _setupObj;
}

