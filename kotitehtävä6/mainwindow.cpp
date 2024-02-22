#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i <= 9; ++i) {
        QString buttonName = "pushButton_" + QString::number(i);
        QPushButton *button = findChild<QPushButton *>(buttonName);
        if (button) {
            connect(button, &QPushButton::clicked, this, &MainWindow::digitClicked);
        } else {
            qDebug() << "Button" << buttonName << "not found!";
        }
    }


    QPushButton *enter = findChild<QPushButton *>("enter");
    connect(enter, &QPushButton::clicked,this,&MainWindow::enterClicked);

    QPushButton *plus = findChild<QPushButton *>("plus");
    connect(plus, &QPushButton::clicked,this,&MainWindow::plusClicked);

    QPushButton *minus = findChild<QPushButton *>("minus");
    connect(minus, &QPushButton::clicked,this,&MainWindow::minusClicked);

    QPushButton *multiply = findChild<QPushButton *>("multiply");
    connect(multiply, &QPushButton::clicked,this,&MainWindow::multiplyClicked);

    QPushButton *divide= findChild<QPushButton *>("divide");
    connect(divide, &QPushButton::clicked,this,&MainWindow::divideClicked);

    QPushButton *clear = findChild<QPushButton *>("clear");
    connect(clear, &QPushButton::clicked,this,&MainWindow::clear);

   line1 = findChild<QLineEdit *>("lineEdit");
   line2 = findChild<QLineEdit *>("lineEdit_2");
   line3 = findChild<QLineEdit *>("lineEdit_3");
   enterCount=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString digit = clickedButton->text();


    if(enterCount < 1){
        QString currentText = this->line1->text();
        currentText += digit;
        line1->setText(currentText);
    }else if(enterCount == 1){
        QString currentText = this->line2->text();
        currentText += digit;
        line2->setText(currentText);
    }





    qDebug() << digit;
}
void MainWindow::enterClicked(){
    qDebug() << enterCount;
    if(enterCount < 1 && this->line1->text() != ""){
      enterCount++;
    }

}

void MainWindow::minusClicked(){
    QString text1 = this->line1->text();
    QString text2 = this->line2->text();
    if(enterCount == 1 && text2 != ""){
        enterCount++;
        double number1 = text1.toDouble();
        double number2 = text2.toDouble();
        double result = number1 - number2;
        this->line3->setText(QString::number(result));
        qDebug() << "Result: " << result;
    }

}

void MainWindow::plusClicked(){
    QString text1 = this->line1->text();
    QString text2 = this->line2->text();
    if(enterCount == 1 && text2 != ""){
        enterCount++;
        double number1 = text1.toDouble();
        double number2 = text2.toDouble();
        double result = number1 + number2;
        this->line3->setText(QString::number(result));
        qDebug() << "Result: " << result;
    }

}

void MainWindow::divideClicked(){
    QString text1 = this->line1->text();
    QString text2 = this->line2->text();
    if(enterCount == 1 && text2 != ""){
        enterCount++;
        double number1 = text1.toDouble();
        double number2 = text2.toDouble();
        if (number2 != 0) {
            double result = number1 / number2;
           this->line3->setText(QString::number(result));
            qDebug() << "Result: " << result;
        } else {
            qDebug() << "Error: Division by zero!";
        }
    }
}
void MainWindow::clear(){

    this->line1->setText("");
    this->line2->setText("");
    this->line3->setText("");
    enterCount=0;

}

void MainWindow::multiplyClicked(){
    QString text1 = this->line1->text();
    QString text2 = this->line2->text();
    if(enterCount == 1 && text2 != ""){
        enterCount++;
        double number1 = text1.toDouble();
        double number2 = text2.toDouble();
        double result = number1 * number2;
        this->line3->setText(QString::number(result));
        qDebug() << "Result: " << result;
    }
}






