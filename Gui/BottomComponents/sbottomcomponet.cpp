
#include "sbottomcomponet.h"

SBottomComponent::SBottomComponent(QWidget *parent)
    : QWidget{parent}
{
    //Create button 0
    productA = Factory::createProduct('A', this);
    if (productA){
        productA->operation();
        connect(productA->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 1
    productB = Factory::createProduct('B', this);
    if (productB){
        productB->operation();
        connect(productB->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 2
    productC = Factory::createProduct('C', this);
    if (productC){
        productC->operation();
        connect(productC->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 3
    productC = Factory::createProduct('D', this);
    if (productC){
        productC->operation();
        connect(productC->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

    //Create button 4
    productC = Factory::createProduct('E', this);
    if (productC){
        productC->operation();
        connect(productC->getSpan(), SIGNAL(clickButton(int)), this, SLOT(ProcClickButton(int)));
    }

}


void SBottomComponent::ProcClickButton(int id){
    int i = 0;
    i = id;
    if (mSubj){
        mSubj->doSomething(id);
    }
}

SBottomComponent::~SBottomComponent(){
    delete productA;
    delete productB;
    delete productC;
}

void SBottomComponent::closeEvent(QCloseEvent* event){
    // Handle close event
    // ...

    // Let the base class handle the event as well
    QWidget::closeEvent(event);
}

void SBottomComponent::keyPressEvent(QKeyEvent* event){
    // Handle key press event
    // ...

    // Let the base class handle the event as well
    QWidget::keyPressEvent(event);
}

void SBottomComponent::mousePressEvent(QMouseEvent* event){
    // Handle mouse press event
    // ...

    // Let the base class handle the event as well
    QWidget::mousePressEvent(event);
}

void SBottomComponent::paintEvent(QPaintEvent* event){
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

