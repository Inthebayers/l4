//---------------------------------------------------------------------------
// display.h
//---------------------------------------------------------------------------
// Subclass of command.
// Displays the contents of the library.
//
// Assumptions:
// -- Will display all items stored in the library
// -- will only be called on a valid library object
//
// Implementation:
// -- calls display on library object
//---------------------------------------------------------------------------

#ifndef DISPLAY_H
#define DISPLAY_H

#include "command.h"
#include <iostream>

class Display : public Command {
  public:
    // constructor
    Display();

    // destructor
    ~Display();

    /** buildCommand
     * @brief builds a command from data file
     * @pre correctly formatted data file
     * @post command object data members are set, all information needed for
     * execute is set, or error message displayed
     * @return true if succesful
     */
    virtual bool buildCommand(istream &inFile, Library *&library);

    /** execute
     * @brief calls display on the library object to display all items
     * @pre a valid library object
     * @post contents of library displayed to coutt
     * @return bool true if successful
     */
    virtual bool execute();

    /** create
     * @brief creates a new display command object
     * @return a Command object pointer to new display object
     */
    virtual Command *create();

    /** display
     * @brief calls display on the library object to display all items
     * @pre a valid library object
     * @post contents of library displayed to coutt
     * @return bool true if successful
     */
    virtual void display();
};

#endif
