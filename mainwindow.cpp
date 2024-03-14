#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QDebug"
#include <QMessageBox>
#include "employe.h"
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPrinter>
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
    QRegularExpression rx2("^[0-9]+$");

    QValidator *validator2 = new QRegularExpressionValidator(rx2, this);
    ui->age->setValidator(validator2);
    ui->salaire->setValidator(validator2);
    song_bref.setSource(QUrl :: fromLocalFile(":/new/prefix1/son/CMPTKey_Souris raspberry simple clic (ID 1735)_LS.wav")) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    song_bref.play() ;
   // ui->groupBox->hide();
   // ui->groupBox_2->show();
}

void MainWindow::on_start_clicked()
{
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
     int id = ui->id_employe->text().toInt();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
   QString mail = ui->email->text();
    int age=ui->age->text().toInt();
    QString role=ui->role->currentText();
   QString mdp=ui->mdp->text();
  int salaire=ui->salaire->text().toInt();
    QString h_d=ui->h_d->text();
    QString h_f=ui->h_f->text();
    qDebug () << salaire ;
    employe e(id,nom,prenom,mail,age,role,mdp,salaire,h_d,h_f);
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
                 ui->id_employe->setText("");
                 ui->nom->setText("");
                 ui->prenom->setText("");
                 ui->email->setText("");
                 ui->age->setText("");
                 ui->mdp->setText("");
                 ui->salaire->setText("");
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    song_bref.play() ;
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
    int salaire=ui->salaire->text().toInt();
    QString h_d=ui->h_d_2->text();
    QString h_f=ui->h_f_2->text();
    employe e(id,nom,prenom,mail,age,role,mdp,salaire,h_d,h_f);
    if(e.employe_existe())
    {
        if(controleSaisie_modif())
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
                ui->id_employe_2->setText("");
                ui->nom_2->setText("");
                ui->prenom_2->setText("");
                ui->email_2->setText("");
                ui->age_2->setText("");
                ui->mdp_2->setText("");
                ui->salaire_2->setText("");
            }
            else
            {
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("modifier failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
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
                   QObject::tr("employe n'existe pas.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
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

void MainWindow::on_pushButtonupdate_clicked()
{
    ui->grp_gestion->hide();
    ui->grp_start->hide();
    ui->grp_login->hide();
    ui->ajout_employe->hide();
    ui->grp_employe->show();
    ui->grp_maissa->hide ();
    ui->add_formateur->hide();
    ui->grp_menyar->show();
    ui->add_formation_2->hide();
    ui->grp_salma->hide();
    ui->ajout_client->hide();
    ui->grp_zeria->hide();
    ui->ajout_equipement->hide();
    ui->update_employe->hide();
    ui->delete_employe->hide();
    ui->id_employe_2->setText("");
    ui->nom_2->setText("");
    ui->prenom_2->setText("");
    ui->email_2->setText("");
    ui->age_2->setText("");
    ui->mdp_2->setText("");
    ui->salaire_2->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->id_employe_3->text().toInt();
    employe e(id , "" , "" , "" , 0 , "" , "" ,0, "" , "");
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
                  //////////// controle de saisie ajout ///////////
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
    if(ui->salaire->text()=="" || ui->salaire->text()[0]=="0"  || ui->salaire->text().toInt()>2000)
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
    if(ui->age->text()=="" || ui->age->text()[0]=="0"  || ui->age->text().toInt()>50  )
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
    if(ui->h_d->time().hour() >= ui->h_f->time().hour())
    {
        ui->h_d->setStyleSheet("QTimeEdit {"
                               "border: 2px solid red;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
        ui->h_f->setStyleSheet("QTimeEdit {"
                               "border: 2px solid red;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
        i=1;
    }
    else
    {
        ui->h_d->setStyleSheet("QTimeEdit {"
                               "border: 2px solid #9370DB;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
        ui->h_f->setStyleSheet("QTimeEdit {"
                               "border: 2px solid #9370DB;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
    }
    return (i==0);
}

void MainWindow::on_bouton_modfier_clicked()  // check out
{

    QSqlQuery query ;
    query.prepare("select * from EMPLOYE where id=:id");
    query.bindValue(":id" , ui->id_employe_2->text().toInt());
    if(query.exec() && query.next())
    {
        qDebug () << query.value("id").toString() ;
        ui->id_employe_2->setText(query.value(0).toString());
        ui->nom_2->setText(query.value(1).toString());
        ui->prenom_2->setText(query.value(2).toString());
        ui->email_2->setText(query.value(3).toString());
        ui->age_2->setText(query.value(4).toString());
        ui->role_2->setCurrentText(query.value(5).toString());
        ui->mdp_2->setText(query.value(6).toString());
        ui->salaire_2->setText(query.value(7).toString());
        ui->h_d_2->setTime(query.value(8).toTime());
        ui->h_f_2->setTime(query.value(9).toTime());




    }
}
                    ////////////////// controle de saisie update////////////////////
bool MainWindow::controleSaisie_modif()
{
    int i=0;
    /////////////////////////////////////////////////////////////////////////////////////////////////
                                /*****nom_EMPLOYE*****/
    /////////////////////////////////////////////////////////////////////////////////////////////////
    if(ui->nom_2->text()=="")
    {
        ui->nom_2->setStyleSheet("QLineEdit {"
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
        ui->nom_2->setStyleSheet("QLineEdit {"
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
    if(ui->id_employe_2->text()=="")
    {
        ui->id_employe_2->setStyleSheet("QLineEdit {"
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
        ui->id_employe_2->setStyleSheet("QLineEdit {"
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
    if(ui->prenom_2->text()=="")
    {
        ui->prenom_2->setStyleSheet("QLineEdit {"
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
        ui->prenom_2->setStyleSheet("QLineEdit {"
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
    if(ui->email_2->text()=="" || !verifier_mail(ui->email_2->text()))
    {
        ui->email_2->setStyleSheet("QLineEdit {"
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
        ui->email_2->setStyleSheet("QLineEdit {"
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
    if(ui->mdp_2->text()=="")
    {
        ui->mdp_2->setStyleSheet("QLineEdit {"
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
        ui->mdp_2->setStyleSheet("QLineEdit {"
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
    if(ui->salaire_2->text()=="" || ui->salaire_2->text()[0]=="0"  || ui->salaire_2->text().toInt()>2000)
    {
        ui->salaire_2->setStyleSheet("QLineEdit {"
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
        ui->salaire_2->setStyleSheet("QLineEdit {"
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
    if(ui->age_2->text()=="" || ui->age_2->text()[0]=="0"  || ui->age_2->text().toInt()>50)
    {
        ui->age_2->setStyleSheet("QLineEdit {"
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
        ui->age_2->setStyleSheet("QLineEdit {"
                                      "border: 2px solid #9370DB;;"
                                      "border-radius: 10px;"
                                      "padding: 5px; "
                                      "background-color: #FFFFFF;"
                                      "color: #000000; }"

                                  "QLineEdit:hover {border-color: #7E57C2;}"
                                  "QLineEdit:focus { border-color: #5E35B1; }");
    }
    if(ui->h_d_2->time().hour() >= ui->h_f_2->time().hour())
    {
        ui->h_d_2->setStyleSheet("QTimeEdit {"
                               "border: 2px solid red;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
        ui->h_f_2->setStyleSheet("QTimeEdit {"
                               "border: 2px solid red;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
        i=1;
    }
    else
    {
        ui->h_d_2->setStyleSheet("QTimeEdit {"
                               "border: 2px solid #9370DB;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
        ui->h_f_2->setStyleSheet("QTimeEdit {"
                               "border: 2px solid #9370DB;"
                               "border-radius: 10px; "
                               "padding: 5px;"
                               "background-color: #FFFFFF;"
                               "color: #000000;}"

                           "QTimeEdit:hover {border-color: #7E57C2;}"

                           "QTimeEdit:focus {border-color: #5E35B1;}");
    }
    return (i==0);
}

                                                 ////trie/////
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    employe e;
    ui->info_emplye ->setModel(e.trie(arg1));
}
                                         ////Recherche/////
void MainWindow::on_lineEdit_4_textChanged(const QString &arg1) // search
{
    employe e;
    ui->info_emplye ->setModel(e.recherche( ui->comboBox->currentText() , arg1));
}
                                   ////statistique/////
void MainWindow:: stat_employe ()
{
    employe e;
    float s0 , s1 ,s2;
    s0=e.count("Admin");
    s1=e.count("Agent");
    s2=e.count("Rh");
    qDebug() << s2 ;
    QList<QWidget*> childWidgets = ui->label_23->findChildren<QWidget*>();
            for (QWidget* childWidget : childWidgets) {
                childWidget->deleteLater();

            }
            ui->label_23->clear();
            ui->label_23->hide();

        float stat = s0 + s1 + s2 ;
        float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
        float y = (stat != 0) ? (s1 * 100) / stat : 0.0;
        float z = (stat != 0) ? (s2 * 100) / stat : 0.0;

        QString ch1 = QString("Admin %1%").arg(x);
        QString ch2 = QString("Agent %1%").arg(y);
        QString ch3 = QString("RH %1%").arg(z);

            QPieSeries *series=new QPieSeries();  // couleurrrrr
            series->setHoleSize(0.35);



            QPieSlice *slice= series->append(ch1,x);
            slice->setLabelVisible();
            slice->setLabelColor(QColor(Qt::black));
            slice->setBrush(QColor(189, 76, 224, 1));
            QPieSlice *slice1= series->append(ch2,y);
            slice1->setLabelVisible();
            slice1->setLabelColor(QColor(Qt::black));
            slice1->setBrush(QColor(84, 16, 149, 1));
            QPieSlice *slice2= series->append(ch3,z);
            slice2->setLabelVisible();

            slice2->setLabelColor(QColor(Qt::black));
            slice2->setBrush(QColor(Qt::green));


            QChart *chart=new QChart();
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            QBrush backgroundBrush(QColor(187,93,87,0));
            chart->setBackgroundBrush(backgroundBrush);
            QChartView *chartview=new QChartView(chart);
            chartview->setRenderHint(QPainter::Antialiasing);
            chartview->setFixedSize(ui->label_23->size());
            chartview->setParent(ui->label_23);
            ui->label_23->setStyleSheet("background:transparent; color:white; ");
            ui->label_23->show();
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    stat_employe();
}

void MainWindow::on_pdf_clicked()
{
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->info_emplye->model());

        if (model) {
            QString content;
            //header
            for (int col = 0; col < model->columnCount(); ++col) {

                 content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                    }
            content += "\n";
            // Parcourez les données du modèle et ajoutez-les au contenu
            for (int row = 0; row < model->rowCount(); ++row) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    content += model->data(model->index(row, col)).toString() + "\t";
                }
                content += "\n";
            }

            // Créez un objet QTextDocument et définissez son contenu
            QTextDocument document;
            document.setPlainText(content);

            // Créez un dialogue pour sélectionner l'emplacement de sauvegarde du PDF.
            QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "info", "Fichiers PDF (*.pdf)");

            if (!fileName.isEmpty()) {
                // Créez un objet QPrinter pour générer le PDF.
                QPrinter printer;
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName(fileName);

                // Imprimez le document sur le PDF.
                document.print(&printer);

                // Affichez un message à l'utilisateur pour confirmer l'exportation réussie.
                QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
            }
        }
}


