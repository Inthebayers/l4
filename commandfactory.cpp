#include "commandfactory.h"
#include "checkout.h"
#include "return.h"
#include "history.h"
#include "display.h"

//---------------------------------------------------------------------------
// commandFactory()
CommandFactory::CommandFactory() {
    for (int i = 0; i < ALPHABET; i++) {
        commandTypes[i] = nullptr;
    }
    // Checkout, Return, History
     commandTypes[2] = new Checkout;
     commandTypes[3] = new Display;
    commandTypes[7] = new History;
     commandTypes[17] = new Return;
}


//---------------------------------------------------------------------------
// createCommand()
Command* CommandFactory::createCommand(char type){
    // create new command pointer
    Command* toReturn = nullptr;

    // create subscript from hash
    int subscript = hash(type);

    // if command exists at hash location
    if (commandTypes[subscript] != nullptr) {
        toReturn = commandTypes[subscript]->create();
    }

    return toReturn;
}

//---------------------------------------------------------------------------
// destructor()
CommandFactory::~CommandFactory() {
    for (int i = 0; i < ALPHABET; i++) {
        delete commandTypes[i];
        commandTypes[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// hash
int CommandFactory::hash(char type) const {
    // change to uppercase if it's not
    type = toupper(type);
    int subscript = type - 'A';
    return subscript;
}