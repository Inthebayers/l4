#include "display.h"
#include "library.h"

Display::Display() {
	libraryPtr_ = nullptr; 
	commType_ = 'D';
}

Display::~Display()
{
	
}

void Display::display() {
	execute();
}

bool Display::execute()
{
	if (libraryPtr_ != nullptr) {
		libraryPtr_->displayItems();
		return true;
	}
	return false;
}

Command* Display::create()
{
	return new Display();
}

