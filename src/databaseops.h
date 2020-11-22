#ifndef DATABASEOPS_H
#define DATABASEOPS_H

#include <QSqlDatabase>

class DatabaseOps
{
public:
    void setIdentity(QSqlDatabase &db, QString &dbName, QString &hostName, QString &userName, QString &password);
};

#endif // DATABASEOPS_H
