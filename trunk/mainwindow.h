#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QDebug>
#include <QStringList>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QSqlRelation>
#include <QSignalMapper>
#include <QSqlRelationalDelegate>
#include <QTableView>
/* Project includes */
#include "createdialog.h"
#include "createaddressdialog.h"
#include "createlocationdialog.h"
#include "backbone.h"

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
    static MainWindow* instance();

public slots:
    void updateViews();

protected:
    void changeEvent(QEvent *e);

private:
    // variables
    Ui::MainWindow *ui;
    QSqlQuery *latestQuery;
    QSqlRelationalTableModel *tagModel, *statusModel, *addressModel, *locationModel, *itemModel, *searchModel;
    // functions and methods
    void onDbLoad();
    QSqlRelationalTableModel* modelViewSetup(QSqlRelationalTableModel *model, QTableView *view, QString table, QStringList headers, QList<int> relationCol, QList<QStringList> relationInfo, int sortedCol);
    QSqlRelationalTableModel* modelViewSetupSimple(QSqlRelationalTableModel *model, QTableView *view, QString table, QStringList headers, int relationCol, QStringList relationInfo, int sortedCol);
    /* Other dialogs */
    CreateDialog *createDialog;
    CreateAddressDialog *createAddressDialog;
    CreateLocationDialog *createLocationDialog;

private slots:
    /* File slots */
    void newDb();
    void openDb();
    void closeDb();
    /* Edit slots */
    void modify(); // maybe add a QString or QObject to know what to modify
    /* Create slots */
    void create(int); // int used for mapping
    /* Tools slots */
    void preferences();
    void about();
    /* Other slots */
    void filterView(int);
};

#endif // MAINWINDOW_H
