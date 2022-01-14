#include <iostream>
#include <vector>
#include "ConcreteObserver.h"
#include "Subject.h"
#include "ConcreteSubject.h"
#include "windows.h"

#define SAFE_DELETE(p){if(p){delete(p);(p)=NULL;}}

int main(){
    
    //initialize price on observers
    ConcreteObserver observer1(19.5);
    ConcreteObserver observer2(29.5);

    std::cout << "original observer price is " << observer1.getPrice() << std::endl;
    std::cout << "original observer price is " << observer2.getPrice() << std::endl;

    Subject *subject = new ConcreteSubject();
    subject->attach(&observer1);
    subject->attach(&observer2);

    // modify price at factory
    float s = 25.5;
    while(s < 999.9){
        subject->setPrice(s);
        subject->notify();

        std::cout << "Observer1 price now is " << observer1.getPrice() << std::endl;
        std::cout << "Observer2 price now is " << observer2.getPrice() << std::endl;
        std::cout << std::endl;

        s = s + 1.0;
        Sleep(1000);
    }

    //delete pointers safely
    SAFE_DELETE(subject);

    return 0;
}

// reference blog: http://blog.csdn.net/liang19890820