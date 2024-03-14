#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"employe.h"
#include <QSoundEffect>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool controleSaisie_ajout();
    bool controleSaisie_modif();
    void stat_employe ();
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_start_clicked();

    void on_login_clicked();

    void on_ajouter_clicked();

    void on_employe_clicked();

    void on_confirmer_clicked();

    void on_home_clicked();

    void on_boutonmodifier_clicked();


    void on_formateur_clicked();

    void on_homemaissa_clicked();

    void on_ajouter_2_clicked();

    void on_confirmer_2_clicked();

    void on_formation_clicked();

    void on_homemenyar_clicked();

    void on_confirmermenyar_clicked();

    void on_add_formation_clicked();

    void on_updatemenyar_clicked();

    void on_client_clicked();


    void on_confirmer_4_clicked();

    void on_add_clien_clicked();

    void on_updatesalma_clicked();

    void on_homesalma_clicked();

    void on_confirmerclient_clicked();

    void on_boutonmodifier_2_clicked();



    void on_homezeria_clicked();

    void on_equipement_clicked();

    void on_confirmerequipement_clicked();

    void on_add_equip_clicked();

    void on_update_equip_clicked();

    void on_bouton_confirmer_clicked();

    void on_boutonretour_ajoutemploye_clicked();

    void on_pushButton_3_clicked();

    void on_bouton_modfier_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButtonupdate_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pdf_clicked();

    void on_label_23_linkActivated(const QString &link);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QSoundEffect song_bref ;
};
#endif // MAINWINDOW_H
