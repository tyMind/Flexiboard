#include "loginpage.h"
#include "ui_loginpage.h"

#include <QSqlField>
#include <QDebug>
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_clicked()
{
    //register button clicked
    RegisterDialog *regDialog=new RegisterDialog(this); //?this
    regDialog->setModal(true);
    regDialog->show();
}

void LoginPage::on_pushButton_2_clicked()
{
    //login button clicked, must check if the data provided by user is invalid or not

    //register button in a sign up window
    QString dbDriverName="QPSQL";
    QString dbConnectName="logCon";
    QSqlDatabase db=QSqlDatabase::addDatabase(dbDriverName, dbConnectName);
    QString hostName="LOCALHOST";
    QString dbName="test";
    QString userName="postgres";
    QString password="Pos_20_db$";

    DatabaseOps dbOps;  //TBD: make setIndentity static
    dbOps.setIdentity(db, dbName, hostName, userName, password);

    db.open();

    QSqlQuery qry(db);
    QString execCommand="SELECT *FROM users";
    qry.exec(execCommand);

    QString inputEmail=ui->lineEdit->text();
    QString inputPassword=ui->lineEdit_2->text();

    bool loggedIn=false;
    //search in the db table
    while(qry.next()){
        QString email=qry.value("email").toString();
        QString password=qry.value("password").toString();
        if(email==inputEmail && password==inputPassword){
            qDebug()<<"successful login";
            MainWindow::setLoggedEmail(email);
            this->close();
            loggedIn=true;
            break;
        }
    }
    if(loggedIn==false){
        QMessageBox::information(this, "Error on inputted fields", "You did not type correctly your email or password");
    }

}

