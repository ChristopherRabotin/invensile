#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QDataWidgetMapper>
#include "backbone.h"
#define DEBUG
namespace Ui {
    class CreateDialog;
}

class CreateDialog : public QDialog {
    Q_OBJECT
public:
    CreateDialog(QWidget *parent = 0, QSqlRelationalTableModel *modelP = 0, bool create = true, int index=-1);
    ~CreateDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateDialog *ui;
    QDataWidgetMapper *mapper;
    QSqlTableModel *statusRelModel, *locationRelModel;
    QSqlRelationalTableModel *model;

private slots:
    void accept();
    void overrideRef();
    void dateItem();
};

#endif // CREATEDIALOG_H
