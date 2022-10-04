#ifndef CHOOK_H
#define CHOOK_H

#include <QObject>
#include <Windows.h>

/************************************************************************/
/*   钩子类,屏蔽系统热键
*/
/************************************************************************/

class CHook : public QObject
{
    Q_OBJECT

public:
    CHook(QObject *parent = NULL);
    ~CHook();
    void hook(bool flag); //功能键
    void showTaskWindow(bool flag); //显示任务栏
    void enableTaskManager(bool flag); //任务管理器
private:
    HWND task;

};

#endif // CHOOK_H
