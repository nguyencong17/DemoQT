#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

double firstNum;
bool userTypingSecondNumber = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->btn9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->btnMinus,SIGNAL(released()),this,SLOT(unary_operator_pressed()));
    connect(ui->btnPercent,SIGNAL(released()),this,SLOT(unary_operator_pressed()));

    connect(ui->btnAdd,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    connect(ui->btnSubtract,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    connect(ui->btnMulti,SIGNAL(released()),this,SLOT(binary_operator_pressed()));
    connect(ui->btnDivide,SIGNAL(released()),this,SLOT(binary_operator_pressed()));

    ui->btnAdd->setCheckable(true);
    ui->btnSubtract->setCheckable(true);
    ui->btnMulti->setCheckable(true);
    ui->btnDivide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton* button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->btnAdd->isChecked() || ui->btnSubtract->isChecked() || ui->btnMulti->isChecked() || ui->btnDivide->isChecked()) && (!userTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userTypingSecondNumber = true;
    }else
    {
        labelNumber = (ui->label->text() + button->text()).toDouble();
    }

    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
}


void MainWindow::on_btnDecimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operator_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "+/-"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

    if(button->text() == "%"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}


void MainWindow::on_btnClear_released()
{
    ui->btnAdd->setChecked(false);
    ui->btnSubtract->setChecked(false);
    ui->btnMulti->setChecked(false);
    ui->btnDivide->setChecked(false);

    userTypingSecondNumber = false;

    QString newLabel = "0";
    ui->label->setText(newLabel);
}


void MainWindow::on_btnEquals_released()
{
    QString newLabel;
    double labelNumber, secondNum;

    secondNum = ui->label->text().toDouble();

    if(ui->btnAdd->isChecked()){
        labelNumber=firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btnAdd->setChecked(false);
    }
    else if(ui->btnSubtract->isChecked()){
        labelNumber=firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btnSubtract->setChecked(false);
    }
    else if(ui->btnMulti->isChecked()){
        labelNumber=firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btnMulti->setChecked(false);
    }
    else if(ui->btnDivide->isChecked()){
        labelNumber=firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->btnDivide->setChecked(false);
    }
    userTypingSecondNumber = false;

}

void MainWindow::binary_operator_pressed()
{
    QPushButton* button = (QPushButton*) sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}

