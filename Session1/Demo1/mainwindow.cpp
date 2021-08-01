#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include <QListWidgetItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Student* student = new Student();
    student->setName("Nguyen Duy Cong");
    student->setDOB("17/07/1999");
    student->setClass("D17CQPT01");
    ui->listWidget->addItem((QListWidgetItem*) student);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->text->setText("Xin chào công đến với QT");
    // Demo QString
    QString s1 = "Hello";
    QString s2 = "world";
    s1.append(s2);
    int i = s1.compare(s2);
    ui->text->setText(s1);
    //Demo QMap
    QMap<int , QString> map;
    map.insert(1,"Nguyen Van A");
    map.insert(2,"Nguyen Van B");
    map.insert(3,"Nguyen Van C");
    map.insert(4,"Nguyen Van D");

    QString s = map[3];
    ui->text->setText(s);

    //Demo QVector
    QVector<QString> v;
    v.push_back("Nguyen Van A");
    v.push_back("Nguyen Van B");
    ui->text->setText("In Vector have " + QString::number(v.size()) + " people");


}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Student* student = (Student*) item;
    ui->studentName->setText(student->getName());
    ui->studentDOB->setText(student->getDOB());
    ui->studentClassName->setText(student->getClass());
}

