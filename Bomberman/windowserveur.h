#ifndef WINDOWSERVEUR_H
#define WINDOWSERVEUR_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QFile>
#include <QTextEdit>
#include <QString>
#include <QTextStream>
#include <QInputDialog>
#include <QDialog>

namespace Ui {
class windowserveur;
}

class windowserveur : public QDialog
{
    Q_OBJECT

public:
    explicit windowserveur(QWidget *parent = 0);
    ~windowserveur();

private:
    Ui::windowserveur *ui;
    QLabel *etatServeur;
    QTcpServer *serveur; // Represente le serveur sur le reseau
    QList<QTcpSocket *> clients; // Gere un tableau contenant la liste des clients


private slots:
    void DemarrerServeur();
    void ArreterServeur();
    void nouvelleConnexion();
    void deconnexionClient();
};

#endif // WINDOWSERVEUR_H
