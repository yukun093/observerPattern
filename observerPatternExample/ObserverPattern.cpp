#include <iostream>
#include <vector>
#include "ConcreteObserver.h"
#include "Subject.h"
#include "ConcreteSubject.h"

int main(){
    
    ConcreteObserver observer1(19);  //input a integer
    ConcreteObserver observer2(25);
    
    std::cout << "observer state is " << observer1.getState() << std::endl;
    std::cout << "observer state is " << observer2.getState() << std::endl;

    Subject *subject = new ConcreteSubject();
    subject->attach(&observer1);
    subject->attach(&observer2);

    subject->setState(30);
    subject->notify();

    std::cout << "Observer state is " << observer1.getState() << std::endl;
    std::cout << "Observer state is " << observer2.getState() << std::endl;

    delete subject;

    return 0;
}
