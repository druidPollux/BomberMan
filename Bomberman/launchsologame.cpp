#include "launchsologame.h"
#include "ui_launchsologame.h"

LaunchSoloGame::LaunchSoloGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchSoloGame)
{
    ui->setupUi(this);
    connect (ui->exit,SIGNAL(clicked()),this,SLOT(close()));
}

LaunchSoloGame::~LaunchSoloGame()
{
    delete ui;
}

void LaunchSoloGame::on_scrollLevel_destroyed()
{

}