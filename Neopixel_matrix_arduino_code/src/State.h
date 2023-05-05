#ifndef _STATE_H
#define _STATE_H
#include <Arduino.h>
class State
{
private:
public:
    String id;
    virtual void mainloop() = 0;
    virtual void cleanup() = 0;
    virtual void init() = 0;

    State(){};
    ~State(){};
};
#endif