#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QMessageBox>
#include "czlibrary/czlibrary.h"
#include "czlibrary/czqtui.h"
#include "Constants.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int screenWidth,screenHeight,screenNum,
    windowWidth,windowHeight,windowLeft,windowTop;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    //UI measure
    int itemWidth,itemHeight,itemMargin,itemStartX,itemStartY,
    in_usernameStartY,in_passwordStartY,
    btn_loginStartY,btn_exitStartY,
    lineEditTitleWidth;

    //UI Obj
    QPushButton *btn_login,*btn_exit;
    QLineEdit   *input_username,*input_password;

    //Code
    bool m_move;
    QPoint m_startPoint;
    QPoint m_windowPoint;
    string username;
    string password;


    void InitData();
    void InitView();

public slots:
    void btn_loginClick();
    void btn_exitClick();

};
#endif // MAINWINDOW_H
