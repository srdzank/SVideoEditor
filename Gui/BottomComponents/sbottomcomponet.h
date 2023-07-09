
#ifndef SBOTTOMCOMPONET_H
#define SBOTTOMCOMPONET_H


#include <QWidget>
#include <QPainter>
#include "component_item.h"
#include <vector>
#include <iostream>
#include "cbottomsubject.h"

using namespace std;

// Abstract base class
class Product {
public:
    virtual void operation() = 0;
    virtual QWidget* getSpan() = 0;
};

// Concrete product classes
class ConcreteProductA : public Product {
public:
    ConcreteProductA(QWidget* parent){
        mParent = parent;
    }
    ~ConcreteProductA();
    void operation() override {
        span = new SComponentA(mParent);
        span->setGeometry(10, 10, 30, 30);
        span->setId(0);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    SComponentA *span;
};

class ConcreteProductB : public Product {
public:
    ConcreteProductB(QWidget* parent){
        mParent = parent;
    }
    ~ConcreteProductB();
    void operation() override {
        span = new SComponentA(mParent);
        span->setGeometry(60, 10, 30, 30);
        span->setId(1);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    SComponentA *span;
};

class ConcreteProductC : public Product {
public:
    ConcreteProductC(QWidget* parent){
        mParent = parent;
    }
    ~ConcreteProductC();
    void operation() override {
        span = new SComponentA(mParent);
        span->setGeometry(110, 10, 30, 30);
        span->setId(2);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    SComponentA *span;
};

class ConcreteProductD : public Product {
public:
    ConcreteProductD(QWidget* parent){
        mParent = parent;
    }
    ~ConcreteProductD();
    void operation() override {
        span = new SComponentA(mParent);
        span->setGeometry(160, 10, 30, 30);
        span->setId(3);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    SComponentA *span;
};

class ConcreteProductE : public Product {
public:
    ConcreteProductE(QWidget* parent){
        mParent = parent;
    }
    ~ConcreteProductE();
    void operation() override {
        span = new SComponentA(mParent);
        span->setGeometry(210, 10, 30, 30);
        span->setId(4);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    SComponentA *span;
};





// Factory class
class Factory {
public:
    // Factory method
    static Product* createProduct(char productType, QWidget *parent) {
        Product* product = nullptr;
        switch (productType) {
        case 'A':
            product = new ConcreteProductA(parent);
            break;
        case 'B':
            product = new ConcreteProductB(parent);
            break;
        case 'C':
            product = new ConcreteProductC(parent);
            break;
        case 'D':
            product = new ConcreteProductD(parent);
            break;
        case 'E':
            product = new ConcreteProductE(parent);
            break;

        default:
            cout << "Invalid product type." << endl;
            break;
        }
        return product;
    }
};

class SBottomComponent : public QWidget
{
    Q_OBJECT
public:
    explicit SBottomComponent(QWidget *parent = nullptr);
    ~SBottomComponent();
    void attachToSubject(Subject *eSubj){
        mSubj = eSubj;
    }

protected:
    void closeEvent(QCloseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

public slots:
    void ProcClickButton(int);

signals:
    void sigUpdate();
private:
    SComponentA *span;
    Product* productA;
    Product* productB;
    Product* productC;
    Product* productD;
    Product* productE;

    Subject *mSubj;
};

#endif // SBOTTOMCOMPONET_H
