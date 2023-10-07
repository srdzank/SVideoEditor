#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    CCustomXML *xml = new CCustomXML();
    xml->procSaveXML("books.xml");
    delete xml;

    ui->setupUi(this);
    connect(this, &MainWindow::resizeEvent, this, &MainWindow::resizeEvent);

    // create main component
    comp = new CMainComponent(this);
    comp->setGeometry(20, 10, this->width()-200, this->height()-370);
    comp->show();

    // create bottom component
    bcomp = new CBottomComponent(this);
    bcomp->setGeometry(0, this->height()-50, this->width(), 50 );
    bcomp->show();

    // create subject and attach subject to bottom component
    subj = new CSubject();
    bcomp->attachToSubject(subj);

    // create AV Tracks
    avcomp = new CAudioVideoComponent(this);
    avcomp->setGeometry(0, this->height()-350, this->width(), 300);
    avcomp->show();

    // create observer and ataach AVTracks to observer
    observer1 = new CConcreteObserver();
    avcomp->attachToObserver(observer1);


    // finnaly need to connect obserser to subj
    //to receive commands from bottom comp to av tracks component
    subj->addObserver(observer1);
    CCustomXML *xml1 = new CCustomXML();
    xml1->procLoadXML("books.xml");
    delete xml1;
}

MainWindow::~MainWindow(){
    delete ui;
    delete comp;
    delete bcomp;
    delete subj;
    delete observer1;
}


void MainWindow::on_pushButton_clicked(){
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QMainWindow::resizeEvent(event);

    // Update the geometry of the components based on the new size of the main window
    comp->setGeometry(20, 30, this->width()*0.8, this->height()-390);
    bcomp->setGeometry(0, this->height() - 50, this->width(), 50);
    avcomp->setGeometry(0, this->height() - 350, this->width(), 300);
    avcomp->Init();
}

// Menu  - File Open -action
void MainWindow::on_actionOpen_triggered(){
}

// Menu  - New File -action
void MainWindow::on_actionNew_File_triggered(){
}


