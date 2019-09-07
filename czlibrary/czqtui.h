#ifndef CZQTUI_H
#define CZQTUI_H

#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <iostream>
#include <string>
#include <sstream>
#include <QLabel>
#include <QLineEdit>

namespace czlibrary { class CzQtUI; }
using namespace std;

class CzQtUI
{
public:
    CzQtUI();

    static void GetScreenInfo(int *width,int *height,int *screenNum);
    static void setFloatWindow(QWidget *parent,int startX,int startY,int width,int height,QString styleSheet);
    static QPushButton* AddQPushButton(QWidget *parent,int startX,int startY,int width,int height,string text,int textSize);
    static QLabel* AddQLabel(QWidget *parent,int startX,int startY,int width,int height,string text,int textSize);
    static QLineEdit*AddQLineEdit(QWidget *parent,int startX,int startY,int width,int height,string placeholder,int textSize,string title="",int titleLength=0);
    static void setPasswordQLineEdit(QLineEdit* lineEdit);
};

#endif // CZQTUI_H
