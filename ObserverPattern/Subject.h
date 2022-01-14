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

    virtual float getPrice() = 0;
    virtual void setPrice(const float s) = 0;

private:
    std::vector<Observer*> observers;
};

#endif