#include "chook.h"
#include <QDebug>
#include <QSettings>

//在注册表该目录下增加新内容
#define TASKMANAGERSystem "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
#define TASKMANAGERExplorer "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"

//            case 9:
//            case 27:
//            case 91:
//            case 93:
//            case 145:
//            case 161:

//            case 33:
//            case 34:
//            case 35:
//            case 36:
//            case 37:
//            case 38:
//            case 39:
//            case 40:

//            case 17:
//            case 16:
//            case 18:
//            case 19:

//            case 112:
//            case 113:
//            case 114:
//            case 115:
//            case 116:
//            case 117:
//            case 118:
//            case 119:
//            case 120:
//            case 121:
//            case 122:
//            case 123:



//            case 163:
//            case 164:
//            case 165:

HHOOK keyHook = NULL;
HHOOK mouseHook = NULL;


LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam )
{
    //在WH_KEYBOARD_LL模式下lParam 是指向KBDLLHOOKSTRUCT类型地址
    KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *) lParam;
    //如果nCode等于HC_ACTION则处理该消息，如果小于0，则钩子子程就必须将该消息传递给 CallNextHookEx
    if(nCode == HC_ACTION)
    {
       qDebug() << "键盘" << pkbhs->vkCode <<  Qt::endl;

        if(pkbhs->vkCode == VK_F12)
        {
            qDebug() << "热键呼出 F12" << Qt::endl;

            UnhookWindowsHookEx(keyHook);
            UnhookWindowsHookEx(mouseHook);

            QString name = "Qt624QWindowIcon";//窗口的类名
            QString windowname = "alantop_set";//窗口标题名
            //HWND hwnd = FindWindow((LPCWSTR)name.unicode(),(LPCWSTR)windowname.unicode());//查找窗口句柄
            HWND hwnd = FindWindow(NULL, (LPCWSTR)windowname.unicode());
            ShowWindow(hwnd,SW_SHOW);//激活并置顶窗口，ShowWindow里面的参数可以网上搜一下，不同功能不同参数。
            ShowWindow(hwnd,SW_RESTORE);
            SetForegroundWindow(hwnd);

            //void unHook();
            //qApp->quit();
        }
        if((pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL)& 0x8000 && GetAsyncKeyState(VK_SHIFT)&0x8000)|| //"Ctrl+Shift+Esc"
            (pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL) & 0x8000) || //"Ctrl+Esc"
            (pkbhs->vkCode == VK_TAB && pkbhs->flags & LLKHF_ALTDOWN )|| //"Alt+Tab"
            (pkbhs->vkCode == VK_ESCAPE && pkbhs->flags &LLKHF_ALTDOWN )|| //"Alt+Esc"
            (pkbhs->vkCode == VK_LWIN || pkbhs->vkCode == VK_RWIN )||	// "LWIN/RWIN"
            (pkbhs->vkCode == VK_F4 && pkbhs->flags & LLKHF_ALTDOWN )||   //"Alt+F4"
            (pkbhs->vkCode == (pkbhs->flags & LLKHF_ALTDOWN) && GetAsyncKeyState(VK_CONTROL)& 0x8000 && GetAsyncKeyState(VK_DELETE)&0x8000))//"Ctrl+Alt+Esc"
        {
            return 1;//返回1表示截取消息不再传递,返回0表示不作处理,消息继续传递
        }

        if(
                ( pkbhs->vkCode >= 112 and pkbhs->vkCode <= 123 ) ||
                             ( pkbhs->vkCode >= 33 and pkbhs->vkCode <= 40 ) ||
                             ( pkbhs->vkCode >= 163 and pkbhs->vkCode <= 165 ) ||
                             ( pkbhs->vkCode >= 16 and pkbhs->vkCode <= 19 ) ||
                             ( pkbhs->vkCode ==9  ) ||
                             ( pkbhs->vkCode ==27  )  ||
                             ( pkbhs->vkCode == 145  )  ||
                             ( pkbhs->vkCode == 91  )  ||
                             ( pkbhs->vkCode == 93  )  ||
                             ( pkbhs->vkCode == 161  )
           )
        {
            return 1;//返回1表示截取消息不再传递,返回0表示不作处理,消息继续传递
        }




    }
    return CallNextHookEx(keyHook, nCode, wParam, lParam);//最重要的回调语句
}



//鼠标钩子过程
LRESULT CALLBACK mouseProc(int nCode,WPARAM wParam,LPARAM lParam )
{
    HC_ACTION;
    qDebug() << "鼠标" << nCode << wParam << lParam << Qt::endl;

    return 0;

    //return 1;//返回1表示截取消息不再传递,返回0表示不作处理,消息继续传递

}

CHook::CHook(QObject *parent)
: QObject(parent)
{

}

CHook::~CHook()
{

}

//安装钩子,调用该函数即安装钩子
void CHook::hook(bool flag)
{
    if (flag)
    {
        //这两个底层钩子,不要DLL就可以全局
        //底层键盘钩子
        keyHook =SetWindowsHookEx( WH_KEYBOARD_LL,keyProc,GetModuleHandle(NULL),0);
        //底层鼠标钩子
        mouseHook =SetWindowsHookEx( WH_MOUSE_LL,mouseProc,GetModuleHandle(NULL),0);
    }
    else
    {
        UnhookWindowsHookEx(keyHook);
        //  UnhookWindowsHookEx(mouseHook);
    }
}

//添加注册屏蔽Ctrl+Alt+del
void CHook::enableTaskManager(bool flag)
{
    // 屏蔽ctrl + alt +del 需要修改注册表的值， 取得管理员权限， 关闭360等杀毒软件
    int value = flag ? 0x00000001 : 0x00000000;
    QSettings *settings = new QSettings(TASKMANAGERSystem, QSettings::NativeFormat);
    settings->setValue("DisableTaskMgr", value); //任务管理器
    settings->setValue("DisableChangePassword", value); //更改密码
    settings->setValue("DisableLockWorkstation", value); //锁定计算机
    settings->setValue("DisableSwitchUserOption", value); //切换用户

    QSettings *settings2 = new QSettings(TASKMANAGERExplorer, QSettings::NativeFormat);
    settings2->setValue("NoLogOff", value); //注销

    delete settings;
    delete settings2;
}

//屏蔽任务栏
void CHook::showTaskWindow(bool flag)
{
    if(flag)
        ShowWindow(task,SW_SHOW);
    else
    {
        task=FindWindow(L"Shell_TrayWnd",NULL);
        ShowWindow(task,SW_HIDE);
    }
}
