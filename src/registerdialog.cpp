#include "registerdialog.h"
#include "ui_registerdialog.h"

#include <QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Register");
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_pushButton_clicked()
{
    //register button in a sign up window
    QString dbDriverName="QPSQL";
    QString dbConnectName="regCon";
    QSqlDatabase db=QSqlDatabase::addDatabase(dbDriverName, dbConnectName);
    QString hostName="LOCALHOST";
    QString dbName="test";
    QString userName="postgres";
    QString password="Pos_20_db$";

    DatabaseOps dbOps;  //TBD: make setIndentity static
    dbOps.setIdentity(db, dbName, hostName, userName, password);

    db.open();

    QSqlQuery regQuery(db);
    QString firstName=ui->lineEdit->text();
    QString lastName=ui->lineEdit_2->text();
    QString email=ui->lineEdit_3->text();
    QString inputPassword=ui->lineEdit_4->text();

    if(firstName=="" || lastName=="" || email=="" || inputPassword==""){
        QMessageBox::warning(this, "Field errors", "Fields cannot be empty");
    }
    else{
        regQuery.prepare("INSERT INTO users (first_name, last_name, email, password, open_remote)"
                         "VALUES(:first_name, :last_name, :email, :password, :open_remote)");
        regQuery.bindValue(":first_name", firstName);
        regQuery.bindValue(":last_name", lastName);
        regQuery.bindValue(":email", email);
        regQuery.bindValue(":password", inputPassword),
        regQuery.bindValue(":open_remote", 0);

        regQuery.exec();
    }
}
