/********************************************************************************
** Form generated from reading UI file 'textinput.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTINPUT_H
#define UI_TEXTINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextInput
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelName;
    QLineEdit *lineEditName;

    void setupUi(QDialog *TextInput)
    {
        if (TextInput->objectName().isEmpty())
            TextInput->setObjectName("TextInput");
        TextInput->resize(291, 96);
        buttonBox = new QDialogButtonBox(TextInput);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 60, 251, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(TextInput);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 251, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(horizontalLayoutWidget);
        labelName->setObjectName("labelName");

        horizontalLayout->addWidget(labelName);

        lineEditName = new QLineEdit(horizontalLayoutWidget);
        lineEditName->setObjectName("lineEditName");

        horizontalLayout->addWidget(lineEditName);


        retranslateUi(TextInput);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TextInput, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TextInput, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TextInput);
    } // setupUi

    void retranslateUi(QDialog *TextInput)
    {
        TextInput->setWindowTitle(QCoreApplication::translate("TextInput", "Please enter a name", nullptr));
        labelName->setText(QCoreApplication::translate("TextInput", "Variable Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextInput: public Ui_TextInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTINPUT_H
