#include "windowstatistics.h"
#include "ui_windowstatistics.h"

windowstatistics::windowstatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowstatistics)
{
    ui->setupUi(this);
    connect(ui->pushButtonFermer,SIGNAL(clicked()),this,SLOT(close()));
}

windowstatistics::~windowstatistics()
{
   delete ui;
}
