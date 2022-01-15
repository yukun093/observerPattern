#ifndef __ConcreteObserver_H__
#define __ConcreteObserver_H__

#include "Subject.h"

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver( const int state ) :
        observer_state( state ) {}

    ~ConcreteObserver() {}

    int getState()
    {
        return observer_state;
    }

    void update( Subject *subject );

private:
    int observer_state;
};

#endif