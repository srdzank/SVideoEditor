
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
#include "CollaborationHub/cbottomsubject.h"
#include "cframeclass.h"
#include <QThread>
#include <QTimer>

class CCustomItemDelegate : public QStyledItemDelegate {
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

class CCustomListWidget : public QListWidget
{
public:
    CCustomListWidget(QWidget *parent = nullptr) : QListWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override
    {
        // Perform the default painting
        QListWidget::paintEvent(event);
    }
};

class CAudioVideoComponent : public QWidget {
    Q_OBJECT
public:
    CAudioVideoComponent(QWidget *parent = nullptr);
    ~CAudioVideoComponent();
    void Init();
    void attachToObserver(CConcreteObserver * eObser);
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
    CCustomListWidget *trackList;
    QLineEdit *trackInput;
    CCustomItemDelegate* itemDelegate;
    QVector<QListWidgetItem*> listOfWidgetItem;
    QVector<CTrackItem*> listOfTracks;
    CConcreteObserver * mObser;
    int currentType;
    CTransparentWidget *transWidg;
    QTimer shotTimer;
    double playPosition;
};

#endif // SAVCOMPONENT_H
