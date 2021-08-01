#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digit_pressed();
    void on_btnDecimal_released();
    void unary_operator_pressed();
    void on_btnClear_released();
    void on_btnEquals_released();
    void binary_operator_pressed();
};
#endif // MAINWINDOW_H
