//---------------------------------------------------------------------------
// return.cpp
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

#include "return.h"

//---------------------------------------------------------------------------
//constructor
Return::Return() {
    commType_ = 'R';
}

//---------------------------------------------------------------------------
// destructor
Return::~Return() {

}

//---------------------------------------------------------------------------
// execture
bool Return::execute() {
   return item_->changeAvailable(1);
}

//---------------------------------------------------------------------------
//display
void Return::display() {
    cout << "  Return    ";
    item_->historyDisplay();
}

//---------------------------------------------------------------------------
//return
Command* Return::create() {
    return new Return(); 
}