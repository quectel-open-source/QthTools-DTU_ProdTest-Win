/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsheng;
    QAction *action_update;
    QAction *action_help;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QTextEdit *textEdit_showMess;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_niceText;
    QLabel *label_niceNum;
    QLabel *label_badRateText;
    QLabel *label_badRate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_imei;
    QLineEdit *lineEdit_imei;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_csq_show;
    QLineEdit *lineEdit_csq;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_flag;
    QComboBox *comboBox_flag;
    QGroupBox *groupBox_serial;
    QGridLayout *gridLayout;
    QLabel *label_12;
    QComboBox *comboBox_uartPort_2;
    QLabel *label_37;
    QComboBox *comboBox_uartBate_2;
    QLabel *label_38;
    QComboBox *comboBox_uartData_2;
    QLabel *label_39;
    QComboBox *comboBox_uartStop_2;
    QPushButton *pushButton_uartOpen_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_csq;
    QSpinBox *spinBox_csq_min;
    QSpinBox *spinBox_csq_max;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_ok;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(446, 433);
        actionsheng = new QAction(MainWindow);
        actionsheng->setObjectName(QString::fromUtf8("actionsheng"));
        action_update = new QAction(MainWindow);
        action_update->setObjectName(QString::fromUtf8("action_update"));
        action_help = new QAction(MainWindow);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        textEdit_showMess = new QTextEdit(groupBox);
        textEdit_showMess->setObjectName(QString::fromUtf8("textEdit_showMess"));

        gridLayout_7->addWidget(textEdit_showMess, 0, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_niceText = new QLabel(groupBox);
        label_niceText->setObjectName(QString::fromUtf8("label_niceText"));
        label_niceText->setMinimumSize(QSize(20, 20));

        horizontalLayout_6->addWidget(label_niceText);

        label_niceNum = new QLabel(groupBox);
        label_niceNum->setObjectName(QString::fromUtf8("label_niceNum"));

        horizontalLayout_6->addWidget(label_niceNum);

        label_badRateText = new QLabel(groupBox);
        label_badRateText->setObjectName(QString::fromUtf8("label_badRateText"));

        horizontalLayout_6->addWidget(label_badRateText);

        label_badRate = new QLabel(groupBox);
        label_badRate->setObjectName(QString::fromUtf8("label_badRate"));

        horizontalLayout_6->addWidget(label_badRate);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 2);

        gridLayout_7->addLayout(horizontalLayout_6, 1, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_imei = new QLabel(groupBox);
        label_imei->setObjectName(QString::fromUtf8("label_imei"));

        horizontalLayout_3->addWidget(label_imei);

        lineEdit_imei = new QLineEdit(groupBox);
        lineEdit_imei->setObjectName(QString::fromUtf8("lineEdit_imei"));

        horizontalLayout_3->addWidget(lineEdit_imei);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        gridLayout_7->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_csq_show = new QLabel(groupBox);
        label_csq_show->setObjectName(QString::fromUtf8("label_csq_show"));

        horizontalLayout_4->addWidget(label_csq_show);

        lineEdit_csq = new QLineEdit(groupBox);
        lineEdit_csq->setObjectName(QString::fromUtf8("lineEdit_csq"));

        horizontalLayout_4->addWidget(lineEdit_csq);

        horizontalLayout_4->setStretch(1, 4);

        gridLayout_7->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_flag = new QLabel(groupBox);
        label_flag->setObjectName(QString::fromUtf8("label_flag"));

        horizontalLayout_5->addWidget(label_flag);

        comboBox_flag = new QComboBox(groupBox);
        comboBox_flag->addItem(QString());
        comboBox_flag->addItem(QString());
        comboBox_flag->addItem(QString());
        comboBox_flag->setObjectName(QString::fromUtf8("comboBox_flag"));

        horizontalLayout_5->addWidget(comboBox_flag);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 4);

        gridLayout_7->addLayout(horizontalLayout_5, 3, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_serial = new QGroupBox(centralwidget);
        groupBox_serial->setObjectName(QString::fromUtf8("groupBox_serial"));
        gridLayout = new QGridLayout(groupBox_serial);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_12 = new QLabel(groupBox_serial);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        comboBox_uartPort_2 = new QComboBox(groupBox_serial);
        comboBox_uartPort_2->setObjectName(QString::fromUtf8("comboBox_uartPort_2"));
        comboBox_uartPort_2->setEditable(false);
        comboBox_uartPort_2->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(comboBox_uartPort_2, 0, 1, 1, 1);

        label_37 = new QLabel(groupBox_serial);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout->addWidget(label_37, 1, 0, 1, 1);

        comboBox_uartBate_2 = new QComboBox(groupBox_serial);
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->addItem(QString());
        comboBox_uartBate_2->setObjectName(QString::fromUtf8("comboBox_uartBate_2"));

        gridLayout->addWidget(comboBox_uartBate_2, 1, 1, 1, 1);

        label_38 = new QLabel(groupBox_serial);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout->addWidget(label_38, 2, 0, 1, 1);

        comboBox_uartData_2 = new QComboBox(groupBox_serial);
        comboBox_uartData_2->addItem(QString());
        comboBox_uartData_2->addItem(QString());
        comboBox_uartData_2->addItem(QString());
        comboBox_uartData_2->addItem(QString());
        comboBox_uartData_2->setObjectName(QString::fromUtf8("comboBox_uartData_2"));

        gridLayout->addWidget(comboBox_uartData_2, 2, 1, 1, 1);

        label_39 = new QLabel(groupBox_serial);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout->addWidget(label_39, 3, 0, 1, 1);

        comboBox_uartStop_2 = new QComboBox(groupBox_serial);
        comboBox_uartStop_2->addItem(QString());
        comboBox_uartStop_2->addItem(QString());
        comboBox_uartStop_2->addItem(QString());
        comboBox_uartStop_2->setObjectName(QString::fromUtf8("comboBox_uartStop_2"));

        gridLayout->addWidget(comboBox_uartStop_2, 3, 1, 1, 1);

        pushButton_uartOpen_2 = new QPushButton(groupBox_serial);
        pushButton_uartOpen_2->setObjectName(QString::fromUtf8("pushButton_uartOpen_2"));
        pushButton_uartOpen_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Bell MT\";\n"
"color: rgb(0, 170, 0);\n"
"\n"
"\n"
""));

        gridLayout->addWidget(pushButton_uartOpen_2, 4, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_serial, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        gridLayout_8 = new QGridLayout(groupBox_3);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_csq = new QLabel(groupBox_3);
        label_csq->setObjectName(QString::fromUtf8("label_csq"));

        horizontalLayout_2->addWidget(label_csq);

        spinBox_csq_min = new QSpinBox(groupBox_3);
        spinBox_csq_min->setObjectName(QString::fromUtf8("spinBox_csq_min"));

        horizontalLayout_2->addWidget(spinBox_csq_min);

        spinBox_csq_max = new QSpinBox(groupBox_3);
        spinBox_csq_max->setObjectName(QString::fromUtf8("spinBox_csq_max"));

        horizontalLayout_2->addWidget(spinBox_csq_max);


        gridLayout_8->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_ok = new QPushButton(widget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setMinimumSize(QSize(70, 70));
        pushButton_ok->setMaximumSize(QSize(70, 70));
        pushButton_ok->setStyleSheet(QString::fromUtf8("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:35px;padding:2px 4px;border-style: outset;}\"\n"
"\"QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}\"\n"
"\"QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}\""));

        horizontalLayout->addWidget(pushButton_ok);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_8->addWidget(widget, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 446, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_update);
        menu->addAction(action_help);

        retranslateUi(MainWindow);

        comboBox_uartBate_2->setCurrentIndex(0);
        comboBox_uartData_2->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionsheng->setText(QCoreApplication::translate("MainWindow", "sheng", nullptr));
        action_update->setText(QCoreApplication::translate("MainWindow", "\345\215\207\347\272\247\346\243\200\346\265\213", nullptr));
        action_help->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\230\276\347\244\272", nullptr));
        label_niceText->setText(QCoreApplication::translate("MainWindow", "\345\220\210\346\240\274\346\225\260\357\274\232", nullptr));
        label_niceNum->setText(QString());
        label_badRateText->setText(QCoreApplication::translate("MainWindow", "\344\270\215\345\220\210\346\240\274\346\225\260\357\274\232", nullptr));
        label_badRate->setText(QString());
        label_imei->setText(QCoreApplication::translate("MainWindow", "IMEI:", nullptr));
        label_csq_show->setText(QCoreApplication::translate("MainWindow", "CSQ:", nullptr));
        label_flag->setText(QCoreApplication::translate("MainWindow", "\344\272\247\346\265\213\346\240\207\345\277\227:", nullptr));
        comboBox_flag->setItemText(0, QString());
        comboBox_flag->setItemText(1, QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\344\272\247\346\265\213", nullptr));
        comboBox_flag->setItemText(2, QCoreApplication::translate("MainWindow", "\350\257\245\344\272\247\345\223\201\345\267\262\344\272\247\346\265\213", nullptr));

        groupBox_serial->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_uartBate_2->setItemText(0, QCoreApplication::translate("MainWindow", "4800", nullptr));
        comboBox_uartBate_2->setItemText(1, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBox_uartBate_2->setItemText(2, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboBox_uartBate_2->setItemText(3, QCoreApplication::translate("MainWindow", "38400", nullptr));
        comboBox_uartBate_2->setItemText(4, QCoreApplication::translate("MainWindow", "57600", nullptr));
        comboBox_uartBate_2->setItemText(5, QCoreApplication::translate("MainWindow", "115200", nullptr));
        comboBox_uartBate_2->setItemText(6, QCoreApplication::translate("MainWindow", "230400", nullptr));
        comboBox_uartBate_2->setItemText(7, QCoreApplication::translate("MainWindow", "460800", nullptr));
        comboBox_uartBate_2->setItemText(8, QCoreApplication::translate("MainWindow", "921600", nullptr));

        label_38->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboBox_uartData_2->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_uartData_2->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_uartData_2->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_uartData_2->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_39->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        comboBox_uartStop_2->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_uartStop_2->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        comboBox_uartStop_2->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        pushButton_uartOpen_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\350\256\276\347\275\256", nullptr));
        label_csq->setText(QCoreApplication::translate("MainWindow", "CSQ\350\214\203\345\233\264", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\344\270\255", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
