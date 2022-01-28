#include <iostream>
#include <vector>
#include "ConcreteObserver.h"
#include "Subject.h"
#include "BasketballFactory.h"
#include "windows.h"

#define SAFE_DELETE(p){if(p){delete(p);(p)=NULL;}}

int main(){
    
    //initialize price on observers
    ConcreteObserver supermarket1(19.5);
    ConcreteObserver supermarket2(29.5);
    ConcreteObserver sportcenter1(35.5);

    Subject *subject = new BasketballFactory();
    subject->attach(&supermarket1);
    subject->attach(&supermarket2);
    subject->attach(&sportcenter1);

    std::cout << "original observer price is " << supermarket1.getPrice() << std::endl;
    std::cout << "original observer price is " << supermarket2.getPrice() << std::endl;
    std::cout << "original observer price is " << sportcenter1.getPrice() << std::endl;

    // modify price at factory
    float s = 25.5;
    while(s < 50.0){
        subject->setPrice(s);
        subject->notify();

        std::cout << "price in the supermarket1 now is " << supermarket1.getPrice() << std::endl;
        std::cout << "price in the supermarket2 now is " << supermarket2.getPrice() << std::endl;    
        std::cout << "price in the sportcenter1 now is " << sportcenter1.getPrice() << std::endl;

        if(s == 30.5){
            subject->detach(0);  // supermarket2 as one Observer object will stop increasing the price if the original price is too high
        }

        else if(s == 35.5){
            subject->detach(1);  // sportcenter1 as one Observer object will stop increasing the price if the original price is too high
        }

        else if(s == 40.5){
            subject->detach(2);  // sportcneter2 as another Observer object will also stop increasing the price if the original price is too high
        }
        
        std::cout << std::endl;
        s = s + 1.0;
        Sleep(1000);
    }

    //delete pointers safely
    SAFE_DELETE(subject);

    return 0;
}

// reference blog: http://blog.csdn.net/liang19890820