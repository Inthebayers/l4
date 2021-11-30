//---------------------------------------------------------------------------
// bookfactory.cpp
//---------------------------------------------------------------------------
// A Book factory class. Handles the creation of Book objects based on the
// book code being taken from input. Works as an intermidiate class to process
// any type of book creation in one class. Able to create periodicals, fiction,
// and children's books based on incoming book code.
//
// Assumptions:
//  -- valid character corresponding to book type from input
//  -- book type character will correspond to present book type
//---------------------------------------------------------------------------

#include "bookfactory.h"
#include "childrenbook.h"
#include "fictionbook.h"
#include "periodicalbook.h"
#include <ctype.h>


//---------------------------------------------------------------------------
// constructor
BookFactory::BookFactory() {

    for (int i = 0; i < BOOKTYPES; i++) {
        bookTypes[i] = nullptr;
    }

    bookTypes[2] = new ChildrenBook;
    bookTypes[5] = new FictionBook;
    bookTypes[15] = new PeriodicalBook;

}

//---------------------------------------------------------------------------
// destructor
//TODO destructor needed  because new keyword ^^ ??
BookFactory::~BookFactory() {
    for (int i = 0; i < BOOKTYPES; i++) {
        if (bookTypes[i] != nullptr) {
            delete bookTypes[i];
            bookTypes[i] = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
// createBook
Book* BookFactory::createBook(char type) {
    Book* toReturn = nullptr;
    int subscript = hash(type);

    if (bookTypes[subscript] != NULL) {
       toReturn =  bookTypes[subscript]->create();
    }

    return toReturn;
}


//---------------------------------------------------------------------------
// hash
int BookFactory::hash(char genre) const {
    //change to uppercase if it's not
    genre = toupper(genre);
    int subscript = genre - 'A';
    return subscript;
}