//---------------------------------------------------------------------------
// checkout.h
//---------------------------------------------------------------------------
// Subclass of command.
// Handles checking out an item, will attempt to decrement avaialble copies
// of the book by one.
//
// Assumptions:
// -- will only be called on a valid item in the library
// -- patronPtr will point to a valid patron
//
// Implementation:
//  -- Execute calls changeAvailable method on Item
//  -- Item to do error handling with available copies
//  -- no destructor implementation for dynamic memory in create() method -
//  -- memory deallocation to be handled by Patron class where commands are
//  -- are stored in itemHistory list
//---------------------------------------------------------------------------

#ifndef CHECKOUT_H
#define CHECKOUT_H
#include "command.h"

class Checkout : public Command {
  public:
    // constructor
    Checkout();

    // destructor
    virtual ~Checkout();

    //---------------------------------------------------------------------------
    /** display
     * @brief displays "CheckOut" to cout and calls historyDisplay on Item
     * @pre a previously executed checkout object
     * @post Checkout and item spedific historyDisplay printed to console
     */
    virtual void display();

    //---------------------------------------------------------------------------
    /** execute
     * @brief calls changeAvailable method on Item to decrement by 1
     * @return true able to checkout book, false otherwise
     * @post itemAvailable copies decremented by one or error message printed
     */
    virtual bool execute();

    //---------------------------------------------------------------------------
    /** create
     * @brief returns new Checkout object, dynamic memory
     * @return pointer to new dynamically allocated Checkout object
     * @post new Checkout Command object created and returned
     */
    virtual Command *create();
};

#endif