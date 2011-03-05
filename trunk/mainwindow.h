#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>

#define VERSION 0.1

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
    Ui::MainWindow *ui;

public slots:
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
};

#endif // MAINWINDOW_H
