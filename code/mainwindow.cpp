/*
Copyright (C) 2023  Quectel Wireless Solutions Co.,Ltd.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qDebug>
#include <QAbstractItemView>
#include <QDateTime>
#include "third/QSimpleUpdater/include/updateConfig.h"
#include <QPainter>
#include <QCoreApplication>

QString softwareVersion = "1.1.1";
QString pushStyleSheet = "QPushButton{border:2px groove gray;border-radius:35px;padding:2px 4px;border-style: outset;font: 87 12pt \"Arial Black\";} \
                         QPushButton:hover{background-color:rgb(229, 241, 251); color: black;} \
                         QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}";

enum
{
    DEV_STATUS_FAULT = 0,
    DEV_STATUS_PASS,
    DEV_STATUS_CLEAR
};

enum
{
    TEXTEDIT_COLOR_BLACK = 0,
    TEXTEDIT_COLOR_RED,
    TEXTEDIT_COLOR_YELLOW,
    TEXTEDIT_COLOR_GREEN,
    TEXTEDIT_COLOR_BLUE,
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle(QString::fromLocal8Bit("DTU产测工具V")+softwareVersion);
    MainWindow::setWindowIcon(QIcon(":/image/quectel.ico"));
    this->qserial = new qSerial();
    this->qserial->portListPeriodSet(1000);
    connect(this->qserial,SIGNAL(portListNoticSignal(QList<QString>)),this,SLOT(portListNoticSlot(QList<QString>)));
    connect(this->qserial,SIGNAL(dataReadNoticSignal(QByteArray)),this,SLOT(dataReadNoticSlot(QByteArray)));

    ui->lineEdit_csq->setEnabled(false);
    ui->lineEdit_imei->setEnabled(false);
    ui->comboBox_flag->setEnabled(false);
    ui->spinBox_csq_min->setValue(15);
    ui->spinBox_csq_min->setRange(1,30);
    ui->spinBox_csq_max->setValue(31);
    ui->spinBox_csq_max->setEnabled(false);
    ui->comboBox_uartData_2->setEnabled(false);
    ui->comboBox_uartStop_2->setEnabled(false);
    ui->comboBox_uartBate_2->setCurrentIndex(5);
    ui->label_niceNum->setText(QString("<font style=' color:green;'>%1</font>").arg(QString::number(0)));
    ui->label_badRate->setText(QString("<font style=' color:red;'>%1</font>").arg(QString::number(0)));
    recvTimer = new QTimer();
    connect(recvTimer,SIGNAL(timeout()),this,SLOT(recvCheckTimeOut()));
    sendTimer = new QTimer();
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(sendTime()));
    ui->pushButton_ok->setStyleSheet(pushStyleSheet+"QPushButton{background-color: rgb(246, 246, 0);}");
    ui->pushButton_ok->setEnabled(false);


    ui->textEdit_showMess->document()->setMaximumBlockCount(2000);
//    ui->pushButton_reset->setStyleSheet("border:none;");

//    QPainter painter(ui->widget);
//    painter.fillRect(ui->widget->rect(),Qt::red);
//    update();
    ui->textEdit_showMess->setReadOnly(true);
    updateVersion = new toolUpdate();
    updateVersion->checkForUpdates();
    connect(ui->menubar,SIGNAL(triggered(QAction*)),this,SLOT(action_handle(QAction*)));

    recvAckTimer = new QTimer();
    connect(recvAckTimer,SIGNAL(timeout()),this,SLOT(recvAckTimeOut()));


    ui->pushButton_ok->setText(QString::fromLocal8Bit(""));
    ui->pushButton_ok->setStyleSheet(pushStyleSheet+"QPushButton{background-color: rgb(192, 192, 192);}");
    ui->label_badRate->hide();
    ui->label_badRateText->hide();
    ui->label_niceText->hide();
    ui->label_niceNum->hide();
    ui->statusBar->setStyleSheet("color:blue");
    ui->statusBar->showMessage(QString::fromLocal8Bit("温馨提示：请选择相应串口号并打开串口进行设备检测"));
    ui->statusBar->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dataHandle(QByteArray &data)
{
    qDebug()<<__FUNCTION__<<data;
    if(!data.isEmpty())
    {
        QList<QByteArray> list = data.split('\r');
        qDebug()<<"QList:"<<(list[0]).toHex();
//        if(list.size()!= 2)
//        {
//            qCritical()<<"mess is error";
//            g_recvData.clear();
//            return;
//        }
        dataAnalysis(list[0].toHex());
        g_recvData = g_recvData.mid(data.size());
    }
}

void MainWindow::dataAnalysis(QByteArray data)
{
    QList<int> numData;
    QByteArray payload;
    bool showErrorFlag = true;
    if(data.size()%2 != 0)
    {
        goto exit;
    }
    for(int i=0;i<data.size();i+=2)
    {
        numData.append(data.mid(i,2).toUInt(nullptr,16));
    }
    if(numData.at(0) != 0xAA || 0xAA !=numData.at(1) || numData.size() < 10)
    {
        qCritical()<<"mess head is error"<<"numData:"<<numData;
        goto exit;
    }
    int16_t dataLen = (numData[2]<<16)+ numData[3];
    int8_t dataCrc = numData[4] & 0xFF;
    int16_t dataId = (numData[5]<<16)+ numData[6];
    int16_t dataCmd = (numData[7]<<16)+ numData[8];
    int8_t dataCurCrc = 0;


    for(int i =0;i<numData.size()-9;i++)
    {
        payload.append(numData[9+i]);
    }
    if(numData.size()-4 != dataLen)
    {
        qCritical()<<"dataLen is error:"<<"dataLen"<<dataLen<<"numData:"<<numData.size();
        goto exit;
    }
    for(int i=0;i<numData.size()-5;i++)
    {
        dataCurCrc += numData.at(5+i);
    }

    if(dataCurCrc  != dataCrc)
    {
        qCritical()<<"crc is error:"<<"dataCurCrc:"<<dataCurCrc<<"dataCrc:"<<dataCrc;
        goto exit;
    }
    if(0x0002 == dataCmd && 0x0001 == dataId)
    {
        QList<QByteArray> payloadList = payload.split('&');
        if(payloadList.size() != 4 && payloadList.size() != 3)
        {
            qCritical()<<"payload size is error"<<payloadList;
            goto exit;
        }
        int factoryFlag = payloadList[0].toHex().toInt(0,16);
        QString serial = payloadList[1];
        int csq = -1;
        QString IMEI;
        if(4 == payloadList.size())
        {
            csq = payloadList[2].toHex().toInt(0,16);
            IMEI = payloadList[3];
        }
        else if(3 == payloadList.size())
        {
            IMEI = payloadList[2];
        }
        if((factoryFlag != 0 && factoryFlag != 1) || serial.isEmpty() || IMEI.isEmpty())
        {
            qCritical()<<"payload is error";
            goto exit;
        }
        ui->comboBox_flag->setCurrentIndex(factoryFlag+1);
        if(factoryFlag == 1)
        {
            logShow(QString::fromLocal8Bit("当前设备已产测！"),TEXTEDIT_COLOR_RED);
            ui->lineEdit_imei->setText(IMEI);
            showErrorFlag = false;
            sendCheckMessTimes = 0;
            goto exit;
        }
        if(-1 != csq)
        {
            ui->lineEdit_csq->setText(QString::number(csq));
        }
        ui->lineEdit_imei->setText(IMEI);
        if(csq>=ui->spinBox_csq_min->value() && csq <= ui->spinBox_csq_max->value() && 0 == serial.compare("factory_test"))
        {
            resetUIInfo(DEV_STATUS_PASS);
            logShow(QString::fromLocal8Bit("设备产测合格，请点击合格按钮！"));
        }
        else
        {
            logShow(QString::fromLocal8Bit("设备产测不合格！"),TEXTEDIT_COLOR_RED);
            resetUIInfo(DEV_STATUS_FAULT);
        }

    }
    else if(0x0004 == dataCmd && 0x0002 == dataId)
    {
        if(recvAckTimer->isActive())
        {
            recvAckTimer->stop();
        }
        QList<QByteArray> payloadList = payload.split('&');
        if(payloadList.size() != 2)
        {
            qCritical()<<"payload size is error"<<payloadList;
            goto exit;
        }
        if(0 == QString(payloadList[0]).compare(ui->lineEdit_imei->text()))
        {
            if(payloadList[1].toHex().toInt(0,16) == 0x01)
            {
                logShow(QString::fromLocal8Bit("产测标志位设置成功！"));
                if(0 == ui->pushButton_ok->text().compare(QString::fromLocal8Bit("不合格")))
                {
                    badDevSum++;
                }
                else
                    niceDevSum++;
                ui->label_niceNum->setText(QString("<font style=' color:green;'>%1</font>").arg(QString::number(niceDevSum)));
                ui->label_badRate->setText(QString("<font style=' color:red;'>%1</font>").arg(QString::number(badDevSum)));
            }
            else if(payloadList[1].toHex().toInt(0,16) == 0x00)
            {
                logShow(QString::fromLocal8Bit("产测标志位设置失败！"),TEXTEDIT_COLOR_RED);
                badDevSum++;
                ui->label_badRate->setText(QString("<font style=' color:red;'>%1</font>").arg(QString::number(badDevSum)));
            }
        }
        else
        {
            logShow(QString::fromLocal8Bit("产测标志位设置失败！"),TEXTEDIT_COLOR_RED);
        }
        resetUIInfo(DEV_STATUS_CLEAR);
    }
    else
    {
        qCritical()<<"can not handle mess";
    }
    return;
exit:
    if(showErrorFlag)
    {
        logShow(QString::fromLocal8Bit("设备信息错误！"));
    }
    else
    {
        nonBlockingSleep(1500);
    }
    resetUIInfo(DEV_STATUS_CLEAR);
}

QByteArray MainWindow::getDevInfo()
{
    QByteArray info;
    info.append(char(0xAA));
    info.append(char(0xAA));
    info.append(char(0x00));
    info.append(char(0x11));
    info.append(char(0x19));
    info.append(char(0x00));
    info.append(char(0x01));
    info.append(char(0x00));
    info.append(char(0x01));
    info.append("factory_test");
    return info;
}

QByteArray MainWindow::setDevFlag(bool flag)
{
    QByteArray info;
    info.append(char(0xAA));
    info.append(char(0xAA));


    QByteArray importData;
    importData.append(char(0x00));
    importData.append(char(0x02));
    importData.append(char(0x00));
    importData.append(char(0x03));
    importData.append(ui->lineEdit_imei->text()+"&");
    importData.append(char(flag));

    int8_t sum =0;
    for(int i=0;i<importData.size();i++)
    {
        sum += importData[i];
    }
    int16_t dataLen = importData.size()+1;
    info.append(char(dataLen >> 8));
    info.append(char(dataLen));

    info.append(char(sum));
    info.append(importData);

    return info;
}

void MainWindow::resetUIInfo(int mode)
{
    if(mode == DEV_STATUS_FAULT) // 不合格
    {
        ui->pushButton_ok->setText(QString::fromLocal8Bit("不合格"));
        ui->pushButton_ok->setStyleSheet(pushStyleSheet+"QPushButton{background-color: rgb(255, 0, 0);}");
        ui->pushButton_ok->setEnabled(false);
        sendFlag = true;
        if(serialIsOpen)
        {
            if(sendTimer->isActive())
            {
                sendTimer->setInterval(2000);
            }
            else
                sendTimer->start(2000);
        }
        sendCheckMessTimes = 0;
    }
    else if(mode == DEV_STATUS_PASS)
    {
        ui->pushButton_ok->setStyleSheet(pushStyleSheet+"QPushButton{background-color: rgb(0, 255, 0);}");
        ui->pushButton_ok->setText(QString::fromLocal8Bit("合格"));
        ui->pushButton_ok->setEnabled(true);
        sendFlag = false;
        if(sendTimer->isActive())
            sendTimer->stop();
        sendCheckMessTimes = 0;
    }
    else
    {
        if(serialIsOpen)
        {
            ui->pushButton_ok->setStyleSheet(pushStyleSheet+"QPushButton{background-color: rgb(246, 246, 0);}");
            ui->pushButton_ok->setText(QString::fromLocal8Bit("测试中"));
            ui->pushButton_ok->setEnabled(false);
            ui->lineEdit_csq->clear();
            ui->lineEdit_imei->clear();
            ui->comboBox_flag->setCurrentIndex(0);
            sendFlag = true;
            if(sendTimer->isActive())
            {
                sendTimer->setInterval(2000);
            }
            else
                sendTimer->start(2000);
        }
    }
}

void MainWindow::logShow(QString data,int colorMode)
{
    if(TEXTEDIT_COLOR_RED == colorMode)
    {
        ui->textEdit_showMess->append(QString("<font style=' color:red;'>%1</font>").arg("["+QDateTime::currentDateTime().toString("yy-MM-dd hh:mm:ss.zzz")+"]"+data));
    }
    else
        ui->textEdit_showMess->append(QString("<font style=' color:black;'>%1</font>").arg("["+QDateTime::currentDateTime().toString("yy-MM-dd hh:mm:ss.zzz")+"]"+data));
}




/**************************************************************************
** 功能	@brief :  串口信息更新
** 输入	@param :
** 输出	@retval:
***************************************************************************/
void MainWindow::portListNoticSlot(QList<QString> portList)
{
    qInfo()<<__FUNCTION__;
    qDebug()<<QString::fromLocal8Bit("串口列表发生变化")<<portList;
    if(portList.count() <= 0)
    {
        qWarning()<<QString::fromLocal8Bit("串口列表为空");
        return;
    }
    QString currentPort = ui->comboBox_uartPort_2->currentText();
    ui->comboBox_uartPort_2->clear();
    ui->comboBox_uartPort_2->addItems(portList);

    if(this->qserial->serialIsOpen() && portList.contains(currentPort) == false)
    {
        on_pushButton_uartOpen_2_clicked();
    }
    else if(this->qserial->serialIsOpen() == false)
    {
        ui->comboBox_uartPort_2->setCurrentText(portList.first());
    }
    else
    {
        ui->comboBox_uartPort_2->setCurrentText(currentPort);
    }

    //调整下拉列表宽度，完整显示
    int max_len=0;
    for(int idx=0;idx<ui->comboBox_uartPort_2->count();idx++)
    {
        if(max_len<ui->comboBox_uartPort_2->itemText(idx).toLocal8Bit().length())
        {
            max_len = ui->comboBox_uartPort_2->itemText(idx).toLocal8Bit().length();
        }
    }
    ui->comboBox_uartPort_2->view()->setFixedWidth(max_len*9*0.75);

}


void MainWindow::on_pushButton_uartOpen_2_clicked()
{
    qDebug()<< "on_pushButton_uartOpen_2_clicked:"<<ui->pushButton_uartOpen_2->text();
    if(ui->pushButton_uartOpen_2->text() == QString::fromLocal8Bit("打开串口"))
    {
        qDebug()<< QString::fromLocal8Bit("打开串口");
        if( true == this->qserial->serialOpen(ui->comboBox_uartPort_2->currentText(),ui->comboBox_uartBate_2->currentText().toInt(),ui->comboBox_uartData_2->currentText().toInt(),QSerialPort::NoParity,ui->comboBox_uartStop_2->currentText().toInt(),QSerialPort::NoFlowControl))
        {

            ui->pushButton_uartOpen_2->setText(QString::fromLocal8Bit("关闭串口"));
            ui->comboBox_uartPort_2->setEnabled(false);
            ui->comboBox_uartBate_2->setEnabled(false);
            sendFlag = true;
            if(sendTimer->isActive())
            {
                sendTimer->setInterval(2000);
            }
            else
                sendTimer->start(2000);
            logShow(QString::fromLocal8Bit("开始产测"));
            serialIsOpen = true;
            resetUIInfo(DEV_STATUS_CLEAR);
            sendCheckMessTimes = 0;
            ui->statusBar->showMessage(QString::fromLocal8Bit(""));
        }
        else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("串口打开失败，请检查是否被占用！"),"ok");
        }
    }
    else
    {
        this->qserial->SerialClose();
        ui->pushButton_uartOpen_2->setText(QString::fromLocal8Bit("打开串口"));
        ui->comboBox_uartPort_2->setEnabled(true);
        ui->comboBox_uartBate_2->setEnabled(true);
        serialIsOpen = false;
        resetUIInfo(DEV_STATUS_CLEAR);
        if(sendTimer->isActive())
        {
            sendTimer->stop();
        }
        badDevSum = 0;
        niceDevSum = 0;
        ui->label_niceNum->setText(QString("<font style=' color:green;'>%1</font>").arg(QString::number(0)));
        ui->label_badRate->setText(QString("<font style=' color:red;'>%1</font>").arg(QString::number(0)));
        ui->pushButton_ok->setText(QString::fromLocal8Bit(""));
        ui->pushButton_ok->setStyleSheet(pushStyleSheet+"QPushButton{background-color: rgb(192, 192, 192);}");
        ui->statusBar->showMessage(QString::fromLocal8Bit("温馨提示：请选择相应串口号并打开串口进行设备检测！"));

    }
}

void MainWindow::dataReadNoticSlot(QByteArray recvData)
{
    g_recvData.append(recvData);
    recvTimer->start(80);
}

void MainWindow::on_spinBox_csq_min_valueChanged(int arg1)
{
    if(arg1 < 31)
    {
        ui->spinBox_csq_max->setMinimum(arg1+1);
    }
}

void MainWindow::recvCheckTimeOut()
{
    if(!g_recvData.isEmpty())
    {
        recvHandleFlag = true;
        dataHandle(g_recvData);
        recvHandleFlag = false;
    }
    else
    {
        recvTimer->stop();
    }
}

void MainWindow::sendTime()
{
    if(sendFlag  && recvHandleFlag == false)
    {
        if(300 == sendCheckMessTimes && true == serialIsOpen)
        {
            on_pushButton_uartOpen_2_clicked();
            logShow(QString::fromLocal8Bit("检测次数超过300，自动关闭串口检测"));
            return;
        }
        logShow(QString::fromLocal8Bit("发送产测信息%1次").arg(QString::number(sendCheckMessTimes+1)));
        sendCheckMessTimes++;
        this->qserial->SerialSend(getDevInfo());
        resetUIInfo(DEV_STATUS_CLEAR);
    }
}

void MainWindow::on_pushButton_ok_clicked()
{
    bool flag = false;
    if(0 == ui->pushButton_ok->text().compare(QString::fromLocal8Bit("合格")))
    {
        flag = true;
    }
    else if(0 == ui->pushButton_ok->text().compare(QString::fromLocal8Bit("测试中")))
    {
        return;
    }
    this->qserial->SerialSend(setDevFlag(flag));
    recvAckTimer->start(2000);
}

void MainWindow::action_handle(QAction *action)
{
    QString name = action->objectName();
    if(0 == name.compare("action_update"))
    {
        updateVersion->checkForUpdates();
    }
    else if(0 == name.compare("action_help"))
    {
        action_helpFile_clicked();
    }
}

void MainWindow::action_helpFile_clicked()
{
    if(helpProcess != NULL)
    {
        helpProcess->close();
        helpProcess = NULL;
    }
    helpProcess = new QProcess(this);
    qDebug()<<QDir::currentPath();
    QString docFilePath = QDir::currentPath()+"/doc/help.chm";

    QFileInfo file(docFilePath);

    if((!file.isFile()) || (getFileTime(":/image/help.chm") > file.lastModified()))
    {
        QDir dir(QDir::currentPath()+"/doc/");
        if(!dir.exists())
        {
            if(!dir.mkdir(QDir::currentPath()+"/doc/"))
            {
                QMessageBox::critical(NULL,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("<FONT size=4><div><b>程序无法使用该路径</b><br/></div>"),QString::fromLocal8Bit("确认"));
                helpProcess->close();
                return;
            }
        }
        QFile::remove(docFilePath);
        QFile::copy(":/image/help.chm",docFilePath);
    }
    QStringList manuals(docFilePath);
    helpProcess->start("hh.exe",manuals);
    helpProcess->waitForStarted();
}

QDateTime MainWindow::getFileTime(QString path)
{
    QFileInfo file(":/image/help.chm");
    return file.lastModified();
}

void MainWindow::recvAckTimeOut()
{
    resetUIInfo(DEV_STATUS_CLEAR);
}

void MainWindow::nonBlockingSleep(int sectime)
{
    QTime dieTime = QTime::currentTime().addMSecs(sectime);

    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 500);
    }
}
