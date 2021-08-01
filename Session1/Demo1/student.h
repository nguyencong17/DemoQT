#ifndef STUDENT_H
#define STUDENT_H
#include <QListWidgetItem>
#include <QString>
class Student : public QListWidgetItem
{
public:
    Student();
    Student(QString name);
    Student(QString name, QString dob, QString className );

    void setName(QString name);
    void setDOB(QString dob);
    void setClass(QString className);

    QString getName();
    QString getDOB();
    QString getClass();
private:
    QString m_DOB;
    QString m_Class;
};

#endif // STUDENT_H
