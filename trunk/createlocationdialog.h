#ifndef CREATELOCATIONDIALOG_H
#define CREATELOCATIONDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QDataWidgetMapper>
#include <QDateTime>
#include <QSqlRelation>
#include "backbone.h"

namespace Ui {
    class CreateLocationDialog;
}

class CreateLocationDialog : public QDialog {
    Q_OBJECT
public:
    CreateLocationDialog(QWidget *parent = 0, QSqlRelationalTableModel *modelP = 0, bool create = true, int index=-1);
    ~CreateLocationDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateLocationDialog *ui;
    QDataWidgetMapper *mapper;
    QSqlTableModel *statusRelModel, *addressRelModel, *locationRelModel;
    QSqlRelationalTableModel *model;

private slots:
    void accept();
    void closeLocation();
};

#endif // CREATELOCATIONDIALOG_H
