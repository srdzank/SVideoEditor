
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include "Gui/Main/scomponent.h"
#include "Gui/BottomComponents/sbottomcomponet.h"
#include "Gui/BottomListTracks/savcomponent.h"
#include "cbottomsubject.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void resizeEvent(QResizeEvent *event) override;



private:
    Ui::MainWindow *ui;
    SComponent *comp;
    SBottomComponent *bcomp;
    SAVComponent *avcomp;
    Subject *subj;
    ConcreteObserver* observer1;
};

#endif // MAINWINDOW_H
