//---------------------------------------------------------------------------
// checkout.h
//---------------------------------------------------------------------------
// Handles checking out a book.
//
// Implementation:
//  -- library calls execute to check out a book to a patron
//---------------------------------------------------------------------------
#include "command.h"

class Checkout : public Command {
public:
    Checkout(); // default

    ~Checkout();

    //---------------------------------------------------------------------------
        /**
         * @brief checks out a book to a patron
         * @return true able to checkout book, false otherwise
         * @post patron is assigned a book and one less copy of book is available
         *       if any were available to begin with
         */
    virtual bool execute(istream&);

private:
    Item* item;
    Patron* patron;
};
