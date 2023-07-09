#include "component_item.h"

SComponentA::SComponentA(QWidget *parent) : QWidget(parent)
{
    isHovered = false;
    setMouseTracking(true);
}

void SComponentA::setId(int i){
    mId = i;
}

void SComponentA::mousePressEvent(QMouseEvent* event)
{
    emit clickButton(mId);
    QWidget::mousePressEvent(event);
}

void SComponentA::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mouseMoveEvent(event);
}


void SComponentA::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mouseReleaseEvent(event);
}


void SComponentA::enterEvent(QEvent* event) {
    isHovered = true;
    update(); // Trigger repaint to change color
    QWidget::enterEvent(event);
}

void SComponentA::leaveEvent(QEvent* event) {
    isHovered = false;
    update(); // Trigger repaint to change color
    QWidget::leaveEvent(event);
}


void SComponentA::paintEvent(QPaintEvent* event)
{
    // Perform custom drawing here
    QPainter painter(this);

    // Set the pen and brush properties for drawing
    QColor color = isHovered ? Qt::red : Qt::green;
    painter.setPen(Qt::red);
    painter.setBrush(color);

    // Example: Draw a rectangle
    painter.drawRect(0, 0, this->width(), this->height());

    // Let the base class handle the event as well
    QWidget::paintEvent(event);
}
