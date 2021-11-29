//---------------------------------------------------------------------------
// book.h
//---------------------------------------------------------------------------
// A book object. Handles the creation and storage of a
// book, containing title, author, number of copies "owned" by the library,
// and copies of this book currently checked in. Parent class of fictionbook,
// periodicalbook, and childrenbook.
//
//---------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "item.h"

using namespace std;

class Book : public Item
{
public:
   ///**
   // * @brief Construct a new Book object
   // *
   // * @param title of book being created
   // * @param bookCode code of book being created to determine type of book
   // */
   //Book(string title, char bookCode);

   /**
     * Default constructor
     */
   Book();

   //---------------------------------------------------------------------------
   /**
      * @brief Destroy the Book object
      *
      * @pre: Assumes valid object has been created
      * @post: Object will be deleted and memory freed.
      */
   virtual ~Book();

   //---------------------------------------------------------------------------
   /**
      * @brief Handles the field management required to check out a book.
      *
      * @return true if check out was successful
      * @return false if check out was not sucessful
      *
      * @pre: Assumes book has amount to check out
      * @post: Book will remove 1 copy of itself from the library stores
      */
   virtual bool checkOut();


   //---------------------------------------------------------------------------
   /**
      * @brief Returns book copy to library, adjusting values for currently
      * checked in copies.
      *
      * @return true if value is modified
      * @return false if value is not modified
      *
      * @pre: Assumes book is checked out
      * @post: Book is returned to library, incrementing the number of copies
      */
   bool returnToLibrary();

   //---------------------------------------------------------------------------
   /**
      * @brief Get the code/genre of the book for hashing purposes.
      *
      * @return char corresponding to the code/genre of the book. hell and now we're going past 80
      *
      * @pre: Assumes valid code and properly created book.
      * @post: No changes to data.
      */
   char getBookCode() const;

   //---------------------------------------------------------------------------
   /**
      * @brief Get the title of the current book object.
      *
      * @return string containing the title of the current book
      *
      * @pre: Assumes valid book with title has been created.
      * @post: No changes.
      */
   string getTitle() const;

   /**
     * Sets the title of the given book. Pure virtual.
     */
   void setTitle(string incomingTitle);

   void setBookCode(char);

   void setAvailableCopies(int);

   int getAvailableCopies() const;

   bool setTotalCopies(int);

   int getTotalCopies();

   /** display
     * @brief prints the contents of the book to console,
     * pure virtual function
     * @pre implemented display() in child classes
     * @post book contents displayed to console
     */
   virtual void display() const = 0;

   /** create
     * @brief creates a new book object, pure virutal funciton
     * @pre implemented create() in child classes
     * @return returns a pointer to a new book object
     */
   virtual Book *create() = 0;

   /**
    * Less than operator. Compares LHS and RHS for lesser value.
    * @param rhsBook rhs Book being passed in
    * @return true
    * @return false
    */

   virtual bool operator<(const Book &rhsBook) const = 0;

   /**
     *
     * Greater than operator. compares LHS and RHS for greater value.
     * @param rhsBook rhs Book being passed in for comparison
     * @return true
     * @return false
     */
   virtual bool operator>(const Book &rhsBook) const = 0;

   /**
     * Equals operator. Determines if two Book objects are equal.
     *
     * @param rhsBook rhs Book being passed in for equals comparison
     * @return true
     * @return false
     */
   virtual bool operator==(const Book &rhsBook) const = 0;

   /**
     * Does not equals operator. Determines if two books are not equal.
     *
     * @param rhsBook
     * @return true
     * @return false
     */

   virtual bool operator!=(const Book &rhsBook) const = 0;

protected:
   // title of book
   string title_;

   // code of book
   char bookCode_;

   // copies of book checked into library
   int availableCopies_;

   // total amount of copies the library owns
   int totalCopies_;

   // default booktype
   char bookType_ = 'H';
};
