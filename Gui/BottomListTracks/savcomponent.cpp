
#include "savcomponent.h"


CAudioVideoComponent::CAudioVideoComponent(QWidget *parent)
    : QWidget(parent)
{
    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // Create a widget to hold the scroll area contents
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);

    // Create a list widget to display the audio tracks
    trackList = new CCustomListWidget();
    itemDelegate = new CCustomItemDelegate();
    trackList->setItemDelegate(itemDelegate);


    QHBoxLayout *buttonLayout = new QHBoxLayout;

    // Create a line edit widget for entering track information
    trackInput = new QLineEdit();

    // Create a button for adding tracks
    QPushButton *addButton = new QPushButton("Add Track");

    // Connect the "Add Track" button to add a track to the list
    connect(addButton, &QPushButton::clicked, this, &CAudioVideoComponent::addTrack);


    // Create a button for deleting tracks
    QPushButton *deleteButton = new QPushButton("Delete Track");
    connect(deleteButton, &QPushButton::clicked, this, &CAudioVideoComponent::deleteTrack);

    // Create a button for deleting tracks
    QPushButton *playButton = new QPushButton("Play Track");
    connect(playButton, &QPushButton::clicked, this, &CAudioVideoComponent::playTrack);


    // Add the list widget, input field, and button to the scroll area widget
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(trackInput);
    scrollLayout->addWidget(trackList);


    // Set the scroll area widget as the content widget of the scroll area
    scrollArea->setWidget(scrollContent);

    // Create a layout to organize the scroll area
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(buttonLayout);
    layout->addWidget(scrollArea);
}

CAudioVideoComponent::~CAudioVideoComponent(){
}


void CAudioVideoComponent::attachToObserver(ConcreteObserver * eObser){
    mObser = eObser;
    connect(mObser, SIGNAL(someSignal(int)), this, SLOT(handleSignal(int)));
}
void CAudioVideoComponent::handleSignal(int data){
    currentType = data;
    for (int i = 0; i < listOfTracks.size(); i++)
    {
        listOfTracks.at(i)->setCurrentType(data);
    }
}

CFrameClass CAudioVideoComponent::getFrameByID(int idFrame){
    CFrameClass frame;
    for (int i = 0; i < listOfTracks.size(); i++)
    {
        frame.Id = i;
        int idBlock = listOfTracks.at(i)->getTrackObjectByFrameID(idFrame);
        frame.listOfObj.push_back(idBlock);
    }
    return frame;
}


void CAudioVideoComponent::addTrack() {
    QString trackName = trackInput->text();
    QListWidgetItem *item = new QListWidgetItem();
    CTrackItem *sobject = new CTrackItem(this);
    trackList->addItem(item);
    trackList->setItemWidget(item, sobject);
    listOfWidgetItem.push_back(item);
    listOfTracks.push_back(sobject);
    trackInput->clear();
    trackList->show();

}


void CAudioVideoComponent::deleteTrack() {
    QListWidgetItem *selectedItem = trackList->currentItem();
    if (selectedItem) {
        int selectedIndex = trackList->row(selectedItem);

        // Remove the item from the list widget
        trackList->takeItem(selectedIndex);

        // Remove the corresponding widget from the span components list
        if (selectedIndex < listOfTracks.size()) {
            CTrackItem *spanComponent = listOfTracks.at(selectedIndex);
            listOfTracks.removeAt(selectedIndex);
            delete spanComponent;
        }

        // Remove the corresponding item from the list of items
        if (selectedIndex < listOfWidgetItem.size()) {
            QListWidgetItem *item = listOfWidgetItem.at(selectedIndex);
            listOfWidgetItem.removeAt(selectedIndex);
            delete item;
        }
    }
}


void CAudioVideoComponent::playTrack() {
    for (int i= 0; i < 2000; i+=50){
    CFrameClass item = getFrameByID(i);
        int stop = 0;
    }

}

void CAudioVideoComponent::paintEvent(QPaintEvent* event){
    // Perform custom drawing here
    QWidget::paintEvent(event);
}
