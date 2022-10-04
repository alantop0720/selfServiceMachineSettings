#include "widget.h"
#include "ui_widget.h"

#include <windows.h>
#include <QDebug>
#include <QKeyEvent>

#include "chook.h"
#include "ThreadObject.h"


extern HHOOK keyHook;
extern HHOOK mouseHook;

LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam );

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    setWindowFlags( Qt::WindowStaysOnTopHint);

    CHook hk;
    hk.hook(true);
    hk.enableTaskManager(true);

    on_pushButton_clicked();


    ThreadObject * thread = new ThreadObject();
    thread->start();



    ui->setupUi(this);




}

Widget::~Widget()
{
    UnhookWindowsHookEx(keyHook);
    UnhookWindowsHookEx(mouseHook);
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    HWND hDesktop, hTask;
    hDesktop = ::FindWindow(L"Progman",NULL);
    //hDesktop = ::FindWindowEx(0,0,L"Progman",NULL);
    hTask = ::FindWindow(L"Shell_TrayWnd",NULL);
    qDebug() << hDesktop << Qt::endl;
    // 隐藏任务栏/桌面
    ::ShowWindow(hTask,SW_HIDE);
    // 隐藏桌面
    bool ret = ::ShowWindow(hDesktop,SW_HIDE);
    qDebug() << ret << Qt::endl;
}

void Widget::on_pushButton_2_clicked()
{
    HWND hDesktop, hTask;
    hDesktop=FindWindow(L"Progman",NULL);
    hTask=FindWindow(L"Shell_TrayWnd",NULL);
    // 显示任务栏
    ::ShowWindow(hTask,SW_SHOW);
    // 显示桌面
    ::ShowWindow(hDesktop,SW_SHOW);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        qDebug() << " 应用内捕捉到 esc" << Qt::endl;
}

void Widget::on_hideZizhuji_clicked()
{
//    QString name = "Qt624QWindowIcon";//窗口的类名
//    QString windowname = "alantop_set";//窗口标题名
//    HWND hwnd = FindWindow((LPCWSTR)name.unicode(),(LPCWSTR)windowname.unicode());//查找窗口句柄
//    ShowWindow(hwnd,SW_HIDE);//激活并置顶窗口，ShowWindow里面的参数可以网上搜一下，不同功能不同参数。



    QString name = "alantop_set";
    HWND hwnd = FindWindow(NULL, (LPCWSTR)name.unicode()); //查找窗口句柄（这里的参数记得是宽字符形式，用LPCWSTR转换或者直接填入L" "）
    if(::IsWindow(hwnd)) //句柄是否存在
    {
        ShowWindow(hwnd,SW_HIDE);

        //SetForegroundWindow(hwnd); //激活窗口
    }
    keyHook =SetWindowsHookEx( WH_KEYBOARD_LL,keyProc,GetModuleHandle(NULL),0);

}

void Widget::on_pushButton_unlock_clicked()
{
    CHook hk;
    hk.hook(true);
    hk.enableTaskManager(true);
}

void Widget::on_pushButton_lock_clicked()
{
    CHook hk;
    hk.hook(true);
    hk.enableTaskManager(false);
}
