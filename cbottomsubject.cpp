#include "cbottomsubject.h"
// Obserser class

void Subject::addObserver(Observer* observer)
{
    if (observer)
    {
        observers.push_back(observer);
    }
}

void Subject::removeObserver(Observer* observer)
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
    {
        observers.erase(it);
    }
}

void Subject::notifyObservers(int data)
{
    for (Observer* observer : observers)
    {
        observer->update(data);
    }
}

void Subject::doSomething(int data)
{
    // Do some work
    std::cout << "Doing something with data: " << data << std::endl;

    // Notify the observers
    notifyObservers(data);
}


void ConcreteObserver::update(int data)
{
    std::cout << "Observer received data: " << data << std::endl;
    emit someSignal(data);
}
