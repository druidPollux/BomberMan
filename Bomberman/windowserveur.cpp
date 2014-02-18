#include "windowserveur.h"
#include "ui_windowserveur.h"
#include <QMessageBox>

windowserveur::windowserveur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowserveur)
{
    ui->setupUi(this);
    connect(ui->pushButtonLancerServeur,SIGNAL(clicked()),this, SLOT(DemarrerServeur()));
    connect(ui->pushButtonArreterServeur,SIGNAL(clicked()),this, SLOT(ArreterServeur()));
    connect(ui->pushButtonFermer,SIGNAL(clicked()),this,SLOT(close()));
}

windowserveur::~windowserveur()
{
    delete ui;
}

void windowserveur::DemarrerServeur()
{
        etatServeur = new QLabel;
        // changer text label
        ui->labelStatutServeur->setText("Le serveur est démarré.");

        serveur = new QTcpServer(this);
        if (!serveur->listen(QHostAddress::Any, 60000)) // Demarrage du serveur sur toutes les IP disponibles et sur le port 60000
        {
            // Si le serveur n'a pas ete demarre correctement

            ui->labelStatutServeurErreur->setText(tr("Le serveur est déja demarré. Raison :<br />") + serveur->errorString());

        }else
        {
            // changer text label
            ui->labelStatutServeur->setText("Le serveur à été demarré sur le port 60 000 <strong>") ;//+ QString::number(serveur->serverPort());

        }
}


void windowserveur::ArreterServeur()
{
    // changer text label
    ui->labelStatutServeur->setText("Le serveur est arreté.");
    serveur->close();
}
void windowserveur::nouvelleConnexion()
{
    //** Gestion des connections clients et de port dans un tableau
    QTcpSocket *nouveauClient = serveur->nextPendingConnection();
    clients << nouveauClient;

}

void windowserveur::deconnexionClient()
{
     //** On determine quel client se deconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // Si par hasard on n'a pas trouve le client a l'origine du signal, on arrete la methode
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}


