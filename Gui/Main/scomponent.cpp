
#include "scomponent.h"

CMainComponent::CMainComponent(QWidget *parent): QWidget{parent}{
}

void CMainComponent::closeEvent(QCloseEvent* event){
    // Handle close event
    // ...

    // Let the base class handle the event as well
    QWidget::closeEvent(event);
}

void CMainComponent::keyPressEvent(QKeyEvent* event){
    // Handle key press event
    // ...

    // Let the base class handle the event as well
    QWidget::keyPressEvent(event);
}

void CMainComponent::mousePressEvent(QMouseEvent* event){
    // Handle mouse press event
    // ...

    // Let the base class handle the event as well
    QWidget::mousePressEvent(event);
}

void CMainComponent::paintEvent(QPaintEvent* event){
    // Perform custom drawing here
    QPainter painter(this);

    // Set the pen and brush properties for drawing
    painter.setPen(Qt::red);
    painter.setBrush(Qt::darkGray);

    // Example: Draw a rectangle
    painter.drawRect(0, 0, this->width(), this->height());

    // Example: Draw text
    painter.setPen(Qt::blue);
    painter.drawText(100, 100, "Hello, Qt!");

    // Let the base class handle the event as well
    QWidget::paintEvent(event);
}
