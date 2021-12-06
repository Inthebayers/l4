//---------------------------------------------------------------------------
// command.h
//---------------------------------------------------------------------------
// Handles the commands from the file. Manages subclasses using input command
// characters.
//
// Assumptions:
// --
// Implementation:
// --
//
//---------------------------------------------------------------------------
#ifndef COMMAND_H
#define COMMAND_H 

class Library;
class Patron;
#include "item.h"

class Command {
public:
    /**
     * @brief Construct a new Command object. Default constructor.
     * @post: Command object will be created.
     */
    Command();

    //---------------------------------------------------------------------------
    /**
     * @brief Destroy the Return object and free memory.
     * @pre: Assumes valid command object created.
     * @post: Command object will be deleted and memory freed.
     */
    virtual ~Command();

    //---------------------------------------------------------------------------
    /**
    * @brief Handles the execution of given code determined by input.
    * @param istream for execution of command
    * @return true if command was sucessfully executed
    * @return false if command was not successfully executed
        */
    virtual bool execute() = 0;

    virtual void display() = 0;

    //TODO comment
    virtual Command* create() = 0;

    bool buildCommand(istream& inFile, Library*& library, int patronID, Patron* patronPtr);

    Item* getItem();

    char getCommandType();

protected:
    int patron_;
    Patron* patronPtr_;
    Item* item_;
    char commType_;
};

#endif