// ThreadObject.cpp
#include "ThreadObject.h"
#include <QDebug>
#include <windows.h>
#include <QSettings>

ThreadObject::ThreadObject()
    : is_stop_(false)
    , count_(0) {  }



void ThreadObject::StopThread()
{
    is_stop_ = true;
}

void ThreadObject::run()
{
//    while (!is_stop_) {
//        qInfo() << "Thread-ID: " << QThread::currentThreadId() << " Count: " << ++count_;
//        sleep(3);
//    }
    qDebug() << "start" ;
    //创建QSettings对象并指定ini文件路径并将格式设置为ini
      QSettings setting("./config.ini", QSettings::IniFormat);

      QString temp = setting.value("debug").toString();
      qDebug() << "temp=" << temp ;


      if ( QString::compare(temp, "1") == 0 )
          msleep(10000);








//    QString name = "Qt624QWindowIcon";//窗口的类名
//    QString windowname = "alantop_set";//窗口标题名
//    HWND hwnd = FindWindow((LPCWSTR)name.unicode(),(LPCWSTR)windowname.unicode());//查找窗口句柄



//    qDebug() << hwnd << Qt::endl;
//    ShowWindow(hwnd,SW_HIDE);//激活并置顶窗口，ShowWindow里面的参数可以网上搜一下，不同功能不同参数。

    //QString name = "Qt624QWindowIcon";//窗口的类名
    QString title = "alantop_set";//窗口标题名
    //HWND hwnd = FindWindow((LPCWSTR)name.unicode(),(LPCWSTR)windowname.unicode());//查找窗口句柄
    HWND hwnd = FindWindow(NULL, (LPCWSTR)title.unicode());
    ShowWindow(hwnd,SW_HIDE);//激活并置顶窗口，ShowWindow里面的参数可以网上搜一下，不同功能不同参数。

    qDebug() << "hwnd=" <<  hwnd << Qt::endl;




    qInfo() << "Thread-ID: " << QThread::currentThreadId() << " Exit";
}

//Sleep(10000);

//QString name = "Qt5QWindowIcon";//窗口的类名
//QString windowname = "alantop_set";//窗口标题名
//HWND hwnd = FindWindow((LPCWSTR)name.unicode(),(LPCWSTR)windowname.unicode());//查找窗口句柄
//ShowWindow(hwnd,SW_HIDE);//激活并置顶窗口，ShowWindow里面的参数可以网上搜一下，不同功能不同参数。
