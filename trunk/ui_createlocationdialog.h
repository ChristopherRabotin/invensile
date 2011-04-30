/********************************************************************************
** Form generated from reading UI file 'createlocationdialog.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATELOCATIONDIALOG_H
#define UI_CREATELOCATIONDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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

class Ui_CreateLocationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *refLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *addressCB;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QComboBox *locationCB;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QDateEdit *creationDateEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QComboBox *statusCB;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *closedLocationCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *closingLabel;
    QDateEdit *closingDateEdit;
    QFormLayout *formLayout;
    QLabel *descriptionLabel;
    QPlainTextEdit *descriptionTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateLocationDialog)
    {
        if (CreateLocationDialog->objectName().isEmpty())
            CreateLocationDialog->setObjectName(QString::fromUtf8("CreateLocationDialog"));
        CreateLocationDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreateLocationDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(CreateLocationDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        refLineEdit = new QLineEdit(CreateLocationDialog);
        refLineEdit->setObjectName(QString::fromUtf8("refLineEdit"));
        refLineEdit->setMaxLength(5);

        horizontalLayout_2->addWidget(refLineEdit);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(CreateLocationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        addressCB = new QComboBox(CreateLocationDialog);
        addressCB->setObjectName(QString::fromUtf8("addressCB"));

        horizontalLayout_6->addWidget(addressCB);


        horizontalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(CreateLocationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        nameLineEdit = new QLineEdit(CreateLocationDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);


        horizontalLayout_10->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(CreateLocationDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        locationCB = new QComboBox(CreateLocationDialog);
        locationCB->setObjectName(QString::fromUtf8("locationCB"));

        horizontalLayout_8->addWidget(locationCB);


        horizontalLayout_10->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(CreateLocationDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        creationDateEdit = new QDateEdit(CreateLocationDialog);
        creationDateEdit->setObjectName(QString::fromUtf8("creationDateEdit"));
        creationDateEdit->setLocale(QLocale(QLocale::French, QLocale::France));
        creationDateEdit->setInputMethodHints(Qt::ImhPreferNumbers);
        creationDateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        creationDateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(creationDateEdit);


        horizontalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(CreateLocationDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        statusCB = new QComboBox(CreateLocationDialog);
        statusCB->setObjectName(QString::fromUtf8("statusCB"));

        horizontalLayout_7->addWidget(statusCB);


        horizontalLayout_11->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        closedLocationCheckBox = new QCheckBox(CreateLocationDialog);
        closedLocationCheckBox->setObjectName(QString::fromUtf8("closedLocationCheckBox"));

        horizontalLayout_5->addWidget(closedLocationCheckBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        closingLabel = new QLabel(CreateLocationDialog);
        closingLabel->setObjectName(QString::fromUtf8("closingLabel"));

        horizontalLayout_4->addWidget(closingLabel);

        closingDateEdit = new QDateEdit(CreateLocationDialog);
        closingDateEdit->setObjectName(QString::fromUtf8("closingDateEdit"));
        closingDateEdit->setLocale(QLocale(QLocale::French, QLocale::France));
        closingDateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        closingDateEdit->setCalendarPopup(true);

        horizontalLayout_4->addWidget(closingDateEdit);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_5);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        descriptionLabel = new QLabel(CreateLocationDialog);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, descriptionLabel);

        descriptionTextEdit = new QPlainTextEdit(CreateLocationDialog);
        descriptionTextEdit->setObjectName(QString::fromUtf8("descriptionTextEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descriptionTextEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(CreateLocationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateLocationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateLocationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateLocationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateLocationDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateLocationDialog)
    {
        CreateLocationDialog->setWindowTitle(QApplication::translate("CreateLocationDialog", "Create location dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateLocationDialog", "Reference", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateLocationDialog", "Address", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateLocationDialog", "Name", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreateLocationDialog", "Parent location", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("CreateLocationDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The entry date is the date at which the item was <span style=\" font-weight:600;\">added</span> to the database. Today's date is the default entry date.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("CreateLocationDialog", "Creation date", 0, QApplication::UnicodeUTF8));
        creationDateEdit->setDisplayFormat(QApplication::translate("CreateLocationDialog", "yyyy.MM.dd", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreateLocationDialog", "Status", 0, QApplication::UnicodeUTF8));
        closedLocationCheckBox->setText(QApplication::translate("CreateLocationDialog", "Location closed", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        closingLabel->setToolTip(QApplication::translate("CreateLocationDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This corresponds to the date on the item. It is <span style=\" font-weight:600;\">not</span> mandatory.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        closingLabel->setText(QApplication::translate("CreateLocationDialog", "Closing date", 0, QApplication::UnicodeUTF8));
        closingDateEdit->setDisplayFormat(QApplication::translate("CreateLocationDialog", "yyyy.MM.dd", 0, QApplication::UnicodeUTF8));
        descriptionLabel->setText(QApplication::translate("CreateLocationDialog", "Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateLocationDialog: public Ui_CreateLocationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATELOCATIONDIALOG_H
