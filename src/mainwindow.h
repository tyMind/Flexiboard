#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBlock>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QWindow>

#include "databaseops.h"
#include "loginpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static void setLoggedEmail(QString email);
    static QString getLoggedEmail();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionupdateRemote_triggered();

private:
    Ui::MainWindow *ui;
    QWidget *nw;

    static QString loggedEmail;
};


#endif // MAINWINDOW_H
