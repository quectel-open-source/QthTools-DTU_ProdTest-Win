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
#include "third/QSimpleUpdater/include/updateConfig.h"
#include <QApplication>
#include <QDir>
#include <QMessageBox>
#include <QStandardPaths>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QReadWriteLock>
#include "Windows.h"
#include "WinUser.h"

QString vitalFilePath = QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation)+"/QthTools-DTU_ProdTest-Win/";
int debugLevel = 0;
QReadWriteLock readWriteLock;
QtMessageHandler gDefaultHandler = NULL;

void customMessageHandler(QtMsgType type,
                          const QMessageLogContext &context,
                          const QString &msg)
{
    QDateTime _datetime = QDateTime::currentDateTime();
    QString szDate = _datetime.toString("yyyy-MM-dd hh:mm:ss.zzz");//"yyyy-MM-dd hh:mm:ss ddd"
    QString txt(szDate);
    if(type < debugLevel)
    {
        return;
    }
    switch (type)
    {
        case QtDebugMsg://调试信息提示
        {
            txt += QString(" [Debug] ");
            break;
        }
        case QtInfoMsg://信息输出
        {
            txt += QString(" [Info] ");
            break;
        }
        case QtWarningMsg://一般的warning提示
        {
            txt += QString(" [Warning] ");
            break;
        }
        case QtCriticalMsg://严重错误提示
        {
            txt += QString(" [Critical] ");
            break;
        }
        case QtFatalMsg://致命错误提示
        {
            txt += QString(" [Fatal] ");
            //abort();
            break;
        }
        default:
        {
            txt += QString(" [Trace] ");
            break;
        }
    }
    txt.append( QString(" %1").arg(context.file) );
    txt.append( QString("<%1>: ").arg(context.line) );
    txt.append(msg);

    readWriteLock.lockForWrite();
    QFile debugLogFile;
    QString configfile = vitalFilePath+".debug.ini";
    debugLogFile.setFileName(configfile);
    if(debugLogFile.size() > 10485760)
    {
        debugLogFile.resize(0);
    }
    debugLogFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&debugLogFile);
    text_stream << txt << "\r\n";
    text_stream.flush();
    debugLogFile.close();
    readWriteLock.unlock();
    if(gDefaultHandler)
    {
        gDefaultHandler(type,context,msg);
    }
}


void initDebugType(bool mode)
{
    Q_UNUSED(mode);
    debugLevel = 0;
    // 更新dump和debug信息输出驱动
//    ::SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)CrashInfocallback);
    gDefaultHandler = qInstallMessageHandler(customMessageHandler);

}

int main(int argc, char *argv[])
{
    initDebugType(0);
    QApplication a(argc, argv);
    // 创建信号量
    QSystemSemaphore semaphore("SingleAppTest2Semaphore", 1);
    // 启用信号量，禁止其他实例通过共享内存一起工作
    semaphore.acquire();

#ifndef Q_OS_WIN32
    // 在linux / unix 程序异常结束共享内存不会回收
    // 在这里需要提供释放内存的接口，就是在程序运行的时候如果有这段内存 先清除掉
    QSharedMemory nix_fix_shared_memory("SingleAppTest2");
    if (nix_fix_shared_memory.attach())
    {undefined
        nix_fix_shared_memory.detach();
    }
#endif
    // 创建一个共享内存  “SingleAppTest2”表示一段内存的标识key 可作为唯一程序的标识
    QSharedMemory sharedMemory("QthTools-DTU_ProdTest-Win");
    // 测试是否已经运行
    bool isRunning = false;
    // 试图将共享内存的副本附加到现有的段中。
    if (sharedMemory.attach())
    {
        // 如果成功，则确定已经存在运行实例
        isRunning = true;
    }
    else
    {
        // 否则申请一字节内存
        sharedMemory.create(1);
        // 确定不存在运行实例
        isRunning = false;
    }
    semaphore.release();

    // 如果您已经运行了应用程序的一个实例，那么我们将通知用户。
    if (isRunning)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The application is already running.\n"
            "Allowed to run only one instance of the application.");
        msgBox.exec();
        return 1;
    }
    //从系统函数中获取显示器的分辨率，设置字体跟随缩放比例来变化
    const float DEFAULT_DPI = 96.0;
    HDC screen = GetDC(nullptr);
    FLOAT dpiX = static_cast<FLOAT>(GetDeviceCaps(screen, LOGPIXELSX));
    ReleaseDC(nullptr, screen);
    float fontSize = dpiX / DEFAULT_DPI;


    QFont font = a.font();
    font.setPointSize(font.pointSize()*fontSize);
    a.setFont(font);

    QDir dir(vitalFilePath);
    if(!dir.exists())
    {
        if(!dir.mkdir(vitalFilePath))
        {
            QMessageBox::critical(NULL,"Dump",QString::fromLocal8Bit("<FONT size=4><div><b>程序无法使用</b><br/></div>"),QString::fromLocal8Bit("确认"));
            return 0;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
