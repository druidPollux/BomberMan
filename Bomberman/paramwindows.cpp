#include "paramwindows.h"
#include "ui_paramwindows.h"

ParamWindows::ParamWindows(QWidget *parent, int modeOuverture) :
    QDialog(parent),
    ui(new Ui::ParamWindows)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(modeOuverture);
    FillCbResolution();
    connect(ui->cboResolution,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeResolution()));
}

ParamWindows::~ParamWindows()
{
    delete ui;
}

void ParamWindows::FillCbResolution()
{
    ui->cboResolution->addItem("800x600");
    ui->cboResolution->addItem("1024x600");
    ui->cboResolution->addItem("1280x720");
    ui->cboResolution->addItem("1440x990");
    ui->cboResolution->addItem("1920x1080");
}

void ParamWindows::ChangeResolution()
{
    //TODO: Changer la résolution en fonction de la selection
}
