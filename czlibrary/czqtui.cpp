#include "czqtui.h"

CzQtUI::CzQtUI()
{

}
void CzQtUI::GetScreenInfo(int *width,int *height,int *screenNum)
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    //    QRect deskRect = desktopWidget->availableGeometry();
    //    int   m_nActScreenX = deskRect.width();
    //    int   m_nActScreenY = deskRect.height();
    //获取设备屏幕大小
    QRect screenRect = desktopWidget->screenGeometry();
    *width = screenRect.width();
    *height  = screenRect.height();


    //获取系统设置的屏幕个数（屏幕拷贝方式该值为1）
    *screenNum  = desktopWidget->screenCount();
}
/*
 * CzLibrary::setFloatWindow(this,windowLeft,windowTop,windowWidth,windowHeight,"background-color:rgba(128,128,128,200)");
 */
void CzQtUI::setFloatWindow(QWidget *parent,int startX,int startY,int width,int height,QString styleSheet){
    parent->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    parent->setGeometry(QRect(startX, startY, width, height));//可设置窗口显示的方位与大小
    parent->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明
    parent->setStyleSheet(styleSheet);
}

/*
 * btn_login =CzLibrary::AddQPushButton(btn_loginStartX,btn_loginStartY,btn_loginWidth,btn_loginHeight,"登     录",this);
 */
QPushButton* CzQtUI::AddQPushButton(QWidget *parent,int startX,int startY,int width,int height,string text,int textSize){
    QPushButton *btn=new QPushButton(parent);
    btn->setGeometry(startX,startY,width,height);
    btn->setText(text.c_str());
    btn->setFont(QFont("Helvetica",textSize,-1,false));
    btn->show();
    return btn;
}

QLabel* CzQtUI::AddQLabel(QWidget *parent,int startX,int startY,int width,int height,string text,int textSize){
    QLabel *label=new QLabel(parent);
    label->setGeometry(startX,startY,width,height);
    label->setText(text.c_str());
    label->setFont(QFont("Helvetica",textSize,-1,false));
    label->show();
    return label;
}


QLineEdit* CzQtUI::AddQLineEdit(QWidget *parent,int startX,int startY,int width,int height,string placeholder,int textSize,string title,int titleWidth){
    QLineEdit *lineEdit=new QLineEdit(parent);
    if(title.length()>0){
        QLabel *lbl=CzQtUI::AddQLabel(parent, startX, startY,titleWidth,height,title,textSize);
        lbl->setAttribute(Qt::WA_TranslucentBackground, true);
        lineEdit->setGeometry(startX+titleWidth,startY,width-titleWidth,height);
    }else{
        lineEdit->setGeometry(startX,startY,width,height);
    }
    lineEdit->setAttribute(Qt::WA_TranslucentBackground, true);
    lineEdit->setText(placeholder.c_str());
    lineEdit->setFont(QFont("Helvetica",textSize,-1,false));
    lineEdit->setTextMargins(10,10,10,10);
    lineEdit->show();
    lineEdit->setPlaceholderText(placeholder.c_str());
    return lineEdit;
}

void CzQtUI::setPasswordQLineEdit(QLineEdit* lineEdit){
    lineEdit->setEchoMode(QLineEdit::QLineEdit::Password);
}

