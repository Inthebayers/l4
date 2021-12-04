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
#pragma once
#include "bookcase.h"
#include "patroncontainer.h"

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
    * @brief Initialize structures across subclasses for access.
    * @post: Bookcase and PatronContainer objects will be accessible.
    */
    void setStructures(PatronContainer*& p, Bookcase*& b);
    // TODO: What the hell is setStructures?



    //---------------------------------------------------------------------------
    /**
    * @brief Handles the execution of given code determined by input.
    * @param istream for execution of command
    * @return true if command was sucessfully executed
    * @return false if command was not successfully executed
    */
   // TODO: I don't think this is virtual, how would it work?
    virtual bool execute(istream) = 0;

private:
    static PatronContainer* patronContainer;
    static Bookcase* bookcase;
};