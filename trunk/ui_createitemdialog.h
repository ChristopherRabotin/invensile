/********************************************************************************
** Form generated from reading UI file 'createitemdialog.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEITEMDIALOG_H
#define UI_CREATEITEMDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *refLabel;
    QLineEdit *refLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *locationLabel;
    QComboBox *locationCB;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QDateEdit *recordDateEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QDateEdit *entryDateEdit;
    QFormLayout *formLayout;
    QLabel *descriptionLabel;
    QPlainTextEdit *descriptionTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateDialog)
    {
        if (CreateDialog->objectName().isEmpty())
            CreateDialog->setObjectName(QString::fromUtf8("CreateDialog"));
        CreateDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        refLabel = new QLabel(CreateDialog);
        refLabel->setObjectName(QString::fromUtf8("refLabel"));

        horizontalLayout_2->addWidget(refLabel);

        refLineEdit = new QLineEdit(CreateDialog);
        refLineEdit->setObjectName(QString::fromUtf8("refLineEdit"));

        horizontalLayout_2->addWidget(refLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        nameLabel = new QLabel(CreateDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_3->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(CreateDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        horizontalLayout_3->addWidget(nameLineEdit);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        locationLabel = new QLabel(CreateDialog);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        horizontalLayout->addWidget(locationLabel);

        locationCB = new QComboBox(CreateDialog);
        locationCB->setObjectName(QString::fromUtf8("locationCB"));

        horizontalLayout->addWidget(locationCB);


        horizontalLayout_7->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(CreateDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        recordDateEdit = new QDateEdit(CreateDialog);
        recordDateEdit->setObjectName(QString::fromUtf8("recordDateEdit"));
        recordDateEdit->setLocale(QLocale(QLocale::French, QLocale::France));
        recordDateEdit->setInputMethodHints(Qt::ImhPreferNumbers);

        horizontalLayout_5->addWidget(recordDateEdit);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(CreateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        entryDateEdit = new QDateEdit(CreateDialog);
        entryDateEdit->setObjectName(QString::fromUtf8("entryDateEdit"));
        entryDateEdit->setLocale(QLocale(QLocale::French, QLocale::France));

        horizontalLayout_6->addWidget(entryDateEdit);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_4);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        descriptionLabel = new QLabel(CreateDialog);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, descriptionLabel);

        descriptionTextEdit = new QPlainTextEdit(CreateDialog);
        descriptionTextEdit->setObjectName(QString::fromUtf8("descriptionTextEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descriptionTextEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(CreateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateDialog)
    {
        CreateDialog->setWindowTitle(QApplication::translate("CreateDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        refLabel->setText(QApplication::translate("CreateDialog", "Reference", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("CreateDialog", "Name", 0, QApplication::UnicodeUTF8));
        locationLabel->setText(QApplication::translate("CreateDialog", "Location", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateDialog", "Entry date", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateDialog", "Date on item", 0, QApplication::UnicodeUTF8));
        descriptionLabel->setText(QApplication::translate("CreateDialog", "Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateDialog: public Ui_CreateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEITEMDIALOG_H
