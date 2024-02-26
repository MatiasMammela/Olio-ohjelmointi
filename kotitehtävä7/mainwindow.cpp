#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player1Time=0;
    player2Time=0;
    player1Turn = true;
    gameRunning=false;
    player1progressBar = findChild<QProgressBar *>("progressBar");
    player2progressBar = findChild<QProgressBar *>("progressBar_2");
    player1progressBar->setValue(100);
    player2progressBar->setValue(100);
    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);

    QPushButton *startButton =  findChild<QPushButton *>("start");
        connect(startButton, &QPushButton::clicked,this,&MainWindow::startTimer);
    QPushButton *stopButton =  findChild<QPushButton *>("stop");
        connect(stopButton, &QPushButton::clicked,this,&MainWindow::stopTimer);

    QPushButton *Player1switchButton =  findChild<QPushButton *>("switch_button1");
    connect(Player1switchButton , &QPushButton::clicked,this,&MainWindow::switchTurn1);

    QPushButton *Player2switchButton =  findChild<QPushButton *>("switch_button_2");
    connect(Player2switchButton , &QPushButton::clicked,this,&MainWindow::switchTurn2);

    QPushButton *timeShort =  findChild<QPushButton *>("time_short");
    connect(timeShort , &QPushButton::clicked,this,&MainWindow::timeShort);

    QPushButton *timeLong =  findChild<QPushButton *>("time_long");
    connect(timeLong , &QPushButton::clicked,this,&MainWindow::timeLong);

    QPushButton *reset = findChild<QPushButton *>("reset");
    connect(reset , &QPushButton::clicked,this,&MainWindow::reset);

    label = findChild<QLabel *>("label");
}
void MainWindow::startTimer()
{
    if(gameTime){
        gameRunning=true;
    pQTimer->start(1000);
    label->setText("Player 1 turn");
    qDebug() << player1Turn;
    }else{
       label->setText("Choose the game duration first");
    }
}
void MainWindow::stopTimer()
{
    pQTimer->stop();
    qDebug() << "timerStopped";
}
void MainWindow::switchTurn1(){

    if(player1Turn && gameRunning){
        player1Turn=false;
        label->setText("Player 2 turn");
    }
}
void MainWindow::switchTurn2(){

    if(!player1Turn && gameRunning){
        player1Turn=true;
        label->setText("Player 1 turn");
    }
}

void MainWindow::timeLong(){
    if(!gameRunning){
    gameTime=300;
    player1Time=300;
    player2Time=300;
    label->setText("5 minute Game Selected");
    }
}
void MainWindow::timeShort(){
    if(!gameRunning){
    gameTime=120;
    player1Time=120;
    player2Time=120;
    label->setText("120 second Game Selected");
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateProgressBar()
{
    double percentage;
    if (player1Turn) {
        percentage =100-((static_cast<double>(gameTime - player1Time) / static_cast<double>(gameTime)) * 100.0);
        qDebug() << "Player 1 Percentage:" << percentage;
        percentage = qBound(0.0, percentage, 100.0);
        player1progressBar->setValue(static_cast<int>(percentage));
    } else {
        percentage = 100-((static_cast<double>(gameTime - player2Time) / static_cast<double>(gameTime)) * 100.0);
        qDebug() << "Player 2 Percentage:" << percentage;
        percentage = qBound(0.0, percentage, 100.0);
        player2progressBar->setValue(static_cast<int>(percentage));
    }
}
void MainWindow::timeout()
{
    if(player1Turn){
        player1Time--;
        qDebug() << player1Time;
    }else{
        player2Time--;
        qDebug() << player2Time;
    }

    if (player1Time <= 0)
    {
        label->setText("Player 2 won. reset the game with reset");
        stopTimer();

    }else if(player2Time <=0){
        label->setText("Player 1 won. reset the game with reset");
        stopTimer();
    }


    updateProgressBar();
}
void MainWindow::reset()
{
    pQTimer->stop();
    player1Time = 0;
    player2Time = 0;
    gameTime=0;
    gameRunning=false;
    player1Turn = true;
    player2progressBar->setValue(100);
    player1progressBar->setValue(100);
    label->setText("Choose the game duration and start the game!");
}
