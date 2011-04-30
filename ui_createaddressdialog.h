/********************************************************************************
** Form generated from reading UI file 'createaddressdialog.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEADDRESSDIALOG_H
#define UI_CREATEADDRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateAddressDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *refLabel;
    QLineEdit *refLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *statusCB;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *streetLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *townLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *postalCodeLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *countryLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateAddressDialog)
    {
        if (CreateAddressDialog->objectName().isEmpty())
            CreateAddressDialog->setObjectName(QString::fromUtf8("CreateAddressDialog"));
        CreateAddressDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateAddressDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        refLabel = new QLabel(CreateAddressDialog);
        refLabel->setObjectName(QString::fromUtf8("refLabel"));

        horizontalLayout->addWidget(refLabel);

        refLineEdit = new QLineEdit(CreateAddressDialog);
        refLineEdit->setObjectName(QString::fromUtf8("refLineEdit"));
        refLineEdit->setMaxLength(10);
        refLineEdit->setReadOnly(false);

        horizontalLayout->addWidget(refLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nameLabel = new QLabel(CreateAddressDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_2->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(CreateAddressDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        horizontalLayout_2->addWidget(nameLineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(CreateAddressDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        statusCB = new QComboBox(CreateAddressDialog);
        statusCB->setObjectName(QString::fromUtf8("statusCB"));

        horizontalLayout_3->addWidget(statusCB);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label = new QLabel(CreateAddressDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);

        streetLineEdit = new QLineEdit(CreateAddressDialog);
        streetLineEdit->setObjectName(QString::fromUtf8("streetLineEdit"));

        horizontalLayout_8->addWidget(streetLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(CreateAddressDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        townLineEdit = new QLineEdit(CreateAddressDialog);
        townLineEdit->setObjectName(QString::fromUtf8("townLineEdit"));

        horizontalLayout_7->addWidget(townLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(CreateAddressDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        postalCodeLineEdit = new QLineEdit(CreateAddressDialog);
        postalCodeLineEdit->setObjectName(QString::fromUtf8("postalCodeLineEdit"));

        horizontalLayout_6->addWidget(postalCodeLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(CreateAddressDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        countryLineEdit = new QLineEdit(CreateAddressDialog);
        countryLineEdit->setObjectName(QString::fromUtf8("countryLineEdit"));

        horizontalLayout_5->addWidget(countryLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(CreateAddressDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateAddressDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateAddressDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateAddressDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateAddressDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateAddressDialog)
    {
        CreateAddressDialog->setWindowTitle(QApplication::translate("CreateAddressDialog", "Create new address", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        refLabel->setToolTip(QApplication::translate("CreateAddressDialog", "The reference is automatically generated by the program. It will start with the reference of the address, followed by the reference of the location, the entry date, the three first letters of the name and a two-digit number.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        refLabel->setText(QApplication::translate("CreateAddressDialog", "Reference", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("CreateAddressDialog", "Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateAddressDialog", "Status", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateAddressDialog", "Street", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateAddressDialog", "Town", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreateAddressDialog", "Postal code", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreateAddressDialog", "Country", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateAddressDialog: public Ui_CreateAddressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEADDRESSDIALOG_H
