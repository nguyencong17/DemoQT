#ifndef MYSTUDENT_H
#define MYSTUDENT_H
#include <QWidget>
#include <QMainWindow>
#include <QListWidgetItem>
#include "student.h"
#include <QString>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class mystudent; }
QT_END_NAMESPACE

class QListWidgetItem;
class StudentDialog;

class mystudent : public QWidget
{
    Q_OBJECT

public:
    mystudent(QWidget *parent = nullptr);
    ~mystudent();

    void AddStudent(Student* student);
    void AddStudent(QString name);
    void AddStudent(QString name, QString dob, QString className);

    void RemoveStudent(Student* student);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_btnRemove_clicked();

    void on_btnAdd_clicked();

private:
    Ui::mystudent *ui;
    QVector<Student*> m_Student;
    StudentDialog* m_StudentDialog;
};
#endif // MYSTUDENT_H
