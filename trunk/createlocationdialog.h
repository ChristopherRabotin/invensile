#ifndef CREATELOCATIONDIALOG_H
#define CREATELOCATIONDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSqlRelationalTableModel>
#include <QDateTime>
#include <QSqlRelation>
#include "backbone.h"

namespace Ui {
    class CreateLocationDialog;
}

class CreateLocationDialog : public QDialog {
    Q_OBJECT
public:
    CreateLocationDialog(QWidget *parent = 0);
    ~CreateLocationDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateLocationDialog *ui;

private slots:
    void accept();
    void closeLocation();
};

#endif // CREATELOCATIONDIALOG_H
