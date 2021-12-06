
#include "history.h"
#include "patroncontainer.h"

//---------------------------------------------------------------------------
// constructor
History::History() {
    commType_ = 'H';
}

//---------------------------------------------------------------------------
//Destructor
History::~History() {

}

//---------------------------------------------------------------------------
// execute
bool History::execute() {
    patronPtr_->printHistory();
    return true;
}

//---------------------------------------------------------------------------
// display
void History::display() {

}

//---------------------------------------------------------------------------
// create
Command* History::create() {
    return new History();
}