// ThreadObject.h
#pragma once
#include <QThread>

class ThreadObject
    : public QThread
{
    Q_OBJECT
public:
    ThreadObject();

public slots:
    void StopThread();
protected:
    virtual void run() override;
private:
    bool        is_stop_;
    int         count_;
};
