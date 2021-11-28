//---------------------------------------------------------------------------
// bookContainer.cpp
//---------------------------------------------------------------------------
// A BookContainer class to contain one genre of books. Acts as interface
// between bookcase and book.
// BookContainer is a binary search tree containing nodeData objects that
// Contian pointers to book objects
//
// Assumptions:
//  -- container has no limit
//  -- each book is uniquely identified by its sorting criteria
// Implementation
//  -- uses a hash table of binary search trees to store the books
//  -- first letter of book title is used to get the array index
//  -- array size is 26, letters a...z correlate directly to index 0...25
//  -- first letter of genre is stored as char
//---------------------------------------------------------------------------

#include "bookcontainer.h"

//---------------------------------------------------------------------------
//constructor
BookContainer::BookContainer() {
    root = nullptr;
    genre_ = "";
}

//---------------------------------------------------------------------------
// Destructor
BookContainter::~BookContainer() {
    delete root;
    root = nullptr;
}