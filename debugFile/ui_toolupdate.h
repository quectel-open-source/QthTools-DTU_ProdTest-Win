/********************************************************************************
** Form generated from reading UI file 'toolupdate.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLUPDATE_H
#define UI_TOOLUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolUpdate
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *toolUpdate)
    {
        if (toolUpdate->objectName().isEmpty())
            toolUpdate->setObjectName(QString::fromUtf8("toolUpdate"));
        toolUpdate->resize(400, 300);
        gridLayout = new QGridLayout(toolUpdate);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(toolUpdate);

        QMetaObject::connectSlotsByName(toolUpdate);
    } // setupUi

    void retranslateUi(QWidget *toolUpdate)
    {
        toolUpdate->setWindowTitle(QCoreApplication::translate("toolUpdate", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toolUpdate: public Ui_toolUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLUPDATE_H
