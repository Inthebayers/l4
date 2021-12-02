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

#include "shelf.h"

//---------------------------------------------------------------------------
// overloaded operator<<
// TODO can we use this??
ostream& operator<<(ostream& out, const Shelf& bc) {
    return out;
}

//---------------------------------------------------------------------------
// constructor
Shelf::Shelf() {
    // initialize known bookCodes_
    // 2 = childrenbook 5 = fictionbook 15 = periodicalbook
    for (int i = 0; i < ITEM_TYPES; i++) {
        if (i == 2 || i == 5 || i == 15) {
            containers[i] = new ItemContainer();
            validCodes[i] = true;
        }
        else {
            containers[i] = nullptr; 
            validCodes[i] = false;
        }
    }

    // TODO dont hard code this 
    // use A hash in the for loop 
    //initialize container types
    containers[2]->setGenre('C');
    containers[5]->setGenre('F'); 
    containers[15]->setGenre('P');

}

//---------------------------------------------------------------------------
// destructor
Shelf::~Shelf() {
    for (int i = 0; i < ITEM_TYPES; i++) {

            delete containers[i];
            containers[i] = nullptr;
        
    }
}



//---------------------------------------------------------------------------
// insert
bool Shelf::insert(Item* toInsert) {
    bool success = false;
    //check for type
    //check if valid and call insert on correlated BookContainer
    int subscript = hash(toInsert->getType());
    if (containers[subscript] != nullptr) {
        success = containers[subscript]->insert(toInsert);
    }
    return success;
}

//---------------------------------------------------------------------------
// buildBook
bool Shelf::buildItem(istream& in) {
    bool success = false;
    ItemFactory itemF;
    char code;
    for (;;) {
        // read bookCode (genre type)
        in >> code;
        if (in.eof()) {
            break;
        }

        // test for end of file
        in.get(); //get and ignore next blank space

        //newBook stores newly created book object
        Item* newItem = nullptr;

        //check for type validity
        if (validCodes[hash(code)]) {
            newItem = itemF.createItem(code);

            //book class responsible for filling in rest of book information
            if (newItem->buildItem(in)) {

                // if book info was set insert in containers
                success = insert(newItem);
            }
        }


        // skip over the rest of the line
        else {
            string garbage;
            getline(in, garbage);
        }
    }
    return success;
    
}

//---------------------------------------------------------------------------
// checkOut
bool Shelf::checkOut(Item& target) {
    // check for type
    // send to hash
    // call checkout on bookcontainer type
    bool success = false;
    int subscript = hash(target.getType());
    if (containers[subscript] != nullptr) {
        Item* retrieved;
        if (containers[subscript]->retrieve(target, retrieved)) {

       }
    }
    return success;
}

//---------------------------------------------------------------------------
// display
void Shelf::display() const {
    // loop through container and display in order each BookContainer stored

    for (int i = 0; i < ITEM_TYPES; i++) {
        if (containers[i] != nullptr) {
            containers[i]->display();
        }
    }
}

//---------------------------------------------------------------------------
// hash
int Shelf::hash(char code) const {
    code = toupper(code);
    int subscript = code - 'A';
    return subscript;
}