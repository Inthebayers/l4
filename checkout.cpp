#include "checkout.h"
#include <iostream>
#include "patroncontainer.h"

//---------------------------------------------------------------------------
// constructor
Checkout::Checkout() {
    commType_ = 'C';
    item_ = nullptr; 
    patron_ = nullptr;
}

//---------------------------------------------------------------------------
// destructor
Checkout::~Checkout() {
}

//---------------------------------------------------------------------------
// display
void Checkout::display() {
    cout << "  CheckOut  ";
    item_->historyDisplay();
}

//---------------------------------------------------------------------------
// execute
// patron_ and item_ data fields are set
bool Checkout::execute() {
    
    // decrement available copies
    return item_->changeAvailable(-1);

}

//---------------------------------------------------------------------------
// checkout
Command* Checkout::create() {
    return new Checkout();
}