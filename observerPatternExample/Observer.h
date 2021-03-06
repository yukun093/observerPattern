#ifndef __Observer_H__
#define __Observer_H__

class Subject;

class Observer{
public:
    virtual ~Observer() {}

    virtual int getState() = 0;
    virtual void update( Subject *subject ) = 0;
};

#endif