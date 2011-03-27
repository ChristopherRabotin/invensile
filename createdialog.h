#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
namespace Ui {
    class CreateDialog;
}

class CreateDialog : public QDialog {
    Q_OBJECT
public:
    CreateDialog(QWidget *parent = 0);
    ~CreateDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CreateDialog *ui;

private slots:
    void submit();
};

#endif // CREATEDIALOG_H
