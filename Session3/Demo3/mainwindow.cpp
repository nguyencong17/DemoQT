#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("test.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        ui->label->setText("Error read file !");
        return;
    }

    QTextStream textStream(&file);

    textStream.setCodec("UTF-8");

    QString s;

    s = textStream.readLine();

    ui->label->setText(s);

    /*Demo QMessage Box*/
    QMessageBox msgBox(QMessageBox::Question, "Quit" , "Do you want quit ?", QMessageBox::Yes | QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes) exit(1);

    /*Demo Progess Bar*/
    ui->progressBar->setValue(12);
    /*Demo QDir (Thao tác với thư mục)*/
    QDir dir("C:\\Users\\Admin\\Desktop\\QTDemo\\Session3\\build-Demo3-Desktop_Qt_5_12_11_MSVC2015_64bit-Debug");

    // kiểm tra thu mục tồn tại hay không

    if(dir.exists()){
        ui->label->setText("Folder Exist");
    }else{
        ui->label->setText("Folder does not exist ");
    }

    // Tạo thư mục bằng QDir
    dir.mkdir("xxx");
    // Tạo thư mục cha và con bằng mkpath
    dir.mkpath("fl1/fl2");
    //Liệt ê ổ đĩa của máy tính
    QFileInfoList list = dir.drives();

    QString s2;

    for(int i=0; i < list.size(); ++i)
    {
        s2.append(list.at(i).absolutePath() + "\n");
    }
    ui->editText->setText(s2);


    /*Demo QFile*/

    QFile qFile("C:\\test");
    // Đổi tên thư mục
    qFile.rename("T");
    //Xóa thư mục
    //qFile.remove();


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Demo QFileDialog*/
void MainWindow::on_pushButton_released()
{
    QString s =  QFileDialog::getOpenFileName(this, "Open File", QString(), "*.txt" );
    ui->lineEdit->setText(s);
}


