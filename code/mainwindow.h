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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serial.h"
#include "third/QSimpleUpdater/toolupdate.h"
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QByteArray getDevInfo();
    QByteArray setDevFlag(bool flag);
    void logShow(QString data,int colorMode = 0);
private slots:
//    void on_pushButton_start_clicked();
    void on_pushButton_uartOpen_2_clicked();
    void dataReadNoticSlot(QByteArray recvData);
    void portListNoticSlot(QList<QString> portList);

    void on_spinBox_csq_min_valueChanged(int arg1);
    void recvCheckTimeOut();
    void sendTime();
    void on_pushButton_ok_clicked();
    void action_handle(QAction* action);
    void recvAckTimeOut();
private:
    void nonBlockingSleep(int sectime);
    void dataHandle(QByteArray &data);
    void dataAnalysis(QByteArray data);
    void resetUIInfo(int mode);
    void action_helpFile_clicked();
    QDateTime getFileTime(QString path);
private:
    Ui::MainWindow *ui;
    qSerial *qserial;
    bool csqRangEnable = false;
    QTimer *recvTimer;
    QTimer *sendTimer;
    QTimer *recvAckTimer;
    QByteArray g_recvData;
    bool sendFlag = false;
    bool recvHandleFlag = false;
    bool serialIsOpen = false;
    long badDevSum = 0;
    long niceDevSum = 0;
    int sendCheckMessTimes = 0;
    toolUpdate *updateVersion;
    QProcess *helpProcess = NULL;
};
#endif // MAINWINDOW_H
