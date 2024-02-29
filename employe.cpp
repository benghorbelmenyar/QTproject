#include "employe.h"


employe::employe()
{

}
employe:: employe(int i, QString n, QString p, QString ml, int ag,QString r, QString md, QString d, QString f)
{
    id=i;
    nom=n;
    prenom=p;
    mail=ml;
    age=ag;
    role =r;
    mdp=md;
    h_d=d;
    h_f=f;

}
bool employe :: ajouter()
{
    QSqlQuery query ;
    query.prepare("INSERT INTO EMPLOYE (id,nom,prenom,mail,age,role,mdp,h_d,h_f) "
                  "VALUES (:id , :nom,:prenom,:mail,:age,:role,:mdp,:h_d,:h_f)");
    query.bindValue(":id",id);
    query.bindValue(":nom" , nom);
    query.bindValue(":prenom" , prenom);
    query.bindValue(":mail" , mail) ;
    query.bindValue(":age" , age);
    query.bindValue(":role" , role);
    query.bindValue(":mdp" , mdp);
    query.bindValue(":h_d" , h_d);
    query.bindValue(":h_f" , h_f);
    if(query.exec())
    {
        return true ;
    }
    else
    {
        qDebug () << query.lastError();
        return false ;
    }
}

bool employe :: employe_existe()
{
    QSqlQuery query;
    query.prepare("SELECT * from EMPLOYE where :id=id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
    else
    {
        qDebug () << query.lastError();
        return false;
    }

}
QSqlQueryModel* employe :: afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel() ;
    model->setQuery("SELECT  *  FROM EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("mail"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("age"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("salaire"));
    model->setHeaderData(6, Qt::Horizontal,QObject:: tr("role"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("h_f"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("h_d"));
    model->setHeaderData(8, Qt::Horizontal,QObject:: tr("h_d"));
    return model;
}
bool employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET nom = :nom, prenom = :prenom, mail = :mail, age = :age, role = :role, mdp = :mdp, h_f = :h_f, h_d = :h_d WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":age", age);
    query.bindValue(":role", role);
    query.bindValue(":mdp", mdp);
    query.bindValue(":h_d", h_d);
    query.bindValue(":h_f", h_f);

    if (query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}
bool employe:: supprimer()
{
    QSqlQuery query ;
    query.prepare("delete from EMPLOYE where id=:id");
    query.bindValue(":id" , id);
    if(query.exec())
    {
        return true ;
    }
    else
    {
        return  false ;
    }
}
