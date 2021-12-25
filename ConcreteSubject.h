#ifndef __ConcreteSubject_H__
#define __ConcreteSubject_H__

#include <iostream>

class ConcreteSubject : public Subject
{
public:
    ~ConcreteSubject() {}

    int getState()
    {
        return subject_state;
    }

    void setState( const int s )
    {
        subject_state = s;
    }

private:
    int subject_state;
};

void ConcreteObserver::update( Subject *subject )
{
    observer_state = subject->getState();
    std::cout << "Observer state updated." << std::endl;
}

#endif
