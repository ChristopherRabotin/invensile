#ifndef SQLRELATIONALTABLEMODEL_H
#define SQLRELATIONALTABLEMODEL_H
#include <QSqlRelationalTableModel>
#include <QDebug>
class SqlRelationalTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    SqlRelationalTableModel(QObject *parent = 0,
                            QSqlDatabase db = QSqlDatabase())
        : QSqlRelationalTableModel(parent,db)
    {}

    virtual bool select()
    {
        const bool ret = QSqlRelationalTableModel::select();
        emit selected(); // without this it doesn't work
        qDebug() << "emitted select for " << tableName();
        return ret;
    }
signals:
    void selected();
};

#endif // SQLRELATIONALTABLEMODEL
