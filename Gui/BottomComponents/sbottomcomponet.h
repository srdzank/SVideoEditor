
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
class InterfaceProduct {
public:
    virtual void operation() = 0;
    virtual QWidget* getSpan() = 0;
};

// Concrete product classes
class CComponentButtonA : public InterfaceProduct {
public:
    CComponentButtonA(QWidget* parent){
        mParent = parent;
    }
    ~CComponentButtonA();
    void operation() override {
        span = new CBaseComponent(mParent);
        span->setGeometry(10, 10, 30, 30);
        span->setId(0);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    CBaseComponent *span;
};

class CComponentButtonB : public InterfaceProduct {
public:
    CComponentButtonB(QWidget* parent){
        mParent = parent;
    }
    ~CComponentButtonB();
    void operation() override {
        span = new CBaseComponent(mParent);
        span->setGeometry(60, 10, 30, 30);
        span->setId(1);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    CBaseComponent *span;
};

class CComponentButtonC : public InterfaceProduct {
public:
    CComponentButtonC(QWidget* parent){
        mParent = parent;
    }
    ~CComponentButtonC();
    void operation() override {
        span = new CBaseComponent(mParent);
        span->setGeometry(110, 10, 30, 30);
        span->setId(2);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    CBaseComponent *span;
};

class CComponentButtonD : public InterfaceProduct {
public:
    CComponentButtonD(QWidget* parent){
        mParent = parent;
    }
    ~CComponentButtonD();
    void operation() override {
        span = new CBaseComponent(mParent);
        span->setGeometry(160, 10, 30, 30);
        span->setId(3);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    CBaseComponent *span;
};

class CComponentButtonE : public InterfaceProduct {
public:
    CComponentButtonE(QWidget* parent){
        mParent = parent;
    }
    ~CComponentButtonE();
    void operation() override {
        span = new CBaseComponent(mParent);
        span->setGeometry(210, 10, 30, 30);
        span->setId(4);
        span->show();
    }

    QWidget* getSpan() override {
        return span;
    }

private:
    QWidget* mParent;
    CBaseComponent *span;
};

// Factory class
class CFactory {
public:
    // Factory method
    static InterfaceProduct* createCustomComponent(char productType, QWidget *parent) {
        InterfaceProduct* product = nullptr;
        switch (productType) {
        case 'A':
            product = new CComponentButtonA(parent);
            break;
        case 'B':
            product = new CComponentButtonB(parent);
            break;
        case 'C':
            product = new CComponentButtonC(parent);
            break;
        case 'D':
            product = new CComponentButtonD(parent);
            break;
        case 'E':
            product = new CComponentButtonE(parent);
            break;

        default:
            cout << "Invalid product type." << endl;
            break;
        }
        return product;
    }
};

class CBottomComponent : public QWidget
{
    Q_OBJECT
public:
    explicit CBottomComponent(QWidget *parent = nullptr);
    ~CBottomComponent();
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
    CBaseComponent *span;
    InterfaceProduct* productA;
    InterfaceProduct* productB;
    InterfaceProduct* productC;
    InterfaceProduct* productD;
    InterfaceProduct* productE;

    Subject *mSubj;
};

#endif // SBOTTOMCOMPONET_H
