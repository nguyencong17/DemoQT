#include "mainwindow.h"
#include <product.h>
#include <productmanager.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Product* product = new Product();
    ProductManager* msg = new ProductManager();

    QObject::connect(product,SIGNAL(newProduct(Product*)),msg,SLOT(addProduct(Product*)));

    product->input();

    w.show();
    return a.exec();
}
