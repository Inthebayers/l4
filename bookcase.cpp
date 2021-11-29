//---------------------------------------------------------------------------
// bookcase.cpp
//---------------------------------------------------------------------------
// Holds containers of books of different genres.
// Genre's are stored in a hash
//
// Assumptions:
//  -- each genre is uniquely identified by a letter
//  -- there cannot be two genres with the same letter
// Implementation
//  -- uses a hash table to store containers for differnt genres
//  -- each genre is associated with a letter e.g: F- fiction
//  -- array size is 26, letters a...z correlate directly to index 0...25
//---------------------------------------------------------------------------

#include "bookcase.h"

//---------------------------------------------------------------------------
// overloaded operator<<
// TODO can we use this??
ostream& operator<<(ostream& out, const Bookcase& bc) {
}

//---------------------------------------------------------------------------
// constructor
Bookcase::Bookcase() {
    // initialize known bookCodes_
    // 
    // childrenBook
    knownBookCodes[2] = true;
    // FictionBook
    knownBookCodes[5] = true;
    // PeriodicalBook
    knownBookCodes[15] = true;
}


//---------------------------------------------------------------------------
// insert
bool Bookcase::insert(const Book& toInsert) {
    //check for type
    char type = toInsert.getBookCode();
    //check if valid

    if (knownBookCodes[check]) {

    }
    // send to hash
    // call insert at bst
}

//---------------------------------------------------------------------------
// checkOut
bool Bookcase::checkOut(Book*& target) const {
    // calls checkout on bookcontainer type
    
}

//---------------------------------------------------------------------------
// display
void Bookcase::display() const {
    // loop through container and display in order each BookContainer stored
    for (int i = 0; i < GENRE_TYPES; i++) {
        if (containers[i] != nullptr) {
            *containers[i].display();
        }
    }
}

//---------------------------------------------------------------------------
// hash
int Bookcase::hash(char genre) const {

}