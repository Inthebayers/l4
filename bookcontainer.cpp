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
// Node functions

//---------------------------------------------------------------------------
// Node Constructor
Node::Node() {
    book = nullptr;
    left = nullptr;
    right = nullptr;
}

//---------------------------------------------------------------------------
// Node Destructor
Node::~Node(
    delete book;
    book = nullptr;
    left = nullptr;
    right = nullptr;
)

//---------------------------------------------------------------------------
// Overloaded << operator
// TODO implement this
Ostream& operator<<(ostream& out, const BookContainer& bc) {

}

//---------------------------------------------------------------------------
// BookContianer Methods

//---------------------------------------------------------------------------
//constructor
BookContainer::BookContainer() {
    root = nullptr;
    genre_ = "";
}

//---------------------------------------------------------------------------
// Destructor
BookContainter::~BookContainer() {
    makeEmpty();
}

//---------------------------------------------------------------------------
// insert
bool BookContainer::insert(const Book& theBook) {
    bool success = false;
    // first check that the book is the correct type
    if (theBook.getBookCode() == genre_) {
        // and the book is not already in container
        Book temp;
        //TODO change to isInContainer
        if (!retrieve(theBook, temp)) {
            //then send to insertNode 
            Node* toInsert = new Node;
            toInsert->book = thebook;
            if (insertNode(toInsert)) {
                success = true;
            }
        }
    }
    return success;
}

//---------------------------------------------------------------------------
// retrieve
bool BookContainer::retrieve(Book& target, Book& returned) const {
    returned = nullptr;
    bool success = false;
    Node* cur = root;

    while (cur != nullptr) {
        if (*cur->book == target) {
            success = true;
            returned = *cur->book;
            break;
            // move to left subtree
        }
        else if (target < *cur->book && cur->left != nullptr) {
            cur = cur->left;
            // move to right subtree
        }
        else if (target > *cur->book && cur->right != nullptr) {
            cur = cur->right;
        }
        // not found break loop and return
        else
            break;
    }
    return success;
}

//---------------------------------------------------------------------------
//display
void BookContainer::display() const {
    if (root != nullptr) {
        displayHelper(root);
    }
}

//---------------------------------------------------------------------------
// displayHelper
// recursive helper for display
void BookContainer::displayHelper(Node* cur) const {
    if (cur == nullptr) {
        return;
    }
    displayHelper(cur->left);
    cur->book->display();
    displayHelper(cur->right);
}

//---------------------------------------------------------------------------
// makeEmpty 
void BookContainer::makeEmpty() {
    clear(root);
}

//---------------------------------------------------------------------------
// clear
// recursive helper function for makeEmpty
void BookContainer::clear(Node* cur) {
    // base case
    if (cur == nullptr) {
        return;
    }
    //post-order traversal
    clear(cur->left);
    clear(cur->right);
    delete cur;
    cur = nullptr;
}

//---------------------------------------------------------------------------
// isEmpty
bool BookContainer::isEmpty() const {
    return (root == nullptr);
}

//---------------------------------------------------------------------------
// setGenre
// genre can only be set on an empty bookContainer object
// once books are stored the genre can not be changed
bool BookContainer::setGenre(char genre) {
    bool success = false;
    if (root == nullptr && genre >= 'a' && genre <= 'Z') {
        // uppercase for consistency
        genre = toupper(genre);
        success = true;
    }
    return success;
}

//---------------------------------------------------------------------------
// getGenre
char BookContainer::getGenre() const {
    return genre_;
}

//---------------------------------------------------------------------------
// insertNode
// helper function to insert into a tree 
bool BookContainer::insertNode(const Node* node) {
    bool inserted = false; 

    // if the tree is empty
    if (root == nullptr) {
        root = toInsert;
        inserted = true;
    }
    //if its not empty traverse the tree
    else {
        Node* cur = root;
        //if the book is less thn the curernt book insert in the left subtree
        // otherwise insert in the right subtree

        while (!inserted) {
            // if its less than 
            if (*node->book < *cur->book) {
                // and there is an empty space, insert
                if (cur->left == nullptr) {
                    cur->left == node;
                    inserted = true;
                }
                // if theres not an empty space move cur left
                else {
                    cur = cur->left;
                }
            }
            // if its greater than 
            else if (*node->book > *node->book) {
                // and theres an empty space, insert
                if (cur->right == nullptr) {
                    cur->right = node;
                    inserted = true;
                }
                // otherwise move right
                else {
                    cur = cur->right;
                }
            }
            // if its equal, delete the node and return false
            else if (*node->book == *cur->book) {
                node->book = nullptr;
                delete node;
                node = nullptr;
                inserted = false;
                break;
            }
        }
    }

    return inserted;

}