//---------------------------------------------------------------------------
// return.h
//---------------------------------------------------------------------------
// Handles the operation of returning a book into the library system. Both by
// unassigning the book from the patron who checked it out, and modifying the
// values for currently checked in copies of the book.
//
// Assumptions:
// -- will only be called on a valid item in the library
// -- patronPtr will point to a valid patron
//
// Implementation:
//  -- no destructor implementation for dynamic memory in create() method -
//  -- memory deallocation to be handled by Patron class where commands are
//  -- are stored in itemHistory list
//
//---------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include <iostream>

class Return : public Command {
  public:
    /**
     * @brief Construct a new Return object. Default constructor.
     *
     * @post: Return object will be created.
     */
    Return();

    /**
     * @brief Destroy the Return object and free memory.
     *
     * @pre: Assumes valid return object created.
     * @post: Return object will be deleted and memory freed.
     */
    ~Return();

    /** buildCommand
     * @brief builds a command from data file
     * @pre correctly formatted data file
     * @post command object data members are set, all information needed for
     * execute is set, or error message displayed
     * @return true if succesful
     */
    virtual bool buildCommand(istream& inFile, Library*& library);

    /**
     * @brief Handles the execution of the return of the given book
     * into the library system.
     *
     * @param input for execution of command
     * @return true if command was sucessfully executed
     * @return false if command was not successfully executed
     */
    virtual bool execute();

    /** display
     * @brief displays "return" to cout and calls historyDisplay on Item
     * @pre a previously executed return object
     * @post Checkout and item specific historyDisplay printed to console
     */
    virtual void display();

    /** create
     * @brief returns new return object, dynamic memory
     * @return pointer to new dynamically allocated return object
     * @post new return Command object created and returned
     */
    virtual Command *create();
};

#endif