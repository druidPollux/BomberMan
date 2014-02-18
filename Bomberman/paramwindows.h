#ifndef PARAMWINDOWS_H
#define PARAMWINDOWS_H

#include <QDialog>

namespace Ui {
class ParamWindows;
}

class ParamWindows : public QDialog
{
    Q_OBJECT

public:
    explicit ParamWindows(QWidget *parent = 0, int modeOuverture = 0);
    ~ParamWindows();

private:
    Ui::ParamWindows *ui;
    void FillCbResolution();

private slots:
    void ChangeResolution();
};

#endif // PARAMWINDOWS_H
