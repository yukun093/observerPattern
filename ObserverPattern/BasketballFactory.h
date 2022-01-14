#ifndef __BasketballFactory_H__
#define __BasketballFactory_H__

#include <iostream>
#include "Subject.h"

class BasketballFactory : public Subject
{
public:
    ~BasketballFactory() {}

    float getPrice()
    {
        return observer_price;
    }

    void setPrice(float s)
    {
        observer_price = s;
    }

private:
    float observer_price;
};

void ConcreteObserver::update(Subject *subject)
{
    observer_price = subject->getPrice();
    std::cout << "Observer's price updated." << std::endl;
}

#endif