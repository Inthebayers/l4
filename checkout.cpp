


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
// data format passed in: Patron userID ItemType  then item specific data
bool Checkout::execute(istream& inFile) {
    //pass in target object
    int patronID;
    inFile >> patronID;
    inFile.get(); // clear empty space

    //create temp book to compare with other books
    // check patron
    //decrease book number available if theres some available
    // add to patron history

}