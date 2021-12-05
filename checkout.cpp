


#include "checkout.h"

//---------------------------------------------------------------------------
// constructor
Checkout::Checkout() {

}

//---------------------------------------------------------------------------
// destructor
Checkout::~Checkout() {

}

//---------------------------------------------------------------------------
// execute
bool Checkout::execute(istream& inFile) {
    bool success = false;
    //pass in target object
    int patronID;
    inFile >> patronID; // user ID is stored
    inFile.get(); // clear empty space

    // search the library for existing patron
    Patron* patron;
    if (library.getPatron(patronID, patron)) {
        // if the patron exists then check library for the item 
        // build the target item from the data file for comparison
        // create copy of item being checked out
        // place in this checkout
        // decrement the original item currentAvailable_
        // place this into patron 
    }
    else {
        cout << "User ID: " << patronID << " is an invalid user ID" << endl;
        return false;
    }
    // create an item from the data file for comparison
    Item* target;
    char type;
    inFile >> type;
    inFile.get(); // skips blank space

    //set Item Format
    char format;
    inFile >> format;

    target = itemFactory.createItem(type);
    target->setFormat(format);

    target->buildItem(inFile);





    // search the library for 
    
    //decrease book number available if theres some available
    // add to patron history

}