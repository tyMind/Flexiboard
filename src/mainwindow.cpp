#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Flexiboard");
    setCentralWidget(ui->plainTextEdit);

//    LoginPage *loginPage=new LoginPage(this);
//    loginPage->setModal(true);
//    loginPage->show();

//    while(loginPage->getLogInStatus()==false){}
//    qDebug()<<"pss: "<<loginPage->getLogInStatus();
//    if(loginPage->getLogInStatus()==true){
//        qDebug()<<"must close";
//        loginPage->close();
//    }
//    loginPage->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->setPlainText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString selectedFile=QFileDialog::getOpenFileName(this, "Open file");
    QFile rwStream(selectedFile);

    if(!rwStream.open(QIODevice::ReadOnly)){
        qDebug()<<"couldn't open the file";
    }
    else{
        QTextStream textStream(&rwStream);
        QString textFromFile=textStream.readAll();
        ui->plainTextEdit->setPlainText(textFromFile);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString saveFileName=QFileDialog::getSaveFileName();
    QFile *saveFile=new QFile(saveFileName);
    QTextStream writeStream(saveFile);

    QString text=ui->plainTextEdit->toPlainText();

    if(saveFile->open(QIODevice::WriteOnly)){
        writeStream<<text;
    }

}

void MainWindow::on_actionupdateRemote_triggered()
{
    //creat another column for each user which will show the status
    //of fileOpenRemote
    bool fileOpenRemote=false;
    if(fileOpenRemote==true){
        qDebug()<<"Go and close the opened window on your another device";
    }
    else{
        QString text;
        QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL", "mwindCon");
        DatabaseOps dbOps;
        QString hostName="LOCALHOST";
        QString dbName="test";
        QString username="postgres";
        QString password="Pos_20_db$";
        dbOps.setIdentity(db, dbName, hostName, username, password);

//        bool ok=db.open();
//        if(ok){
//            QSqlQuery updOpenRem(db);
//            QString updExecStat="UPDATE users SET openremote=0 WHERE id=1";
//            if(updOpenRem.exec(updExecStat)){
//                qDebug()<<"Update query has completed successfully";
//            }
//            else{
//                qDebug()<<"there was an issue with the update query";
//            }

//            qDebug()<<"opened!!!!!!!";
//            text=ui->plainTextEdit->toPlainText();
//            QSqlQuery qry;
//            QString prepInsStat="INSERT INTO users (first_name, last_name, text, remote_open) "
//                                "VALUES (:first_name, :last_name, :text, :remote_open)";

//            qry.prepare(prepInsStat);
//            qry.bindValue(":first_name", "tyMind");
//            qry.bindValue(":last_name", "Yeghiazaryan");
//            qry.bindValue(":text", text);
//            qry.bindValue(":remote_open", 0);
//            if(qry.exec()){
//                qDebug()<<"Insertion query executed successfully";
//            }
//            else{
//                qDebug()<<"Insertion query was not successful";
//            }
//       }
//       else{
//            qDebug()<<"couldn't open";
//       }
//       db.close();
//       qDebug()<<"Closing Database";

                bool ok=db.open();
                if(ok){
                    QSqlQuery updOpenRem(db);
//                    QString updExecStat="UPDATE users SET open_remote=0 WHERE id=1";
//                    if(updOpenRem.exec(updExecStat)){
//                        qDebug()<<"Update query has completed successfully";
//                    }
//                    else{
//                        qDebug()<<"there was an issue with the update query";
//                    }

                    qDebug()<<"opened!!!!!!!";
                    text=ui->plainTextEdit->toPlainText();
                    QSqlQuery qry(db);
                    QString prepInsStat="SELECT *FROM users_data";
                    qry.prepare(prepInsStat);

                    qry.exec();

                    QString fetchedData="";
                    qry.next();
                    fetchedData=qry.value("email").toString();
                    qDebug()<<fetchedData;
//                    while(qry.next()){
//                        fetchedData=qry.value("email").toString();
//                        qDebug()<<fetchedData;
//                    }
                    ui->plainTextEdit->setPlainText(fetchedData);

               }
               else{
                    qDebug()<<"couldn't open";
               }
               db.close();
               qDebug()<<"Closing Database";


    }
}
