//---------------------------------------------------------------------------
// history.cpp
//---------------------------------------------------------------------------
// Handles the operation of retrieving the history of a Patron within the
// library system. Returns and outputs their rental history of books from the
// library.
//
// Assumptions:
// -- will only be called on a valid item in the library
// -- patronPtr will point to a valid patron
//
// Implementation:
//  -- no destructor implementation for dynamic memory in create() method -
//  -- memory deallocation to be handled by Patron class where commands are
//  -- are stored in itemHistory list
//---------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"
#include <iostream>

class History : public Command {
  public:
    /** constructor
     * @brief Construct a new History object. Default constructor.
     *
     * @post: history object will be created.
     */
    History();

    /** destructor
     * @brief Destroy the History object and free memory.
     *
     * @pre: Assumes valid history object created.
     * @post: History object will be deleted and memory freed.
     */
    ~History();

    /** buildCommand
     * @brief builds a command from data file
     * @pre correctly formatted data file
     * @post command object data members are set, all information needed for
     * execute is set, or error message displayed
     * @return true if succesful
     */
    virtual bool buildCommand(istream &inFile, Library *&library);

    /**
     * @brief Handles the execution of the history retrieval for a patron
     * object. Outputs the check-out history of a given patron in a organized
     * fashion.
     *
     * @param input for execution of command
     * @return true if command was sucessfully executed
     * @return false if command was not successfully executed
     */
    virtual bool execute();

    /** display
     * @brief pure virtual method
     */
    virtual void display();

    /** create
     * @brief returns new History object, dynamic memory
     * @return pointer to new dynamically allocated Checkout object
     * @post new Checkout Command object created and returned
     */
    virtual Command *create();
};

#endif