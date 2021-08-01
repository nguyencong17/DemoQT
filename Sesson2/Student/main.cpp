#include "mystudent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mystudent w;
    w.AddStudent("Nguyen Duy Cong", "17/07/1999", "D17CQPT01");
    w.AddStudent("Nguyen Duy Cong", "17/07/1999", "D17CQPT01");
    w.AddStudent("Nguyen Duy Cong", "17/07/1999", "D17CQPT01");
    w.AddStudent("Nguyen Duy Cong", "17/07/1999", "D17CQPT01");
    w.AddStudent("Nguyen Duy Cong", "17/07/1999", "D17CQPT01");
    w.show();
    return a.exec();
}
