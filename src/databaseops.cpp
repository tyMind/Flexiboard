#include "databaseops.h"

void DatabaseOps::setIdentity(QSqlDatabase &db, QString &dbName, QString &hostName, QString &userName, QString &password){
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(password);
}
