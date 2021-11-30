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

#include "bookcase.h"

//---------------------------------------------------------------------------
// overloaded operator<<
// TODO can we use this??
ostream& operator<<(ostream& out, const Bookcase& bc) {
    return out;
}

//---------------------------------------------------------------------------
// constructor
Bookcase::Bookcase() {
    // initialize known bookCodes_
    // 2 = childrenbook 5 = fictionbook 15 = periodicalbook
    for (int i = 0; i < GENRE_TYPES; i++) {
        if (i == 2 || i == 5 || i == 15) {
            containers[i] = new BookContainer();
            validCodes[i] = true;
        }
        else {
            containers[i] = nullptr; 
            validCodes[i] = false;
        }
    }

    //initialize container types
    containers[2]->setGenre('C');
    containers[5]->setGenre('F'); 
    containers[15]->setGenre('P');

}

//---------------------------------------------------------------------------
// destructor
Bookcase::~Bookcase() {
    for (int i = 0; i < GENRE_TYPES; i++) {
        if (validCodes) {
            delete containers[i];
            containers[i] = nullptr;
        }
    }
}



//---------------------------------------------------------------------------
// insert
bool Bookcase::insert(Book* toInsert) {
    bool success = false;
    //check for type
    //check if valid and call insert on correlated BookContainer
    int subscript = hash(toInsert->getBookCode());
    if (containers[subscript] != nullptr) {
        success = containers[subscript]->insert(toInsert);
    }
    return success;
}

//---------------------------------------------------------------------------
// buildBook
bool Bookcase::buildBook(istream& in) {
    bool success = false;
    BookFactory bf;
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
        Book* newBook = nullptr;

        //check for type validity
        if (validCodes[hash(code)]) {
            newBook = bf.createBook(code);

            //book class responsible for filling in rest of book information
            if (newBook->buildBook(in)) {

                // if book info was set insert in containers
                success = insert(newBook);
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
bool Bookcase::checkOut(Book& target) {
    // check for type
    // send to hash
    // call checkout on bookcontainer type
    bool success = false;
    int subscript = hash(target.getBookCode());
    if (containers[subscript] != nullptr) {
        Book* retrieved;
        if (containers[subscript]->retrieve(target, retrieved)) {

       }
    }
    return success;
}

//---------------------------------------------------------------------------
// display
void Bookcase::display() const {
    // loop through container and display in order each BookContainer stored

    for (int i = 0; i < GENRE_TYPES; i++) {
        if (containers[i] != nullptr) {
            containers[i]->display();
        }
    }
}

//---------------------------------------------------------------------------
// hash
int Bookcase::hash(char genre) const {
    genre = toupper(genre);
    int subscript = genre - 'A';
    return subscript;
}