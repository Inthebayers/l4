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
}

//---------------------------------------------------------------------------
// destructor
Command::~Command() {
    item_ = nullptr;
}

//---------------------------------------------------------------------------
// buildCommand
// data format passed in: Patron userID ItemType  itemFormat  then item specific data(author, titiel, or date for p)
bool Command::buildCommand(istream& inFile, Library* library, int patronID, Patron* patronPtr) {
    //has access to library
    Library* library_ = library;
    patron_ = patronID;
    patronPtr_ = patronPtr;

    // H data ends after patron so nothing to do but execute
    if (commType_ == 'H') {
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
    
    //set Item Format from incoming data 
    char format;
    inFile >> format;

    //check that the input was a valid format
    if (!target->setFormat(format)) {
        cout << "Item Format: " << format << " is and invalid format" << endl;

        // discard the rest of the line and return 
        string garbage;
        getline(inFile, garbage);
        return false;
    }
    // if format is valid, fill an item object with the rest of the data line
    target->fill(inFile);
    Item* found;
    if (library->getItem(*target, found)) {
        //TODO nothing getting found
        found->display();
        cout << "Was Found!!!!!!" << endl;
           
        item_ = found;
        return execute();
    }
    else {
        target->display();
        cout << " is not a valid item";
        return false;
    }

   
}


Item* Command::getItem() {
    return item_;
}

char Command::getCommandType() {
    return commType_;
}


