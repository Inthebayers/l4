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

    // create an item from the data file for comparison
    Item* target;
    char type;
    inFile >> type;
    inFile.get(); // skips blank space

    //set Item Format
    char format;
    inFile >> format;

    // create new itemfactory
    ItemFactory itemFactory_;

    // create new item with type
    target = itemFactory_.createItem(type);

    // if media format is not valid, output error
    if (!target->setFormat(format)) {
        cout << "Item Format: " << format << " is and invalid format" << endl;
        string garbage;
        getline(inFile, garbage);
        return false;
    }
    // empty command object
    // create item object for comparison
    target->buildItem(inFile);
    Item* found;
    if (library->getItem(*target, found)) {
        item_ = found;
    }

    return execute();
}


Item* Command::getItem() {
    return item_;
}

char Command::getCommandType() {
    return commType_;
}


