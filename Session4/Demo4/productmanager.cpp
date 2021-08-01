#include "productmanager.h"
#include <QDebug>
#include <product.h>
ProductManager::ProductManager(QObject *parent) : QObject(parent)
{

}

void ProductManager::addProduct(Product * product)
{
    m_Products.push_back(product);
    qDebug() << "Đã add product";
}
