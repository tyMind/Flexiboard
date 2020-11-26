#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QSqlRecord>
#include "registerdialog.h"
#include "mainwindow.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
