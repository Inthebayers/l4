//---------------------------------------------------------------------------
// command.h
//---------------------------------------------------------------------------
// Parent class to child command classes
// Handles the commands from the file. Manages subclasses using input command
// characters. Builds command objects from data file and calls execute.  
//
// Assumptions:
// -- Data file format is correct
// 
// Implementation:
// -- Has access to Library class through a reference to a pointer
// -- Builds and checks command type and values
//
//---------------------------------------------------------------------------
#ifndef COMMAND_H
#define COMMAND_H 

class Library;
class Patron;
#include "item.h"

class Command {
public:

    //---------------------------------------------------------------------------
    /** constructor
     * @brief Construct a new Command object. Default constructor.
     * @post: Command object will be created.
     */
    Command();

    //---------------------------------------------------------------------------
    /** destructor
     * @brief Destroy the Return object and free memory.
     * @pre: Assumes valid command object created.
     * @post: Command object will be deleted and memory freed.
     */
    virtual ~Command();

    //---------------------------------------------------------------------------
    /** execute
    * @brief Handles the execution of given code determined by input.
    * @param istream for execution of command
    * @return true if command was sucessfully executed
    * @return false if command was not successfully executed
    */
    virtual bool execute() = 0;

    //---------------------------------------------------------------------------
    /** display
    * @brief Handles the display of command object
    * @post command object displayed to console in correct format
    */
    virtual void display() = 0;

    //---------------------------------------------------------------------------
    /** create
    * @brief creates and returns a new command object pointer
    * @return pointer to a new dynamically allocated command object
    */
    virtual Command* create() = 0;

    //---------------------------------------------------------------------------
    /** buildCommand
    * @brief builds a command from data file
    * @pre correctly formatted data file
    * @post command object created and executed, or error message displayed
    * @param inFile data file of cmmands
    * @param library the library to execute on
    * @param patronID the patron connected to the command
    * @param patronPtr pointer to patron executing command
    * @return true if succesful 
    */
    bool buildCommand(istream& inFile, Library*& library, int patronID, Patron* patronPtr);

    //---------------------------------------------------------------------------
    /** getItem
    * @brief gets and returns the Item object associated with command
    * @return an item pointer
    */
    Item* getItem();

    //---------------------------------------------------------------------------
    /** getCommandType
    * @brief gets and returns the char code for command type
    * @return char of command code
    */
    char getCommandType();

protected:

    // patronID # associated with command
    int patron_;

    //pointer to patron associated with command
    Patron* patronPtr_;

    //pointer to item assocaited with command
    Item* item_;

    //command type code
    char commType_;

    // pointer to library associated with command
    Library* libraryPtr_;
};

#endif