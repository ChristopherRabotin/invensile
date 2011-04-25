#ifndef BACKBONE_H
#define BACKBONE_H
#define DEBUG
#include <QObject>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QStringListIterator>
#include <QDate>
#include <QDebug>
#include <QSqlError>

class backbone : public QObject
{
     Q_OBJECT
public:
    backbone();
    QSqlDatabase db;
    QSqlQuery query;
    bool newDb(QString dbFile);
    bool openDb(QString dbFile);
    void closeDb();
    void exportInventory();
    static backbone* instance();
    bool execMQueries(QString query);
//private:
};

#endif // BACKBONE_H
