//---------------------------------------------------------------------------
// command.cpp
//---------------------------------------------------------------------------
// Handles the commands from the file. Manages subclasses using input command
// characters.
//
// Assumptions:
// --
// Implementation:
// --
//
//---------------------------------------------------------------------------

#include "command.h"
#include "library.h"
#include "patron.h"

//---------------------------------------------------------------------------
// constructor
Command::Command() {
    commType_ = ' ';
    patron_ = 0;
    item_ = nullptr;
    patronPtr_ = nullptr;
    libraryPtr_ = nullptr; 
}

//---------------------------------------------------------------------------
// destructor
Command::~Command() {
    item_ = nullptr;
}

//---------------------------------------------------------------------------
// buildCommand
// data format passed in: Patron userID ItemType  itemFormat  then item specific data(author, titiel, or date for p)
bool Command::buildCommand(istream& inFile, Library*& library, int patronID, Patron* patronPtr) {
    //has access to library
    /*Library* library_ = library;*/
    libraryPtr_ = library;
    patron_ = patronID;
    patronPtr_ = patronPtr;

    // H data ends after patron so nothing to do but execute
    if (commType_ == 'H' || commType_ == 'D') {
        return execute();
    }

    // create an item from the data file for comparison
    // store itemtype from data file
    char type;
    inFile >> type;
    inFile.get(); // skips blank space

    // create new itemfactory
    ItemFactory itemFactory_;

    // create new item of  type
    Item* target = nullptr;
    target = itemFactory_.createItem(type);

    // item now has default format
    if (target == nullptr) {
        string garbage;
        getline(inFile, garbage);
        return false;
    }
    //set Item Format from incoming data 
    char format;
    inFile >> format;
    inFile.get();

    //check that the input was a valid format
    
    if (!target->setFormat(format)) {
        cout << endl << "ERROR: Item Format: \"" << format << "\" is an invalid format" << endl;

        // discard the rest of the line and return 
        string garbage;
        getline(inFile, garbage);
        delete target;
        return false;
    }
    // if format is valid, fill an item object with the rest of the data line
    target->fill(inFile);
    Item* found;
    if (library->getItem(*target, found)) {
        if (found->getCopiesAvailable() == 0 && commType_ == 'C') {
            cout << endl << "ERROR: Patron " << patronID << " checkout failed due to no copies available of";
            found->errorDisplay();
            cout << endl;
             
            delete target; 
            return false;
        }
        item_ = found;

        bool success = execute();
         delete target;
        return success;
    }
    else {

        
        target->errorDisplay();
        
        cout << endl;
         delete target;
        return false;
    }

   
}


Item* Command::getItem() {
    return item_;
}

char Command::getCommandType() {
    return commType_;
}


