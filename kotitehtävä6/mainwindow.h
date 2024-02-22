#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>

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

private slots:
    void digitClicked();
    void enterClicked();
    void multiplyClicked();
    void minusClicked();
    void plusClicked();
    void divideClicked();
    void clear();
private:
    Ui::MainWindow *ui;
    int enterCount;
    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
};
#endif // MAINWINDOW_H
