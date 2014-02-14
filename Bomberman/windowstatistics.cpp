#include "windowstatistics.h"
#include "ui_windowstatistics.h"

windowstatistics::windowstatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowstatistics)
{
    ui->setupUi(this);
}

windowstatistics::~windowstatistics()
{
   delete ui;
}
