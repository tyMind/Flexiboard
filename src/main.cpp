#include "mainwindow.h"
//#include "loginpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    LoginPage login;
    login.setModal(true);
    login.show();

//    QWidget *wdg=new QWidget();
//    wdg->show();

    return a.exec();
}
