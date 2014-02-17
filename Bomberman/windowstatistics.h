#ifndef WINDOWSTATISTICS_H
#define WINDOWSTATISTICS_H

#include <QDialog>

namespace Ui {
class windowstatistics;
}

class windowstatistics : public QDialog
{
    Q_OBJECT

public:
    explicit windowstatistics(QWidget *parent = 0);
    ~windowstatistics();

private:
    Ui::windowstatistics *ui;
};

#endif // WINDOWSTATISTICS_H
