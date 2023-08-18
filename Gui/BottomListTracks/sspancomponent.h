#ifndef SSPANCOMPONENT_H
#define SSPANCOMPONENT_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QMouseEvent>


class CTrackObject
{
public:
    CTrackObject(const QRect& rect) : mRect(rect) {}

    void move(const QPoint& newPosition)
    {
        mRect.moveTo(newPosition);
    }

    void resize(const QSize& newSize)
    {
        mRect.setSize(newSize);
    }

    void paint(QPainter* painter) const
    {
        painter->setBrush(color);
        painter->drawRect(mRect);
    }

    QRect getRect() const
    {
        return mRect;
    }
    void setColor(QColor eColor){
        color = eColor;
    }
    void setTypeObject(int typeObj){
        mTypeObj = typeObj;
    }
    int getTypeObject() const{
        return mTypeObj;
    }
private:
    QRect mRect;
    QColor color;
    int mTypeObj;
};

class CTrackItem : public QWidget
{
    Q_OBJECT
public:
    explicit CTrackItem(QWidget *parent = nullptr);

    void setId(int i);
    void setCurrentType(int eCurrentType){
        currentType = eCurrentType;
    }
    int getTrackObjectByFrameID(int i) const;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;


private:
    QVector<CTrackObject> mTrackObjects;
    bool mIsMovingObject;
    bool mIsResizingObject;
    int mSelectedObjectIndex;
    QPoint mLastMousePos;
    int mId;
    int currentType;
};



#endif // SSPANCOMPONENT_H
