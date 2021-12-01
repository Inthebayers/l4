//---------------------------------------------------------------------------
// bookfactory.h
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

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "book.h"
#include <iostream>

class ItemFactory {
public:
    //---------------------------------------------------------------------------
        /**
         * @brief Construct a new Book Factory object. Default constructor.
         * @post: BookFactory object will be created.
         */
    ItemFactory();

    //---------------------------------------------------------------------------
        /**
         * @brief Destructor for BookFactory object.
         * @pre: Assumes valid BookFactory object to be deleted.
         * @post: BookFactory object will be deleted, with memory freed.
         */
    ~ItemFactory();

    //---------------------------------------------------------------------------
    /**
    * @brief Create a Book object. Determines type of book based on incoming
    * stream information. Can create a fiction, periodical, or children's book.
    * @return Book pointer pointing to the newly created book object.
    */
   // TODO: This should be fine right? If music is added, createMusic?
    Book* createBook(char type);


private:
    // TODO: Do we need to change this to book-> item?
    static const int BOOKTYPES = 26;

    // array containing indexes for all possible bookTypes in future
    // TODO: Do we need to change this to book-> item?
    Book* bookTypes[BOOKTYPES];

    // hash function
    int hash(char ch) const;
};

#endif