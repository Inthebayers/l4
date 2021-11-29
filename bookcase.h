//---------------------------------------------------------------------------
// bookcase.h
//---------------------------------------------------------------------------
// Holds containers of books of different genres.
//
// Assumptions:
//  -- each genre is uniquely identified by a letter
//  -- there cannot be two genres with the same letter
// Implementation
//  -- uses a hash table to store containers for differnt genres
//  -- each genre is associated with a letter e.g: F- fiction
//  -- array size is 26, letters a...z correlate directly to index 0...25
// 
// TODO - these comments came from bookContainer - seem more applicable here
// //  -- uses a hash table of binary search trees to store the books
//  -- first letter of book title is used to get the array index
//  -- array size is 26, letters a...z correlate directly to index 0...25
//  -- first letter of genre is stored as char

//---------------------------------------------------------------------------

#ifndef BOOKCASE_H
#define BOOKCASE_H

#include "bookcontainer.h"
#include <iostream>

class Bookcase {
    friend ostream& operator<<(ostream&, const Bookcase&);

public:

    Bookcase();  // contructor
    ~Bookcase(); // destructor

//--------------------------------------------------------------------------
    /** insert
     * @brief inserts book into a container
     * @pre existing book and BookContainer
     * @post book is unchanged
     * @return true book inserted, false book not inserted
     * @param book to be inserted
     */
    bool insert(const Book*&);

    //--------------------------------------------------------------------------
    /** checkOut
    * @brief checks and gets the book that needs to be checked out
    * @pre Book object of target
    * @post decrements copies of book available by 1 if books available
    * @return true if successful false if not
    * @param book to be checkout out
    */
    bool checkOutBook(Book*& target);

    void display() const;

private:
    int hash(char) const;          // hash funtion to get genre type
    BookContainer* containers[26]; // array that stores containers
};

#endif
