/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionRecent_Files;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionModify;
    QAction *actionLocation;
    QAction *actionItem;
    QAction *actionAddress;
    QAction *actionPreferences;
    QAction *actionAbout;
    QAction *actionStatus;
    QAction *actionTag;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabWidget;
    QWidget *informationTab;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *followUpBox;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QTableView *followUpView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *dbInfoBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *searchTab;
    QWidget *tagsTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *filterTagsEdit;
    QTableWidget *tagView;
    QHBoxLayout *horizontalLayout;
    QPushButton *newTagButton;
    QPushButton *modifyTagButton;
    QPushButton *deleteTagButton;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLineEdit *filterStatusesEdit;
    QTableWidget *statusesView;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *newStatusButton;
    QPushButton *modifyStatusButton;
    QPushButton *deleteStatusButton;
    QWidget *addressesTab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *filterAddressEdit;
    QTableWidget *tableWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *newAddressButton;
    QPushButton *viewAddressItemsButton;
    QPushButton *modifyAddressButton;
    QPushButton *deleteAddressButton;
    QWidget *locationsTab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QLineEdit *filterLocationsEdit;
    QTableView *locationsView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *newLocationButton;
    QPushButton *viewItemsLocationButton;
    QPushButton *modifyLocationButton;
    QPushButton *deleteLocationButton;
    QWidget *itemsTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QLineEdit *filterItemsEdit;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *newItemButton;
    QPushButton *modifyItemButton;
    QPushButton *deleteItemButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCreate;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionRecent_Files = new QAction(MainWindow);
        actionRecent_Files->setObjectName(QString::fromUtf8("actionRecent_Files"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionModify = new QAction(MainWindow);
        actionModify->setObjectName(QString::fromUtf8("actionModify"));
        actionLocation = new QAction(MainWindow);
        actionLocation->setObjectName(QString::fromUtf8("actionLocation"));
        actionItem = new QAction(MainWindow);
        actionItem->setObjectName(QString::fromUtf8("actionItem"));
        actionAddress = new QAction(MainWindow);
        actionAddress->setObjectName(QString::fromUtf8("actionAddress"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName(QString::fromUtf8("actionStatus"));
        actionTag = new QAction(MainWindow);
        actionTag->setObjectName(QString::fromUtf8("actionTag"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_9 = new QVBoxLayout(centralWidget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        informationTab = new QWidget();
        informationTab->setObjectName(QString::fromUtf8("informationTab"));
        verticalLayout_10 = new QVBoxLayout(informationTab);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        followUpBox = new QGroupBox(informationTab);
        followUpBox->setObjectName(QString::fromUtf8("followUpBox"));
        verticalLayout_8 = new QVBoxLayout(followUpBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        followUpView = new QTableView(followUpBox);
        followUpView->setObjectName(QString::fromUtf8("followUpView"));

        verticalLayout_7->addWidget(followUpView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(followUpBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(followUpBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_8->addLayout(verticalLayout_7);


        verticalLayout_10->addWidget(followUpBox);

        dbInfoBox = new QGroupBox(informationTab);
        dbInfoBox->setObjectName(QString::fromUtf8("dbInfoBox"));
        horizontalLayout_6 = new QHBoxLayout(dbInfoBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_6 = new QLabel(dbInfoBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        label_7 = new QLabel(dbInfoBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);


        horizontalLayout_6->addLayout(verticalLayout_6);


        verticalLayout_10->addWidget(dbInfoBox);

        tabWidget->addTab(informationTab, QString());
        searchTab = new QWidget();
        searchTab->setObjectName(QString::fromUtf8("searchTab"));
        tabWidget->addTab(searchTab, QString());
        tagsTab = new QWidget();
        tagsTab->setObjectName(QString::fromUtf8("tagsTab"));
        verticalLayout_2 = new QVBoxLayout(tagsTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(tagsTab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        filterTagsEdit = new QLineEdit(tagsTab);
        filterTagsEdit->setObjectName(QString::fromUtf8("filterTagsEdit"));

        horizontalLayout_4->addWidget(filterTagsEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tagView = new QTableWidget(tagsTab);
        tagView->setObjectName(QString::fromUtf8("tagView"));

        verticalLayout_2->addWidget(tagView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newTagButton = new QPushButton(tagsTab);
        newTagButton->setObjectName(QString::fromUtf8("newTagButton"));

        horizontalLayout->addWidget(newTagButton);

        modifyTagButton = new QPushButton(tagsTab);
        modifyTagButton->setObjectName(QString::fromUtf8("modifyTagButton"));

        horizontalLayout->addWidget(modifyTagButton);

        deleteTagButton = new QPushButton(tagsTab);
        deleteTagButton->setObjectName(QString::fromUtf8("deleteTagButton"));

        horizontalLayout->addWidget(deleteTagButton);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(tagsTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_9->addWidget(label_3);

        filterStatusesEdit = new QLineEdit(tab);
        filterStatusesEdit->setObjectName(QString::fromUtf8("filterStatusesEdit"));

        horizontalLayout_9->addWidget(filterStatusesEdit);


        verticalLayout_5->addLayout(horizontalLayout_9);

        statusesView = new QTableWidget(tab);
        statusesView->setObjectName(QString::fromUtf8("statusesView"));

        verticalLayout_5->addWidget(statusesView);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        newStatusButton = new QPushButton(tab);
        newStatusButton->setObjectName(QString::fromUtf8("newStatusButton"));

        horizontalLayout_10->addWidget(newStatusButton);

        modifyStatusButton = new QPushButton(tab);
        modifyStatusButton->setObjectName(QString::fromUtf8("modifyStatusButton"));

        horizontalLayout_10->addWidget(modifyStatusButton);

        deleteStatusButton = new QPushButton(tab);
        deleteStatusButton->setObjectName(QString::fromUtf8("deleteStatusButton"));

        horizontalLayout_10->addWidget(deleteStatusButton);


        verticalLayout_5->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab, QString());
        addressesTab = new QWidget();
        addressesTab->setObjectName(QString::fromUtf8("addressesTab"));
        verticalLayout_4 = new QVBoxLayout(addressesTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(addressesTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        filterAddressEdit = new QLineEdit(addressesTab);
        filterAddressEdit->setObjectName(QString::fromUtf8("filterAddressEdit"));

        horizontalLayout_8->addWidget(filterAddressEdit);


        verticalLayout_4->addLayout(horizontalLayout_8);

        tableWidget_3 = new QTableWidget(addressesTab);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));

        verticalLayout_4->addWidget(tableWidget_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        newAddressButton = new QPushButton(addressesTab);
        newAddressButton->setObjectName(QString::fromUtf8("newAddressButton"));

        horizontalLayout_7->addWidget(newAddressButton);

        viewAddressItemsButton = new QPushButton(addressesTab);
        viewAddressItemsButton->setObjectName(QString::fromUtf8("viewAddressItemsButton"));

        horizontalLayout_7->addWidget(viewAddressItemsButton);

        modifyAddressButton = new QPushButton(addressesTab);
        modifyAddressButton->setObjectName(QString::fromUtf8("modifyAddressButton"));

        horizontalLayout_7->addWidget(modifyAddressButton);

        deleteAddressButton = new QPushButton(addressesTab);
        deleteAddressButton->setObjectName(QString::fromUtf8("deleteAddressButton"));

        horizontalLayout_7->addWidget(deleteAddressButton);


        verticalLayout_4->addLayout(horizontalLayout_7);

        tabWidget->addTab(addressesTab, QString());
        locationsTab = new QWidget();
        locationsTab->setObjectName(QString::fromUtf8("locationsTab"));
        verticalLayout = new QVBoxLayout(locationsTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_5 = new QLabel(locationsTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_12->addWidget(label_5);

        filterLocationsEdit = new QLineEdit(locationsTab);
        filterLocationsEdit->setObjectName(QString::fromUtf8("filterLocationsEdit"));

        horizontalLayout_12->addWidget(filterLocationsEdit);


        verticalLayout->addLayout(horizontalLayout_12);

        locationsView = new QTableView(locationsTab);
        locationsView->setObjectName(QString::fromUtf8("locationsView"));

        verticalLayout->addWidget(locationsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        newLocationButton = new QPushButton(locationsTab);
        newLocationButton->setObjectName(QString::fromUtf8("newLocationButton"));

        horizontalLayout_2->addWidget(newLocationButton);

        viewItemsLocationButton = new QPushButton(locationsTab);
        viewItemsLocationButton->setObjectName(QString::fromUtf8("viewItemsLocationButton"));

        horizontalLayout_2->addWidget(viewItemsLocationButton);

        modifyLocationButton = new QPushButton(locationsTab);
        modifyLocationButton->setObjectName(QString::fromUtf8("modifyLocationButton"));

        horizontalLayout_2->addWidget(modifyLocationButton);

        deleteLocationButton = new QPushButton(locationsTab);
        deleteLocationButton->setObjectName(QString::fromUtf8("deleteLocationButton"));

        horizontalLayout_2->addWidget(deleteLocationButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(locationsTab, QString());
        itemsTab = new QWidget();
        itemsTab->setObjectName(QString::fromUtf8("itemsTab"));
        verticalLayout_3 = new QVBoxLayout(itemsTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_4 = new QLabel(itemsTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_11->addWidget(label_4);

        filterItemsEdit = new QLineEdit(itemsTab);
        filterItemsEdit->setObjectName(QString::fromUtf8("filterItemsEdit"));

        horizontalLayout_11->addWidget(filterItemsEdit);


        verticalLayout_3->addLayout(horizontalLayout_11);

        tableView_2 = new QTableView(itemsTab);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout_3->addWidget(tableView_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        newItemButton = new QPushButton(itemsTab);
        newItemButton->setObjectName(QString::fromUtf8("newItemButton"));

        horizontalLayout_5->addWidget(newItemButton);

        modifyItemButton = new QPushButton(itemsTab);
        modifyItemButton->setObjectName(QString::fromUtf8("modifyItemButton"));

        horizontalLayout_5->addWidget(modifyItemButton);

        deleteItemButton = new QPushButton(itemsTab);
        deleteItemButton->setObjectName(QString::fromUtf8("deleteItemButton"));

        horizontalLayout_5->addWidget(deleteItemButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        tabWidget->addTab(itemsTab, QString());

        verticalLayout_9->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuCreate = new QMenu(menuBar);
        menuCreate->setObjectName(QString::fromUtf8("menuCreate"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuCreate->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionRecent_Files);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionModify);
        menuCreate->addAction(actionLocation);
        menuCreate->addAction(actionItem);
        menuCreate->addAction(actionAddress);
        menuCreate->addSeparator();
        menuCreate->addAction(actionStatus);
        menuCreate->addAction(actionTag);
        menuTools->addAction(actionPreferences);
        menuTools->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(activated()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Invensile", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New file (Ctrl+N)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open a file (Ctrl+O)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save (Ctrl+S)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("MainWindow", "Close file (Ctrl+W)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionRecent_Files->setText(QApplication::translate("MainWindow", "Recent Files", 0, QApplication::UnicodeUTF8));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Exit (Ctrl+Q)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("MainWindow", "Copy (Ctrl+C)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("MainWindow", "Paste (Ctrl+V)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionModify->setText(QApplication::translate("MainWindow", "Modify", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionModify->setToolTip(QApplication::translate("MainWindow", "Modify (Ctrl+M)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionModify->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionLocation->setText(QApplication::translate("MainWindow", "Location", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLocation->setToolTip(QApplication::translate("MainWindow", "Create a location (Alt+C, L)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLocation->setShortcut(QApplication::translate("MainWindow", "Alt+C, L", 0, QApplication::UnicodeUTF8));
        actionItem->setText(QApplication::translate("MainWindow", "Item", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionItem->setToolTip(QApplication::translate("MainWindow", "Create an item (Alt+C, L)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionItem->setShortcut(QApplication::translate("MainWindow", "Alt+C, I", 0, QApplication::UnicodeUTF8));
        actionAddress->setText(QApplication::translate("MainWindow", "Address", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAddress->setToolTip(QApplication::translate("MainWindow", "Create an address (Alt+C, A)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAddress->setShortcut(QApplication::translate("MainWindow", "Alt+C, A", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionStatus->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        actionStatus->setShortcut(QApplication::translate("MainWindow", "Alt+C, S", 0, QApplication::UnicodeUTF8));
        actionTag->setText(QApplication::translate("MainWindow", "Tag", 0, QApplication::UnicodeUTF8));
        actionTag->setShortcut(QApplication::translate("MainWindow", "Alt+C, T", 0, QApplication::UnicodeUTF8));
        followUpBox->setTitle(QApplication::translate("MainWindow", "Follow ups", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Mark as correct", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Modify status", 0, QApplication::UnicodeUTF8));
        dbInfoBox->setTitle(QApplication::translate("MainWindow", "Database Information", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Latest database modification: ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Program version", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(informationTab), QApplication::translate("MainWindow", "Information", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(searchTab), QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Filter tags", 0, QApplication::UnicodeUTF8));
        newTagButton->setText(QApplication::translate("MainWindow", "New tag", 0, QApplication::UnicodeUTF8));
        modifyTagButton->setText(QApplication::translate("MainWindow", "Modify tag", 0, QApplication::UnicodeUTF8));
        deleteTagButton->setText(QApplication::translate("MainWindow", "Delete tag", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tagsTab), QApplication::translate("MainWindow", "Tags", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Filter statuses", 0, QApplication::UnicodeUTF8));
        newStatusButton->setText(QApplication::translate("MainWindow", "New status", 0, QApplication::UnicodeUTF8));
        modifyStatusButton->setText(QApplication::translate("MainWindow", "Modify status", 0, QApplication::UnicodeUTF8));
        deleteStatusButton->setText(QApplication::translate("MainWindow", "Delete status", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Statuses", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Filter addresses", 0, QApplication::UnicodeUTF8));
        newAddressButton->setText(QApplication::translate("MainWindow", "New address", 0, QApplication::UnicodeUTF8));
        viewAddressItemsButton->setText(QApplication::translate("MainWindow", "View address items", 0, QApplication::UnicodeUTF8));
        modifyAddressButton->setText(QApplication::translate("MainWindow", "Modify address", 0, QApplication::UnicodeUTF8));
        deleteAddressButton->setText(QApplication::translate("MainWindow", "Delete address", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(addressesTab), QApplication::translate("MainWindow", "Addresses", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Filter locations", 0, QApplication::UnicodeUTF8));
        newLocationButton->setText(QApplication::translate("MainWindow", "New Location", 0, QApplication::UnicodeUTF8));
        viewItemsLocationButton->setText(QApplication::translate("MainWindow", "View location items", 0, QApplication::UnicodeUTF8));
        modifyLocationButton->setText(QApplication::translate("MainWindow", "Modify location", 0, QApplication::UnicodeUTF8));
        deleteLocationButton->setText(QApplication::translate("MainWindow", "Delete location", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(locationsTab), QApplication::translate("MainWindow", "Locations", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Filter items", 0, QApplication::UnicodeUTF8));
        newItemButton->setText(QApplication::translate("MainWindow", "New item", 0, QApplication::UnicodeUTF8));
        modifyItemButton->setText(QApplication::translate("MainWindow", "Modify item", 0, QApplication::UnicodeUTF8));
        deleteItemButton->setText(QApplication::translate("MainWindow", "Delete item", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(itemsTab), QApplication::translate("MainWindow", "Items", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuCreate->setTitle(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
