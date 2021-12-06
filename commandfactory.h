//---------------------------------------------------------------------------
// commandfactory.h
//---------------------------------------------------------------------------
// A command factory class to create new instances of command objects.
//
// Assumptions:
//  -- Each command will have a unique char identifier
//  --
// Implementation:
//  --
//---------------------------------------------------------------------------

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"

class CommandFactory {
public:
    //constructor
    CommandFactory();

    ~CommandFactory();

    /** createCommand
     * @brief creates a new empty command object of a certain type
     * @param type char specifying the command type to create
     * @post new command object created
     * @return pointer to the new command object
     */
    Command* createCommand(char type);

private:

    static const int ALPHABET = 36;

    //array of command types
    Command* commandTypes[ALPHABET];

    // hash function
    int hash(char ch) const;
};
#endif