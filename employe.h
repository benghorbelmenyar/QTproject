#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "QString"
#include"connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include <QSqlError>
#include<QLCDNumber>
#include<QString>
#include<QSqlQueryModel>
class employe
{
private:
    int id;
    QString nom;
    QString prenom;
    QString mail;
    int age;
    QString role;
    QString mdp;
    QString h_d;
    QString h_f;




public:
    employe();
    employe(int , QString , QString , QString , int ,QString , QString , QString , QString  );
    bool ajouter ();
    bool modifier ();
    bool supprimer();
    QSqlQueryModel* afficher();
    bool employe_existe();
};

#endif // EMPLOYE_H
