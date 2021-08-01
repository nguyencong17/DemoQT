#include "mystudent.h"
#include "ui_mystudent.h"
#include "student.h"
#include "studentdialog.h"
mystudent::mystudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mystudent)
{
    ui->setupUi(this);
    m_StudentDialog = new StudentDialog();
}


mystudent::~mystudent()
{
    for(int i = 0 ; i < m_Student.size() ; ++i )
    {
        RemoveStudent(m_Student[i]);
    }
    delete ui;
    delete m_StudentDialog;
}

void mystudent::AddStudent(Student *student)
{
    ui->listWidget->addItem((QListWidgetItem*) student);
    m_Student.push_back(student);
}

void mystudent::AddStudent(QString name)
{
    Student* student = new Student(name);
    AddStudent(student);
}

void mystudent::AddStudent(QString name, QString dob, QString className)
{
    Student* student = new Student(name,dob,className);
    AddStudent(student);
}

void mystudent::RemoveStudent(Student *student)
{
    ui->listWidget->removeItemWidget((QListWidgetItem*) student);
    for(int i = 0 ; i < m_Student.size() ; ++i )
    {
        if(m_Student[i] == student){
            m_Student.remove(i);
            delete student;
        }
    }
}


void mystudent::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
//    Student* student = (Student*) item;
//    ui->studentName->setText(student->getName());
//    ui->studentDOB->setText(student->getDOB());
//    ui->studentClassName->setText(student->getClass());
    m_StudentDialog->showStudent((Student*) item);
}


void mystudent::on_btnRemove_clicked()
{
    RemoveStudent((Student*) ui->listWidget->currentItem());
}


void mystudent::on_btnAdd_clicked()
{
    AddStudent("Nguyen Van A");
}

