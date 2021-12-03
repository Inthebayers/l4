//---------------------------------------------------------------------------
// patron.cpp
//---------------------------------------------------------------------------
// A Patron class to store information on Patrons of the library
// Patron name, ID, book rental history and currently checked out books
// are all stored.
// Patron Objects are initiated in the Patron Factory.
//
// Assumptions:
//  -- rentalHistory has no limit
//  -- currentCheckOuts has no limit
//  -- userID will be unique identifier
// Implementation:
//  -- rentalHistory Book objects are stored in a STL list
//  -- currentCheckOuts Book objects are stored in a STL list
//  -- Once a book is added to currentCheckOuts it is added to rentalHistory
//---------------------------------------------------------------------------

#include "patron.h"

//---------------------------------------------------------------------------
// Constructor
Patron::Patron() {
	nameLastFirst_ = "";
	userID_ = 0;
}

//---------------------------------------------------------------------------
// destructor
Patron::~Patron() {

}


//---------------------------------------------------------------------------
// buildPatron
bool Patron::buildPatron(istream& inFile) {
	
	int userID;

	string nameLastFirst;

	// check if userID is correct
	if (userID > 0) {
		inFile >> userID;

		inFile.get();

		getline(inFile, nameLastFirst);

		userID_ = userID;

		nameLastFirst_ = nameLastFirst;

		return true;
	}

	return false;
}

//---------------------------------------------------------------------------
// getFirst
string Patron::getName() const {
	return nameLastFirst_;
}

//---------------------------------------------------------------------------
// getID
int Patron::getID() const {
	return userID_;
}

//---------------------------------------------------------------------------
// printHistory
void Patron::printHistory() const {
	// go through list of commands ie. checkout, returns 
	// print via command functions the history
}

//---------------------------------------------------------------------------
// addHistory
bool Patron::addToHistory(const Item& item) {

}
