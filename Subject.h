/*
 * Subject
 * knows its observers and provides an interface for attaching
 * and detaching observers
 */
#ifndef __Subject_H__
#define __Subject_H__

#include <vector>
#include "Observer.h"

class Subject
{
public:
    virtual ~Subject() {}

    void attach( Observer *observer )
    {
        observers.push_back(observer);
    }

    void detach( const int index )
    {
        observers.erase( observers.begin() + index );
    }

    void notify()
    {
        for ( unsigned int i = 0; i < observers.size(); i++ )
        {
            observers.at( i )->update( this );
        }
    }

    virtual int getState() = 0;
    virtual void setState( const int s ) = 0;

private:
    std::vector<Observer*> observers;
};

#endif
