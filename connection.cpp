#include "connection.h"
#include<QDebug>


Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("abc");//inserer nom de l'utilisateur
db.setPassword("abc");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
