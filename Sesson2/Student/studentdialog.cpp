#include "studentdialog.h"
#include "ui_studentdialog.h"
#include <QString>
StudentDialog::StudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("Thông tin sinh viên"));
}

StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::showStudent(Student *student)
{
    ui->name->setText(student->getName());
    ui->dob->setText(student->getDOB());
    ui->className->setText(student->getClass());

    m_Student = student;

    show();
}

void StudentDialog::on_pushButton_released()
{
    m_Student->setName(ui->name->text());
    m_Student->setDOB(ui->dob->text());
    m_Student->setClass(ui->className->text());

    hide();
}

