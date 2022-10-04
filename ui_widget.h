/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_unlock;
    QPushButton *hideZizhuji;
    QPushButton *pushButton_lock;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(683, 523);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 60, 180, 100));
        pushButton->setMaximumSize(QSize(181, 101));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 60, 180, 100));
        pushButton_unlock = new QPushButton(Widget);
        pushButton_unlock->setObjectName(QString::fromUtf8("pushButton_unlock"));
        pushButton_unlock->setGeometry(QRect(100, 180, 180, 100));
        hideZizhuji = new QPushButton(Widget);
        hideZizhuji->setObjectName(QString::fromUtf8("hideZizhuji"));
        hideZizhuji->setGeometry(QRect(170, 350, 300, 100));
        pushButton_lock = new QPushButton(Widget);
        pushButton_lock->setObjectName(QString::fromUtf8("pushButton_lock"));
        pushButton_lock->setGeometry(QRect(350, 180, 180, 100));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "alantop_set", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\232\220\350\227\217\344\273\273\345\212\241\346\240\217 \346\241\214\351\235\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\344\273\273\345\212\241\346\240\217\346\241\214\351\235\242", nullptr));
        pushButton_unlock->setText(QCoreApplication::translate("Widget", "\345\261\217\350\224\275\351\224\201\345\256\232\350\256\241\347\256\227\346\234\272", nullptr));
        hideZizhuji->setText(QCoreApplication::translate("Widget", "\351\232\220\350\227\217\345\272\224\347\224\250\347\250\213\345\272\217  \345\261\217\350\224\275\345\270\270\347\224\250\347\263\273\347\273\237\351\224\256\347\233\230", nullptr));
        pushButton_lock->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\351\224\201\345\256\232\350\256\241\347\256\227\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
