
#include "sbottomcomponet.h"

CBottomComponent::CBottomComponent(QWidget *parent)
    : QWidget{parent}
{
    //Create button 0
    productA = CFactory::createCustomComponent('A', this);
    if (productA){
        productA->operation();
        connect(productA->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 1
    productB = CFactory::createCustomComponent('B', this);
    if (productB){
        productB->operation();
        connect(productB->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 2
    productC = CFactory::createCustomComponent('C', this);
    if (productC){
        productC->operation();
        connect(productC->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 3
    productD = CFactory::createCustomComponent('D', this);
    if (productD){
        productD->operation();
        connect(productD->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 4
    productE = CFactory::createCustomComponent('E', this);
    if (productE){
        productE->operation();
        connect(productE->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

}


void CBottomComponent::ProcClickButton(int id){
    int i = 0;
    i = id;
    if (mSubj){
        mSubj->doSomething(id);
    }
}

CBottomComponent::~CBottomComponent(){
    delete productA;
    delete productB;
    delete productC;
    delete productD;
    delete productE;
}

void CBottomComponent::closeEvent(QCloseEvent* event){
    // Handle close event
    // ...

    // Let the base class handle the event as well
    QWidget::closeEvent(event);
}

void CBottomComponent::keyPressEvent(QKeyEvent* event){
    // Handle key press event
    // ...

    // Let the base class handle the event as well
    QWidget::keyPressEvent(event);
}

void CBottomComponent::mousePressEvent(QMouseEvent* event){
    // Handle mouse press event
    // ...

    // Let the base class handle the event as well
    QWidget::mousePressEvent(event);
}

void CBottomComponent::paintEvent(QPaintEvent* event){
    // Perform custom drawing here
    QPainter painter(this);

    // Set the pen and brush properties for drawing
    painter.setPen(Qt::red);
    painter.setBrush(Qt::blue);

    // Example: Draw a rectangle
    painter.drawRect(0, 0, width(), height());

    // Example: Draw text
    painter.setPen(Qt::blue);
    painter.drawText(10, 10, "Hello, Bottom Qt!");

    // Let the base class handle the event as well
    QWidget::paintEvent(event);
}

