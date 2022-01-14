#ifndef __ConcreteObserver_H__
#define __ConcreteObserver_H__

#include "Subject.h"

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(float s):
        observer_price(s) {}

    ~ConcreteObserver() {}

    float getPrice()  // observerState
    {
        return observer_price;
    }

    void update( Subject *subject );

private:
    float observer_price;
};

#endif