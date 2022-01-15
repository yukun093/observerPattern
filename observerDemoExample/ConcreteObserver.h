#ifndef __ConcreteObserver_H__
#define __ConcreteObserver_H__

#include "Subject.h"

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(const int price) :
        observer_price(price) {}

    ~ConcreteObserver() {}

    int getState()  // observerState
    {
        return observer_price;
    }

    void update( Subject *subject );

private:
    int observer_price;
};

#endif