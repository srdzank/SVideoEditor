#ifndef SComponentA_H
#define SComponentA_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QMouseEvent>



class CBaseComponent : public QWidget
{
    Q_OBJECT
public:
    explicit CBaseComponent(QWidget *parent = nullptr);

    void setId(int i);
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;


signals:
    void clickButton(int);
private:
    bool mIsMovingObject;
    bool mIsResizingObject;
    int mSelectedObjectIndex;
    QPoint mLastMousePos;
    int mId;
    bool isHovered;
};



#endif // SComponentA_H
