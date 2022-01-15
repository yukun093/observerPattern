#include <iostream>
#include <vector>
#include "ConcreteObserver.h"
#include "Subject.h"
#include "ConcreteSubject.h"

#define SAFE_DELETE(p){if(p){delete(p);(p)=NULL;}

int main(){
    
    ConcreteObserver observer1(10);
    ConcreteObserver observer2(20);

    std::cout << "observer state is " << observer1.getState() << std::endl;
    std::cout << "observer state is " << observer2.getState() << std::endl;

    Subject *subject = new ConcreteSubject();
    subject->attach(&observer1);
    subject->attach(&observer2);

    subject->setState(30);
    subject->notify();

    std::cout << "Observer state is " << observer1.getState() << std::endl;
    std::cout << "Observer state is " << observer2.getState() << std::endl;

    //delete pointers safely
    SAFE_DELETE(subject);

    return 0;
}

// reference blog: http://blog.csdn.net/liang19890820