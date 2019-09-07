#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    CzLibrary::Log("MainWindow / init");
    ui->setupUi(this);

    InitData();
    InitView();

}

void MainWindow::InitData(){
    //获取屏幕信息
    CzQtUI::GetScreenInfo(&screenWidth,&screenHeight,&screenNum);
    stringstream ss;
    ss<<"get Screen Info:"<<screenWidth<<","<<screenHeight<<","<<screenNum;
    CzLibrary::Log(ss.str());

    windowWidth=400;
    windowHeight=600;
    windowLeft=(screenWidth-windowWidth)/2;
    windowTop=(screenHeight-windowHeight)/2;

    itemWidth=int(windowWidth*0.8f);
    itemHeight=45;
    itemMargin=20;
    itemStartX=(windowWidth-itemWidth)/2;
    itemStartY=40;

    lineEditTitleWidth=80;

    in_usernameStartY=itemStartY;
    in_passwordStartY=in_usernameStartY+itemHeight+itemMargin;
    btn_loginStartY=in_passwordStartY+itemHeight+itemMargin;
    btn_exitStartY=btn_loginStartY+itemMargin+itemHeight;

    //全局变量
    m_move=false;
}

void MainWindow::InitView(){
    CzQtUI::setFloatWindow(this,windowLeft,windowTop,windowWidth,windowHeight,"background-color:rgba(128,128,128,200)");

    input_username=CzQtUI::AddQLineEdit(this,itemStartX,in_usernameStartY,itemWidth,itemHeight,"",Constants::MainTextSize,"用户名",lineEditTitleWidth);
    input_password=CzQtUI::AddQLineEdit(this,itemStartX,in_passwordStartY,itemWidth,itemHeight,"",Constants::MainTextSize,"密码",lineEditTitleWidth);
    CzQtUI::setPasswordQLineEdit(input_password);

    btn_login =CzQtUI::AddQPushButton(this,itemStartX,btn_loginStartY,itemWidth,itemHeight,"登     录",Constants::MainTextSize);
    connect(btn_login, SIGNAL(clicked()), this, SLOT(btn_loginClick()));

    btn_exit =CzQtUI::AddQPushButton(this,itemStartX,btn_exitStartY,itemWidth,itemHeight,"退     出",Constants::MainTextSize);
    connect(btn_exit, SIGNAL(clicked()), this, SLOT(btn_exitClick()));

}

void MainWindow::btn_loginClick(){
    CzLibrary::Log("MainWindow::btn_loginClick");
    username = string(this->input_username->text().toLocal8Bit());
    password = string(this->input_password->text().toLocal8Bit());
    if(username.length()==0){
        QMessageBox::information(0, "提示", "请输入用户名或手机号", "确定");
        return;
    }
    if(password.length()==0){
        QMessageBox::information(0, "提示", "请输入密码", "确定");
        return;
    }

    CzLibrary::Log(username+","+password);
}

void MainWindow::btn_exitClick(){
    CzLibrary::Log("MainWindow::btn_exitClick");
    exit(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //当鼠标左键点击时.
    if (event->button() == Qt::LeftButton)
    {
        m_move = true;
        //记录鼠标的世界坐标.
        m_startPoint = event->globalPos();
        //记录窗体的世界坐标.
        m_windowPoint = this->frameGeometry().topLeft();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置.
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可.
        this->move(m_windowPoint + relativePos );
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态.
        m_move = false;
    }
}
