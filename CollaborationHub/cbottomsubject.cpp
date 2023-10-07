#include "cbottomsubject.h"
// Obserser class

void CSubject::addObserver(Observer* observer) {
    if (observer)     {
        observers.push_back(observer);
    }
}

void CSubject::removeObserver(Observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())    {
        observers.erase(it);
    }
}

void CSubject::notifyObservers(int data) {
    for (Observer* observer : observers) {
        observer->update(data);
    }
}

void CSubject::doSomething(int data) {
    // Do some work
    std::cout << "Doing something with data: " << data << std::endl;

    // Notify the observers
    notifyObservers(data);
}


void CConcreteObserver::update(int data) {
    std::cout << "Observer received data: " << data << std::endl;
    emit someSignal(data);
}
