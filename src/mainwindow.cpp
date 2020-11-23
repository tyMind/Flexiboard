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

        bool ok=db.open();
        if(ok){
//            QSqlQuery updOpenRem(db);
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

            QString fetchedEmail="";
            QString fetchedText="";
            QString userEmail=getLoggedEmail();
            qDebug()<<"User email: "<<userEmail;

            while(qry.next()){
                fetchedEmail=qry.value("email").toString();
                if(fetchedEmail==userEmail){
                    fetchedText=qry.value("text").toString();
                }
            }
            ui->plainTextEdit->setPlainText(fetchedText);

        }
        else{
            qDebug()<<"couldn't open";
        }
        db.close();
        qDebug()<<"Closing Database";


    }
}

QString MainWindow::loggedEmail;

QString MainWindow::getLoggedEmail(){
    return loggedEmail;
}

void MainWindow::setLoggedEmail(QString email){
    loggedEmail=email;
}

