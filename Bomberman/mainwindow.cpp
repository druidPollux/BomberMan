#include "mainwindow.h"
#include "paramwindows.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDialog>
#include "windowstatistics.h"
#include "windowserveur.h"
#include "launchsologame.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Maximize the window
    showMaximized();

    //Show welcome message
    ui->statusBar->showMessage("Bienvenue sur BOMBERMAN.", 15000);

    // Linking buttons to action triggered
    connect(ui->actionDemarrerPartieSolo,SIGNAL(triggered()),this,SLOT(BeginPartySolo()));
    connect(ui->actionDemarrerPartieMulti,SIGNAL(triggered()),this,SLOT(BeginPartyMulti()));
    connect(ui->actionChargerPartieSolo,SIGNAL(triggered()),this,SLOT(LoadPartySolo()));
    connect(ui->actionChargerPartieMulti,SIGNAL(triggered()),this,SLOT(LoadPartyMulti()));
    connect(ui->actionSauvegarderPartieSolo,SIGNAL(triggered()),this,SLOT(SavePartySolo()));
    connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(Quit()));
    connect(ui->actionCommandes_de_jeu,SIGNAL(triggered()),this,SLOT(GameControls()));
    connect(ui->actionAffichage,SIGNAL(triggered()),this,SLOT(DisplaySetting()));
    connect(ui->actionAudio,SIGNAL(triggered()),this,SLOT(AudioSetting()));
    connect(ui->actionAide,SIGNAL(triggered()),this,SLOT(Help()));
    connect(ui->actionA_propos,SIGNAL(triggered()),this,SLOT(Credits()));
    connect(ui->actionAffichageStatistics,SIGNAL(triggered()),this,SLOT(Statistics()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BeginPartySolo()
{
    /*QMessageBox msg;
    msg.setText("Vous venez de lancer une partie solo.");
    msg.exec();*/

    LaunchSoloGame* formsologame = new LaunchSoloGame(this);
    formsologame->show();
}

void MainWindow::BeginPartyMulti()
{
    windowserveur* formServeur;
    formServeur = new windowserveur(this);
    formServeur->exec();
}

void MainWindow::LoadPartySolo()
{   
    // Ouverture du dossier parent de la solution et filtre sur les fichiers de type texte pour sélection fichier à ouvrir
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichiers texte (*.txt)");

    // Message d'information provisoire indiquant le chemin d'accès au fichier à ouvrir
    QMessageBox::information(this, "Fichier", "Vous avez ouvert le fichier :\n" + fichier);

    // on déclare la variable de type fichier, puis on l'ouvre en mode "lecture seule"
    QFile fichierACharger(fichier);
    fichierACharger.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux (&fichierACharger);

    QString ligne;

    // On parcours ensuite le fichier ligne par ligne en y appliquant un traitement : ici affichage d'une messageBox
    while(! flux.atEnd())
    {
        ligne = flux.readLine();

        QMessageBox msg;
        msg.setText(ligne);
        msg.exec();
    }
}

void MainWindow::LoadPartyMulti()
{
    QMessageBox msg;
    msg.setText("Vous venez de charger une partie multi.");
    msg.exec();
}

void MainWindow::SavePartySolo()
{
    // On ouvre une boite de dialogue permettant la sauvegarde d'un fichier
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString("*.txt"), "Fichiers texte (*.txt);; Tous les fichiers (*.*)");

    // Message d'information provisoire indiquant le chemin d'accès du fichier créé
    QMessageBox::information(this, "Fichier", "Vous avez sauvegardé le fichier :\n" + fichier);
}

void MainWindow::Quit()
{
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Warning, "Confirmation de sortie.", "Êtes-vous sûr de vouloir quitter BomberMan ?", QMessageBox::Yes|QMessageBox::No).exec())
    {
        exit(true);
    }
}


void MainWindow::GameControls()
{
    ParamWindows* paramForm;
    paramForm = new ParamWindows(this, 2);
    paramForm->show();
}

void MainWindow::DisplaySetting()
{
    ParamWindows* paramForm;
    paramForm = new ParamWindows(this, 1);
    paramForm->show();
}

void MainWindow::AudioSetting()
{
    ParamWindows* paramForm;
    paramForm = new ParamWindows(this, 0);
    paramForm->show();
}

void MainWindow::Help()
{
    QString texte;
    QFile fichier("C:/Users/thibaud/Documents/GitHub/BomberMan/Bomberman/Help.txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        texte = fichier.readAll();
        QMessageBox msgHelp;
        msgHelp.setGeometry(10,100,400,200);
        msgHelp.information(this, "Fichier d'aide : ", texte);

        fichier.close();
    }
    else texte = "Impossible d'ouvrir le fichier !";
}

void MainWindow::Credits()
{
    /*QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations audio.");
    msg.exec();*/

    QMessageBox::about(this, tr("BomberMAN"),
                 tr("The <b>BomberMAN</b>  is a strategic, maze-based video game franchise originally developed by Hudson Soft. The original game was published in 1983 and new games have been published at irregular intervals ever since.                Several titles in the 2000s were published by fellow Japanese game company Konami, who gained full control of the franchise when they purchased and absorbed Hudson in 2012. Today, Bomberman has featured in over 70 different games on numerous platforms (including all Nintendo platforms save for the 3DS and Wii U), as well as several anime and manga.His franchise is one of the most commercially successful of all time.    <br><b>Realised by the Dream-Team : </b></br> <br>Petra Kratochvilova</br> <br>Thibaud Cutullic</br><br>Yoann Solacroup</br><br>Yann Damon</br><br>Gregoire Quincy</br><br>Roman Logvinov</br><br>Damien Moro</br>"));
}
void MainWindow::Statistics()
{
    windowstatistics* Stats;
    Stats = new windowstatistics(this);
    Stats->exec();
}

//---- Partie Modifié le 30/01/2014
// Je ne sais si dois intégrer les fonction ci dessous au menu, donc la base des fonction est la.
// On verra avec Damien ...

void MainWindow::nouvelleConnexion()
{
    // Gestion des connections clients et de port dans un tableau
    QTcpSocket *nouveauClient = serveur->nextPendingConnection();
    clients << nouveauClient;

}

void MainWindow::deconnexionClient()
{
     // On determine quel client se deconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouve le client a l'origine du signal, on arrete la methode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}
//---- Fin modif
