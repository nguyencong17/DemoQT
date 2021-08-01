#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = nullptr);
    void input();
signals:
    void newProduct(Product*);

};

#endif // PRODUCT_H
