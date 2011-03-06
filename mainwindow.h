#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QDate>
#include <QSqlError>
#include <QDebug>
#include <QStringList>
#include <QSqlTableModel>
#include <QSignalMapper>

#define VERSION 0.1
#define DEBUG

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    // variables
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *latestQuery;
    QSqlTableModel *tagModel, *statusModel, *addressModel, *locationModel, *itemModel;
    // functions and methods
    bool execMQueries(QString query);
    void onDbLoad();
    void sqlErrorMsg(QString query, QSqlError error);

private slots:
    /* File slots */
    void newDb();
    void openDb();
    void closeDb();
    void exportInventory();
    /* Edit slots */
    void modify(); // maybe add a QString or QObject to know what to modify
    /* Create slots */
    void create(); // idem as modify to avoid code duplication
    /* Tools slots */
    void preferences();
    void about();
    /* Other slots */
    void filterView(int);
};

#endif // MAINWINDOW_H
