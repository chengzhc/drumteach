#ifndef CZLIBRARY_H
#define CZLIBRARY_H

#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <iostream>
#include <string>
#include <sstream>


namespace czlibrary { class CzLibrary; }
using namespace std;

#define TAG "CzLibrary"
#define IS_LIBRARY_DEBUG true
#define IS_DEBUG true

class CzLibrary : public QApplication
{
public:
    static void Log(string info);

private:
    static void LibraryLog(string info);



};

#endif // CZLIBRARY_H
