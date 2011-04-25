#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include "backbone.h"
#define DEBUG
namespace Ui {
    class CreateDialog;
}

class CreateDialog : public QDialog {
    Q_OBJECT
public:
    CreateDialog(QWidget *parent = 0);
    ~CreateDialog();
    QSqlQuery query;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateDialog *ui;

private slots:
    void accept();
};

#endif // CREATEDIALOG_H
