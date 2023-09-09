
#ifndef SCOMPONENT_H
#define SCOMPONENT_H


#include <QWidget>
#include <QPainter>

class CMainComponent : public QWidget
{
    Q_OBJECT
public:
    explicit CMainComponent(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

public slots:

signals:

};

#endif // SCOMPONENT_H

