#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    connect(ui->actionSauvegarderPartieSolo,SIGNAL(triggered()),this,SLOT(BeginPartySolo()));
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
    QMessageBox msg;
    msg.setText("Vous venez de lancer une partie solo.");
    msg.exec();
}

void MainWindow::BeginPartyMulti()
{
    etatServeur = new QLabel;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(etatServeur);
    setLayout(layout);

    // Gestion du serveur
    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 60000)) // Demarrage du serveur sur toutes les IP disponibles et sur le port 60000
    {
        // Si le serveur n'a pas ete demarre correctement
        etatServeur->setText(tr("Le serveur n'a pas pu etre demarre. Raison :<br />") + serveur->errorString());
    }
    else
    {
        // Si le serveur a ete demarre correctement
        QMessageBox msg;
        msg.setText(tr("Vous venez de lancer une partie multi.<br>") + tr("Le serveur à été demarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
        msg.exec();
}

}

void MainWindow::LoadPartySolo()
{
    QMessageBox msg;
    msg.setText("Vous venez de charger une partie solo.");
    msg.exec();
}

void MainWindow::LoadPartyMulti()
{
    QMessageBox msg;
    msg.setText("Vous venez de charger une partie multi.");
    msg.exec();
}

void MainWindow::SavePartySolo()
{
    QMessageBox msg;
    msg.setText("Vous venez de sauvegarder une partie solo.");
    msg.exec();
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
    QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations des commandes de jeu.");
    msg.exec();
}

void MainWindow::DisplaySetting()
{
    QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations d'affichage.");
    msg.exec();
}

void MainWindow::AudioSetting()
{
    QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations audio.");
    msg.exec();
}

void MainWindow::Help()
{
    QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations audio.");
    msg.exec();
}

void MainWindow::Credits()
{
    QMessageBox msg;
    msg.setText("Vous venez d'ouvrir les configurations audio.");
    msg.exec();
}

void MainWindow::Statistics()
{
//QTextEdit zoneTexte;
//zoneTexte.setGeometry(100,100,400,200);
//zoneTexte.setReadOnly(true);

    QString texte;
    QFile fichier("C:/Users/admin/Documents/GitHub/BomberMan/Bomberman/1.txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {

         texte = fichier.readAll();
        // zoneTexte.setText(texte);
        // zoneTexte.show();
        QMessageBox msgStatistics;
        msgStatistics.setGeometry(10,100,400,200);
        msgStatistics.information(this, "Statistiques du joueur", texte);




//QMessageBox information;
// information.setGeometry(10,100,400,200);
// information.information(this, "Statistiques du joueur", texte);

         fichier.close();
    }
    else texte = "Impossible d'ouvrir le fichier !";


}

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

