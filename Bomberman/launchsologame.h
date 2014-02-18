#ifndef LAUNCHSOLOGAME_H
#define LAUNCHSOLOGAME_H

#include <QDialog>

namespace Ui {
class LaunchSoloGame;
}

class LaunchSoloGame : public QDialog
{
    Q_OBJECT

public:
    explicit LaunchSoloGame(QWidget *parent = 0);
    ~LaunchSoloGame();

private slots:
    void on_scrollLevel_destroyed();

private:
    Ui::LaunchSoloGame *ui;
};

#endif // LAUNCHSOLOGAME_H