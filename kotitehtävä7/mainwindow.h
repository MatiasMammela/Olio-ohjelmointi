#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qprogressbar.h"
#include <QMainWindow>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short gameTime;
    bool gameRunning;
    void reset();
    QTimer *pQTimer;
    void setGameInfoText(QString teksti, short aika);
    QProgressBar *player1progressBar;
    QProgressBar *player2progressBar;
    void timeLong();
    void timeShort();
    bool player1Turn;
    QLabel *label;
private slots:
    void startTimer();
    void stopTimer();
    void switchTurn1();
    void switchTurn2();
    void updateProgressBar();
    void timeout();
};
#endif // MAINWINDOW_H
