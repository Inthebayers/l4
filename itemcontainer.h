//---------------------------------------------------------------------------
// ItemContainer.h
//---------------------------------------------------------------------------
// An itemContainer class to contain one genre of books. Acts as interface
// between bookcase and book.
// ItemContainer is a binary search tree containing Node structs that
// Contain pointers to book objects, left child, and right child.
//
// Assumptions:
//  -- container has no limit
//  -- each item is uniquely identified by its sorting criteria
//  -- each ItemContainer will store only one type
//  -- items will not be removed from the library
// 
// Implementation
//  -- root data member is a pointer to the root of the tree
//  -- genre_ data member stores the itemContainer genre type
//  -- Does not allow duplicate items to be inserted
//  -- uses a hash table of binary search trees to store the items
//  -- first letter of item title is used to get the array index
//  -- array size is 26, letters a...z correlate directly to index 0...25
//  -- first letter of genre is stored as char
//---------------------------------------------------------------------------

#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include "item.h"
#include <iostream>

using namespace std;

class ItemContainer {

public:
    //constructor
    ItemContainer();

    //destructor
    ~ItemContainer();

    /** insert
    * @brief calls private helper method to insert book as Node is BookConatiner
    * @pre existing book and BookContainer
    * @post book is unchanged
    * @return true book inserted, false book not inserted
    * @param book to be inserted
    */
    bool insert(Item*);

    /** checkOut
    * @brief sets book to checked out and returns by reference
    * @pre existing book in container
    * @return true book was checked out, false book was not checked out
    * @param book to be checkout out
    * @param returned book returned by reference if found
    */
    bool retrieve( Item& target, Item*& returned) const;

    /** isInContainer
    * @brief checks if an item object is found in the container
    * @param target a complete Item object pointer as target
    * @return bool true if found, false if not
    */
    bool isInContainer(Item* target) const;

    /** display
    * @brief prints the contents of the tree in-order
    * @pre a non empty tree
    * @post contents displayed to console
    */
    void display() const;

    /** makeEmpty
     * @brief clears the BookContainer structure
     * @pre a non empty BookContainer 
     * @post An empty BookContainer
     */
    void makeEmpty();

    /** isEmpty
     * @brief Checks if the BookContainer tree is empty
     * @return true if empty, false if not empty
     */
    bool isEmpty() const;

    /** setGenre
    *@brief setter method for the genre_ data member
    * genre can only be set while BookContainer is empty 
    *  - as in it can not later be changed
    *@post BookContainer genreType Specified
    */
    bool setGenre(char genre); 

    /** getGenre
    * @brief retrieves the BookContainer genre_ data member
    * @pre none
    * @return char of genre type 
    */
    char getGenre() const;



private:

    // Node struct that holds item objects in tree
    struct Node {

        Item* item;
        Node* left;
        Node* right;

        // default constructor
        Node();
        // destructor
        ~Node();
    };

    // root of the BookContaier BST
    Node* root;

    //genre of this bookcontainer
    char type;

    /** insertNode
    * @brief inserts a Node object containing a book pointer into the tree
    * @pre valid Node* to insert
    * @post Book* is stored in a Node and placed into sorted position
    * duplicates are not inserted, returns a boolean value
    */
    bool insertNode(Node*);

    /** dsiplayHelper
    * @brief recursive helper function for display
    * traverses the BookContainer tree in order and displays books
    * @post display() called on all book objects in order
    */
    void displayHelper(Node* cur) const;

    /** clear
    * @brief recursive helper function for makeEmpty
    * @post the BookContainer is empty
    */
    void clear(Node* cur);
};

#endif
