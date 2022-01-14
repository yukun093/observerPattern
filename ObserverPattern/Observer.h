#ifndef __Observer_H__
#define __Observer_H__

class Subject;

/*
 * Observer
 * defines an updating interface for objects that should be notified
 * of changes in a subject
 */
class Observer{
public:
    virtual ~Observer() {}

    virtual float getPrice() = 0;
    virtual void update( Subject *subject ) = 0;
};

#endif
