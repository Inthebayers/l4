//---------------------------------------------------------------------------
// display.cpp
//---------------------------------------------------------------------------
// Subclass of command.
// Displays the contents of the library. 
// 
// Assumptions:
// -- Will display all items stored in the library
// -- will only be called on a valid library object
// 
// Implementation:
// -- calls display on library object
//---------------------------------------------------------------------------

#include "display.h"
#include "library.h"

//---------------------------------------------------------------------------
// constructor
Display::Display() {
	libraryPtr_ = nullptr; 
	commType_ = 'D';
}

//---------------------------------------------------------------------------
// destructor
Display::~Display()
{
}

//---------------------------------------------------------------------------
// execute
bool Display::execute()
{
	if (libraryPtr_ != nullptr) {
		libraryPtr_->displayItems();
		return true;
	}
	return false;
}

//---------------------------------------------------------------------------
// display
void Display::display() {
	execute();
}

//---------------------------------------------------------------------------
// create
Command* Display::create()
{
	return new Display();
}

