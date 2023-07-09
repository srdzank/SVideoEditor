
#ifndef CBOTTOMSUBJECT_H
#define CBOTTOMSUBJECT_H
#include <vector>
#include <iostream>
#include <QWidget>


// Observer interface
class Observer : public QWidget
{
    Q_OBJECT

public:
    explicit Observer(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~Observer() {}

    virtual void update(int data) = 0;
};

// Subject class
class Subject
{
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers(int data);
    void doSomething(int data);

private:
    std::vector<Observer*> observers;
};

// Concrete observer class
class ConcreteObserver : public Observer
{
    Q_OBJECT

signals:
    void someSignal(int data);
public slots:
    void handleSignal(int data){
        int stop = 0;
    }
public:
    explicit ConcreteObserver(QWidget* parent = nullptr) : Observer(parent) {}

    void update(int data) override;
};

#endif // CBOTTOMSUBJECT_H
