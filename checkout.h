//---------------------------------------------------------------------------
// checkout.h
//---------------------------------------------------------------------------
// Handles checking out a book.
//
// Implementation:
//  -- library calls execute to check out a book to a patron
//---------------------------------------------------------------------------
#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "command.h"

class Patron;

class Checkout : public Command {
public:
    Checkout(); // default

    virtual ~Checkout();
    /** display()     
     * @brief Handles output and display of the checkout information
     */

    virtual void display();

    /**
     * @brief checks out a book to a patron
     * @return true able to checkout book, false otherwise
     * @post patron is assigned a book and one less copy of book is available
     *       if any were available to begin with
     */
    virtual bool execute();

    virtual Command* create();


protected:
    Item* item_;
    Patron* patron_;
};

#endif