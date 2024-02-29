#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QDebug"
#include <QMessageBox>
#include "employe.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Connection c;
    bool test=c.createconnect();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
       { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->setupUi(this);
    ui->grp_start->show();
    ui->grp_login->hide();
    ui->grp_gestion->hide();
    ui->grp_employe->hide();
    ui->ajout_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->update_employe->hide();
    ui->ajout_equipement->hide();
    ui->delete_employe->hide();

    employe e;
    ui->info_emplye->setModel(e.afficher());
    QRegularExpression rx("^[A-Za-z]+$");

    QValidator *validator1 = new QRegularExpressionValidator(rx, this);
    ui->nom->setValidator(validator1);
    ui->prenom->setValidator(validator1);
    ui->nom_2->setValidator(validator1);
    ui->prenom_2->setValidator(validator1);
    QRegularExpression rx2("^[1-9]+$");

    QValidator *validator2 = new QRegularExpressionValidator(rx2, this);
    ui->age->setValidator(validator2);
    ui->salaire->setValidator(validator2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


   // ui->groupBox->hide();
   // ui->groupBox_2->show();
}

void MainWindow::on_start_clicked()
{
    ui->grp_login->show();
    ui->grp_start->hide();
    ui->grp_gestion->hide();
    ui->grp_employe->hide();
    ui->ajout_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();

}

void MainWindow::on_login_clicked()
{
    ui->grp_gestion->show();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_ajouter_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->show();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_employe_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->show();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_confirmer_clicked()
{
     int id = ui->id_employe->text().toInt();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
   QString mail = ui->email->text();
    int age=ui->age->text().toInt();
    QString role=ui->role->currentText();
   QString mdp=ui->mdp->text();
    QString h_d=ui->h_d->text();
    QString h_f=ui->h_f->text();
    employe e(id,nom,prenom,mail,age,role,mdp,h_d,h_f);
    if(!e.employe_existe())
     {
        if(controleSaisie_ajout())
        {
             if(e.ajouter()==false)
             {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("ajout failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
             }
             else
             {
                 ui->grp_gestion->hide();
                 ui->grp_start->hide();
                 ui->grp_login->hide();
                 ui->ajout_employe->hide();
                 ui->grp_employe->show();
                 ui->grp_maissa->hide();
                 ui->add_formateur->hide();
                 ui->grp_menyar->hide();
                 ui->add_formation_2->hide();
                 ui->grp_salma->hide();
                 ui->ajout_client->hide();
                 ui->grp_zeria->hide();
                 ui->ajout_equipement->hide();
                 ui->update_employe->hide();
                 ui->delete_employe->hide();
                 ui->info_emplye->setModel(e.afficher());
                 ui->id_employe->text()="";
                 ui->nom->text()="";
                 ui->prenom->text()="";
                 ui->email->text()="";
                 ui->age->text()="";
                 ui->mdp->text()="";
                ui->info_emplye->setModel(e.afficher());
              }
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("remplir tous les champs.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("employe existe deja.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    }

}



void MainWindow::on_home_clicked()
{
    ui->grp_gestion->show();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}


void MainWindow::on_boutonmodifier_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->show();
    ui->delete_employe->hide();
}

void MainWindow::on_formateur_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->show();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_homemaissa_clicked()
{
    ui->grp_gestion->show();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_ajouter_2_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->show();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_confirmer_2_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->show();
    ui->add_formateur->hide();
    ui->grp_menyar->show();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();

}




void MainWindow::on_formation_clicked()
{

    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->show();
    ui->add_formateur->hide();
    ui->grp_menyar->show();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();

}

void MainWindow::on_homemenyar_clicked()
{
    ui->grp_gestion->show();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();

}

void MainWindow::on_confirmermenyar_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->show();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_add_formation_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->show();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_updatemenyar_clicked()
{   ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->show();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();

}

void MainWindow::on_client_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->show();
    ui->add_formation_2->hide();
    ui->grp_salma->show();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}



void MainWindow::on_confirmer_4_clicked()
{

    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->show();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();

}

void MainWindow::on_add_clien_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->show();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_updatesalma_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->show();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_homesalma_clicked()
{   ui->grp_gestion->show();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_confirmerclient_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->show();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_boutonmodifier_2_clicked()
{
     ui->grp_gestion->hide();
     ui->grp_start->hide();
     ui->grp_login->hide();
     ui->ajout_employe->hide();
     ui->grp_employe->hide();
     ui->grp_maissa->hide();
     ui->add_formateur->hide();
     ui->grp_menyar->hide();
     ui->add_formation_2->hide();
     ui->grp_salma->hide();
     ui->ajout_client->hide();
     ui->grp_zeria->hide();
     ui->ajout_equipement->hide();
     ui->update_employe->hide();
     ui->delete_employe->hide();
}




void MainWindow::on_homezeria_clicked()
{
    ui->grp_gestion->show();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_equipement_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->show();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_confirmerequipement_clicked()
{   ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->show();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_add_equip_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->show();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_update_equip_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->show();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_bouton_confirmer_clicked() // mt3 lupdate
{
    int id = ui->id_employe_2->text().toInt();
    QString nom = ui->nom_2->text();
    QString prenom = ui->prenom_2->text();
    QString mail = ui->email_2->text();
    int age=ui->age_2->text().toInt();
    QString role=ui->role_2->currentText();
    QString mdp=ui->mdp_2->text();
    QString h_d=ui->h_d_2->text();
    QString h_f=ui->h_f_2->text();
    employe e(id,nom,prenom,mail,age,role,mdp,h_d,h_f);
    if(e.employe_existe())
    {
        if(e.modifier())
        {
            ui->grp_gestion->hide();
            ui->grp_start->hide();
            ui->grp_login->hide();
            ui->ajout_employe->hide();
            ui->grp_employe->show();
            ui->grp_maissa->hide();
            ui->add_formateur->hide();
            ui->grp_menyar->hide();
            ui->add_formation_2->hide();
            ui->grp_salma->hide();
            ui->ajout_client->hide();
            ui->grp_zeria->hide();
            ui->ajout_equipement->hide();
            ui->update_employe->hide();
            ui->delete_employe->hide();
            ui->info_emplye->setModel(e.afficher());
        }
        else
        {
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("modifier failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_boutonretour_ajoutemploye_clicked()
{
    ui->grp_login->hide();
    ui->grp_start->hide();
    ui->grp_gestion->hide();
    ui->grp_employe->show();
    ui->ajout_employe->hide();
    ui->grp_maissa->hide();
    ui->add_formateur->hide();
    ui->grp_menyar->hide();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->id_employe_3->text().toInt();
    employe e(id , "" , "" , "" , 0 , "" , "" , "" , "");
    if(e.employe_existe())
    {
            if(!e.supprimer())
            {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("suppretion failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                ui->info_emplye->setModel(e.afficher());
                ui->id_employe_3->setText("");
            }
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("employe n'existe pas.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
bool verifier_mail(QString ch)
{
    int test1=false;
    int test2=false;
    for(int i=0 ; i<ch.length() ; i++)
    {
        if(test1==false)
        {
            if(ch[i]=='.')
            {
                test1=true ;
            }
        }
        else
        {
            if(ch[i]=='@')
            {
                test2=true;
                break;
            }
        }
    }
    return  (test1 && test2);
}
bool MainWindow:: controleSaisie_ajout()
{
    int i=0;
    /////////////////////////////////////////////////////////////////////////////////////////////////
                                /*****nom_EMPLOYE*****/
    /////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->nom->text()=="")
    {
        ui->nom->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->nom->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }

/////////////////////////////////////////////////////////////////////////////////////////////////
                            /*****ID_EMPLOYE*****/
/////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->id_employe->text()=="")
    {
        ui->id_employe->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->id_employe->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////
                                /*****prenom_EMPLOYE*****/
/////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->prenom->text()=="")
    {
        ui->prenom->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->prenom->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////
                                    /*****prenom_EMPLOYE*****/
/////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->email->text()=="" || !verifier_mail(ui->email->text()))
    {
        ui->email->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->email->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////
                                        /*****mdp_EMPLOYE*****/
/////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->mdp->text()=="")
    {
        ui->mdp->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->mdp->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////
                                            /*****salaire_EMPLOYE*****/
/////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->salaire->text()=="")
    {
        ui->salaire->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->salaire->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////
                                        /*****AGE_EMPLOYE*****/
    /////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->age->text()=="")
    {
        ui->age->setStyleSheet("QLineEdit {"
                                      "border: 2px solid red;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
        i=1;
    }
    else
    {
        ui->age->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
    return (i==0);
}
