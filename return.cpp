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

Command* Return::create() {
    return new Return(); 
}