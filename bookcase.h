//---------------------------------------------------------------------------
// bookcase.h
//---------------------------------------------------------------------------
// Holds containers of books of different genres.
//
// Assumptions:
//  -- each genre is uniquely identified by a letter
//  -- there cannot be two genres with the same letter
// Implementation
//  -- containers[] 
//  -- uses a hash table to store containers for differnt genres
//  -- each genre is associated with a letter e.g: F- fiction
//  -- array size is 26, letters a...z correlate directly to index 0...25
//  -- uses a hash table of binary search trees to store the books
//  -- first letter of genre is stored as char
//  -- no destructor - no dynamically allocated memory
//---------------------------------------------------------------------------

#ifndef BOOKCASE_H
#define BOOKCASE_H

#include "bookcontainer.h"
#include <iostream>

class Bookcase {
    friend ostream& operator<<(ostream&, const Bookcase&);

public:

    Bookcase();  // contructor

//--------------------------------------------------------------------------
    /** insert
     * @brief inserts book into a container 
     * @pre existing book object of any type
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
    bool checkOut(Book*& target) const;

    void display() const;


private:

    const int GENRE_TYPES = 26;

    // to store current known book types to check for
    // genre validity
    bool knownBookCodes[GENRE_TYPES]; 

    // hash funtion to get genre 
    int hash(char) const;
    
    // array that stores containers by genre
    BookContainer* containers[GENRE_TYPES]; 
};

#endif
