#include <iostream>
#include <string>
#include <list>
#include <vector>

#define SAFE_DELETE(p) {if(p){delete(p); (p)=NULL;}}

class Observer;

class Subject{
public:
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

class Observer{
public:
    virtual void update(float price) = 0;
};

class ConcreteSubject : public Subject{
public:
    ConcreteSubject() {}

    void attach(Observer *observer) {
        observers.push_back(observer);
    }

    void detach(Observer *observer) {
        observers.remove(observer);
    }

    void setPrice(float price){
        m_price = price;
    }

    void notify() {
        for (std::list<Observer *>::iterator it = observers.begin(); it != observers.end(); it++){
            (*it)->update(m_price);
        }
    }

private:
    float m_price;
    std::list<Observer*> observers;
};

/*
define concrete implementations of observer
multi observers
*/
class ConcreteObserver : public Observer{
public:
    ConcreteObserver(std::string name) {m_strName = name;}

    void update(float price) {
        std::cout << m_strName << " \t - price: " << price << "\n";
    }
private:
    std::string m_strName;
};

int main(){
    
    ConcreteSubject *mSubject = new ConcreteSubject();
    ConcreteObserver *observer1 = new ConcreteObserver("James Lebron");
    ConcreteObserver *observer2 = new ConcreteObserver("Curry Stephen");

    //register observer
    mSubject->attach(observer1);
    mSubject->attach(observer2);

    //modify price and notify observers
    mSubject->setPrice(29.9);
    mSubject->notify();

    //detach observer
    mSubject->detach(observer1);
    mSubject->setPrice(39.9);
    mSubject->notify();

    //delete pointers safely
    SAFE_DELETE(mSubject);
    SAFE_DELETE(observer1);
    SAFE_DELETE(observer2);

    return 0;
}