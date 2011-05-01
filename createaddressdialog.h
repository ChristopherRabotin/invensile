#ifndef CREATEADDRESSDIALOG_H
#define CREATEADDRESSDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include "backbone.h"

namespace Ui {
    class CreateAddressDialog;
}

class CreateAddressDialog : public QDialog {
    Q_OBJECT
public:
    CreateAddressDialog(QWidget *parent = 0);
    ~CreateAddressDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateAddressDialog *ui;
    QDataWidgetMapper *mapper;
    QSqlRelationalTableModel *statusModel;
    QSqlTableModel *relModel;

private slots:
    void accept();
};

#endif // CREATEADDRESSDIALOG_H
