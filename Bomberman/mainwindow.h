#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void BeginPartySolo();
    void BeginPartyMulti();
    void LoadPartySolo();
    void LoadPartyMulti();
    void SavePartySolo();
    void Quit();
    void GameControls();
    void DisplaySetting();
    void AudioSetting();
    void Help();
    void Credits();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
