#include "loginpage.h"
#include "ui_loginpage.h"

#include <QSqlField>
#include <QDebug>

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_clicked()
{
    //register button clicked
    RegisterDialog *regDialog=new RegisterDialog();
    regDialog->setModal(true);
    regDialog->show();
}

void LoginPage::on_pushButton_2_clicked()
{
    //login button clicked, must check if the data provided by user is invalid or not

    //register button in a sign up window
    QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL", "logCon");
    QString hostName="LOCALHOST";
    QString dbName="test";
    QString userName="postgres";
    QString password="Pos_20_db$";

    DatabaseOps dbOps;  //TBD: make setIndentity static
    dbOps.setIdentity(db, dbName, hostName, userName, password);

    db.open();

    QSqlQuery qry(db);
    qry.exec("SELECT *FROM users");
    QSqlRecord rec=qry.record();

    QString inputEmail=ui->lineEdit->text();
    QString inputPassword=ui->lineEdit_2->text();

    while(qry.next()){
        qDebug()<<"inside while";
        QString email=qry.value("email").toString();
        QString password=qry.value("password").toString();
        qDebug()<<email<<" "<<password;

        if(email==inputEmail && password==inputPassword){
            qDebug()<<"successful login";
            setLoginTrue();
            this->close();
            break;
        }
    }

}

void LoginPage::setLoginTrue(){
    isLoggedIn=true;
}

bool LoginPage::getLogInStatus(){
    return isLoggedIn;
}
