#ifndef DISPLAY_H
#define DISPLAY_H

#include "command.h"
#include <iostream>

class Display : public Command
{
public:
    Display();

    ~Display();

    virtual bool execute();

    virtual Command* create();

    virtual void display();

private: 
};

#endif
