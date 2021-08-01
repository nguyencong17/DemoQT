#include "student.h"
#include <QListWidgetItem>

Student::Student(QString name) : QListWidgetItem(name)
{

}

Student::Student(QString name, QString dob, QString className):QListWidgetItem(name),m_DOB(dob),m_Class(className)
{

}
Student::Student()
{

}

void Student::setName(QString name)
{
    QListWidgetItem::setText(name);
}

void Student::setDOB(QString dob)
{
    m_DOB = dob;
}

void Student::setClass(QString className)
{
    m_Class = className;
}

QString Student::getName()
{
    return QListWidgetItem::text();
}

QString Student::getDOB()
{
    return m_DOB;
}

QString Student::getClass()
{
    return m_Class;
}

