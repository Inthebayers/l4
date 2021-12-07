#ifndef DISPLAY_H
#define DISPLAY_H

#include "command.h"
class Display :
    public Command
{
public:
    Display();

    virtual ~Display();

    virtual bool execute();

    virtual Command* create();

    virtual void display();

private: 
};

#endif
