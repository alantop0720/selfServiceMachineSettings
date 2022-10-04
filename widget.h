#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_hideZizhuji_clicked();

    void on_pushButton_unlock_clicked();

    void on_pushButton_lock_clicked();

private:
    Ui::Widget *ui;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET_H
