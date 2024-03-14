#include "employe.h"


employe::employe()
{

}
employe:: employe(int i, QString n, QString p, QString ml, int ag,QString r, QString md,int sl , QString d, QString f)
{
    id=i;
    nom=n;
    prenom=p;
    mail=ml;
    age=ag;
    role =r;
    mdp=md;
   salaire=sl;
    h_d=d;
    h_f=f;

}
bool employe :: ajouter()
{
    QSqlQuery query ;
    query.prepare("INSERT INTO EMPLOYE (id,nom,prenom,mail,age,role,mdp,salaire ,h_d,h_f) "
                  "VALUES (:id , :nom,:prenom,:mail,:age,:role,:mdp,:salaire,:h_d,:h_f)");
    query.bindValue(":id",id);
    query.bindValue(":nom" , nom);
    query.bindValue(":prenom" , prenom);
    query.bindValue(":mail" , mail) ;
    query.bindValue(":age" , age);
    query.bindValue(":role" , role);
    query.bindValue(":mdp" , mdp);
    query.bindValue(":salaire" , salaire);
    query.bindValue(":h_d" , h_d);
    query.bindValue(":h_f" , h_f);
    if(query.exec())
    {
        return true ;
    }
    else
    {
        qDebug () << query.lastError() << salaire;
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
    return model;
}
bool employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET nom = :nom, prenom = :prenom, mail = :mail, age = :age, role = :role, mdp = :mdp, salaire= :salaire,h_f = :h_f, h_d = :h_d WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":age", age);
    query.bindValue(":role", role);
    query.bindValue(":mdp", mdp);
    query.bindValue(":salaire", salaire);
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
QSqlQueryModel* employe:: trie(QString attribut)
{
    QSqlQueryModel* model =new QSqlQueryModel() ;
    if(attribut == "nom") model->setQuery("select * from employe order by nom ASC");
    else if( attribut == "prenom") model->setQuery("select * from employe order by prenom ASC");
    else  model->setQuery("select * from employe order by id ASC");
    return  model ;
}
QSqlQueryModel* employe:: recherche (QString attribut , QString ch)
{
    QSqlQueryModel* model =new QSqlQueryModel() ;
    if(attribut == "nom") model->setQuery("SELECT * FROM employe WHERE nom LIKE '%" + ch + "%'");
    else if( attribut == "prenom") model->setQuery("SELECT * FROM employe WHERE prenom LIKE '%" + ch + "%'");
    else  model->setQuery("select * from employe where id LIKE '%" + ch + "%'");
    return  model ;
}
int employe::count (QString ch)
{
    QSqlQueryModel* searchModel = new QSqlQueryModel();
        searchModel->setQuery("SELECT * FROM EMPLOYE WHERE role LIKE '%" + ch + "%'");

        return searchModel->rowCount() ;
}
