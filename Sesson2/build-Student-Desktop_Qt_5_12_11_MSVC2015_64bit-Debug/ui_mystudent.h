/********************************************************************************
** Form generated from reading UI file 'mystudent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTUDENT_H
#define UI_MYSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mystudent
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QListWidget *listWidget;

    void setupUi(QWidget *mystudent)
    {
        if (mystudent->objectName().isEmpty())
            mystudent->setObjectName(QString::fromUtf8("mystudent"));
        mystudent->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(mystudent);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(mystudent);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnAdd = new QPushButton(mystudent);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout_2->addWidget(btnAdd);

        btnRemove = new QPushButton(mystudent);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        horizontalLayout_2->addWidget(btnRemove);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(mystudent);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(mystudent);

        QMetaObject::connectSlotsByName(mystudent);
    } // setupUi

    void retranslateUi(QWidget *mystudent)
    {
        mystudent->setWindowTitle(QApplication::translate("mystudent", "mystudent", nullptr));
        label->setText(QApplication::translate("mystudent", "Ch\306\260\306\241ng Tr\303\254nh Qu\341\272\243n L\303\275 Sinh Vi\303\252n", nullptr));
        btnAdd->setText(QApplication::translate("mystudent", "Th\303\252m sinh vi\303\252n", nullptr));
        btnRemove->setText(QApplication::translate("mystudent", "X\303\263a sinh vi\303\252n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mystudent: public Ui_mystudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTUDENT_H
