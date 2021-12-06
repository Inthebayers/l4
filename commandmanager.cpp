

#include "commandmanager.h"
#include "commandfactory.h"
#include "library.h"
#include "patron.h"


/** 
 * runCommands()
 * Handles the parsing and execution calls for commands coming in through istream. 
 * @param inFile incoming file stream containing commands and run information
 */
bool CommandManager::runCommands(istream& inFile, Library* library) {
    
    // instantiate bool tracker
    bool success = false;

    // create storage for command char 
    char commandType;

    // create pointer to empty command
    Command* newCommand;

    for (;;) {
        // bring in first character in file to commandType
        inFile >> commandType;
        if (inFile.eof()) {
            break;
        }
        inFile.get(); // for empty space

        //create a new command of type
        CommandFactory commFactory;
        newCommand = commFactory.createCommand(commandType);

        // if command character was invalid
        if (newCommand == nullptr) {
            // output error message
            cout << "Command: " << commandType << " is an invalid command" << endl;
            string garbage;
            getline(inFile, garbage);
            success = false;
        }
        else { // command type is valid, next read patron
            int patronID;
            inFile >> patronID;
            inFile.get(); // clear empty space

            //search the library for existing patron

            Patron* patron = nullptr;
            if (!library->getPatron(patronID, patron)) {
                cout << "User ID: " << patronID << " is an invalid user ID" << endl;
                string garbage;
                getline(inFile, garbage);
            }
            //patron should now be a pointer to the specific patorn

            // if a new command object was built
            // buildcommand will execute command on library
            else {
                if (newCommand->buildCommand(inFile, library, patronID, patron)) {
                    // store command in patron
                    patron->addToHistory(newCommand);
                }

            }
        }

    }

    return success;

}