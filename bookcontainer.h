//---------------------------------------------------------------------------
// bookContainer.h
//---------------------------------------------------------------------------
// A BookContainer class to contain one genre of books. Acts as interface
// between bookcase and book.
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

#ifndef BOOKCONTAINER_H
#define BOOKCONTAINER_H

#include "book.h"
#include <iostream>

using namespace std;

class BookContainer {
    /** operator<<
     * @brief fills ostream with all the information of the books in container
     *        in sorted order
     * @pre existing ostream and BookContainer
     * @post BookContainer unchanged
     * @return filled ostream
     * @param ostream to be filled
     * @param book container to get books from
     */
    friend ostream &operator<<(ostream &, const BookContainer &);

  public:
    BookContainer(); // default constructor
    ~BookContainer();

//---------------------------------------------------------------------------
    /** insert
     * @brief inserts book into container
     * @pre existing book and BookContainer
     * @post book is unchanged
     * @return true book inserted, false book not inserted
     * @param book to be inserted
     */
    bool insert(const Book *&);
    
//---------------------------------------------------------------------------
    /** checkOut
     * @brief sets book to checked out
     * @pre existing book in container
     * @return true book was checked out, false book was not checked out
     * @param book to be checkout out
     */
    Book *checkOut(istream &);

  private:
    struct Node {
        Book *book;
        Node *left;
        Node *right;
    };
    Node *root;
    // private data member
    char genre;
};

#endif
