#ifndef BACKBONE_H
#define BACKBONE_H

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
    bool newDb(QString dbFile);
    bool openDb(QString dbFile);
    void closeDb();
    void exportInventory();
    static backbone* instance();
private:
    bool execMQueries(QString query);
};

#endif // BACKBONE_H
