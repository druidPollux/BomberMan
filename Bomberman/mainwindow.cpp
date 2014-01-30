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
    QMessageBox msg;
    msg.setText("Vous venez de lancer une partie multi.");
    msg.exec();
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

