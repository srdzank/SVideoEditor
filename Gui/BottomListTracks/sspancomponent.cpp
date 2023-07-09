#include "sspancomponent.h"

SSpanComponent::SSpanComponent(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    mIsMovingObject = false;
    mIsResizingObject = false;
    mSelectedObjectIndex = -1;
}

void SSpanComponent::setId(int i){
    mId = i;
}

void SSpanComponent::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint mousePos = event->pos();
        mSelectedObjectIndex = -1;

        // Check if any track object is clicked
        for (int i = 0; i < mTrackObjects.size(); i++)
        {
            const QRect& objectRect = mTrackObjects[i].getRect();
            if (objectRect.contains(mousePos))
            {
                mSelectedObjectIndex = i;
                break;
            }
        }

        if (mSelectedObjectIndex == -1)
        {
            // Add a new track object
            QRect newRect(mousePos.x(), 0, 100, height()-2);
            CTrackObject newTrackObject(newRect);
            QColor color = Qt::darkGray;
            switch (currentType) {
            case 0:
                color = Qt::red;
                break;
            case 1:
                color = Qt::blue;
                break;
            case 2:
                color = Qt::yellow;
                break;
            case 3:
                color = Qt::cyan;
                break;
            case 4:
                color = Qt::green;
                break;

            default:
                break;
            }
            newTrackObject.setColor(color);
            newTrackObject.setTypeObject(currentType);
            mTrackObjects.append(newTrackObject);
        }
        else
        {
            // Check if the resize handle is clicked
            const QRect& objectRect = mTrackObjects[mSelectedObjectIndex].getRect();
            int resizeHandleX = objectRect.right();
            int resizeHandleWidth = 20; // Adjust this value as needed
            QRect resizeHandleRect(resizeHandleX-resizeHandleWidth, 0, resizeHandleWidth, height());
            if (resizeHandleRect.contains(mousePos))
            {
                // Start resizing the selected track object
                mIsMovingObject = false;
                mIsResizingObject = true;
            }

            // Check if the resize handle is clicked
            int resizeHandleX1 = objectRect.left();
            //int resizeHandleWidth = 10; // Adjust this value as needed
            QRect resizeHandleRect1(resizeHandleX1, 0, resizeHandleWidth, height());
            if (resizeHandleRect1.contains(mousePos))
            {
                // Start moving the selected track object
                mIsMovingObject = true;
                mIsResizingObject = false;
                mLastMousePos = mousePos;
            }
        }

        update(); // Trigger a repaint of the widget
    }
    else if (event->button() == Qt::RightButton)
    {
        // Delete the selected track object
        if (mSelectedObjectIndex >= 0 && mSelectedObjectIndex < mTrackObjects.size())
        {
            mTrackObjects.remove(mSelectedObjectIndex);
            mSelectedObjectIndex = -1;
            update(); // Trigger a repaint of the widget
        }
    }

    QWidget::mousePressEvent(event);
}

void SSpanComponent::mouseMoveEvent(QMouseEvent* event)
{
    QPoint newPosition = event->pos();
    if (mIsMovingObject && mSelectedObjectIndex >= 0 && mSelectedObjectIndex < mTrackObjects.size())
    {
        QPoint delta = newPosition - mLastMousePos;
        QRect objectRect = mTrackObjects[mSelectedObjectIndex].getRect();
        objectRect.translate(delta);
        mLastMousePos = newPosition;
        mTrackObjects[mSelectedObjectIndex].move(QPoint(newPosition.x(), 0));
        update(); // Trigger a repaint of the widget
    }
    else if (mIsResizingObject && mSelectedObjectIndex >= 0 && mSelectedObjectIndex < mTrackObjects.size())
    {
        QRect objectRect = mTrackObjects[mSelectedObjectIndex].getRect();
        QSize newSize(newPosition.x() - objectRect.left(), height()-2);
        objectRect.setSize(newSize);
        mTrackObjects[mSelectedObjectIndex].resize(newSize);
        update(); // Trigger a repaint of the widget
    }
    else
    {
        // Check if the mouse is over a track object
        for (int i = 0; i < mTrackObjects.size(); i++)
        {
            const QRect& objectRect = mTrackObjects[i].getRect();
            int resizeHandleX = objectRect.right();
            int resizeHandleWidth = 10; // Adjust this value as needed
            QRect resizeHandleRect(resizeHandleX-resizeHandleWidth, 0, resizeHandleWidth, height());
            if (resizeHandleRect.contains(newPosition)){
                setCursor(Qt::SizeHorCursor);
                break;
            }
            else
            {
            int resizeHandleX1 = objectRect.left();
            //int resizeHandleWidth = 10; // Adjust this value as needed
            QRect resizeHandleRect1(resizeHandleX1, 0, resizeHandleWidth, height());
            if (resizeHandleRect1.contains(newPosition)){
                setCursor(Qt::OpenHandCursor);
                break;
            }
            else {
                setCursor(Qt::ArrowCursor);
            }
            }
        }
    }
    QWidget::mouseMoveEvent(event);
}


void SSpanComponent::mouseReleaseEvent(QMouseEvent* event)
{
    mIsMovingObject = false;
    mIsResizingObject = false;
    QWidget::mouseReleaseEvent(event);
}

void SSpanComponent::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // Paint all the track objects
    for (const CTrackObject& trackObject : mTrackObjects)
    {
        trackObject.paint(&painter);
    }

    QWidget::paintEvent(event);
}

int SSpanComponent::getTrackObjectByFrameID(int id) const {
    int idx = -1;
    for(int i = 0; i < mTrackObjects.size(); i++){
        if(mTrackObjects.at(i).getRect().contains(id, 10)){
            idx = mTrackObjects.at(i).getTypeObject();
            break;
        }
    }
    return idx;
}
