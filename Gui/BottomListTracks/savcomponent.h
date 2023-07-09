
#ifndef SAVCOMPONENT_H
#define SAVCOMPONENT_H

#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollArea>
#include <QWidget>

#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include "sspancomponent.h"
#include "cbottomsubject.h"
#include "cframeclass.h"

class CustomItemDelegate : public QStyledItemDelegate {
public:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        // Call the base class paint function to perform the default painting
        QStyledItemDelegate::paint(painter, option, index);

        // Perform custom painting
        painter->save();

        // Customize the painting of the item here
        painter->drawText(option.rect, Qt::AlignCenter, index.data().toString());

        painter->restore();
    }
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QSize size = QStyledItemDelegate::sizeHint(option, index);
        size.setHeight(50); // Set the desired height for each row
        return size;
    }
};

class CustomListWidget : public QListWidget
{
public:
    CustomListWidget(QWidget *parent = nullptr) : QListWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override
    {
        // Perform the default painting
        QListWidget::paintEvent(event);
    }
};


class SAVComponent : public QWidget {
    Q_OBJECT
public:
    SAVComponent(QWidget *parent = nullptr);
    ~SAVComponent();

    void attachToObserver(ConcreteObserver * eObser);
    CFrameClass getFrameByID(int idFrame);
public slots:
    void handleSignal(int data);
private slots:
    void addTrack();
    void deleteTrack();
    void playTrack();

protected:
    void paintEvent(QPaintEvent* event) override;
private:
    CustomListWidget *trackList;
    QLineEdit *trackInput;
    CustomItemDelegate* itemDelegate;
    QVector<QListWidgetItem*> listOfWidgetItem;
    QVector<SSpanComponent*> listOfSpanComponent;
    ConcreteObserver * mObser;
    int currentType;
};

#endif // SAVCOMPONENT_H
