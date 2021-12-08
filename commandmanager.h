//---------------------------------------------------------------------------
// commandmanager.h
//---------------------------------------------------------------------------
// CommandManager handles the operations of parsing command inputs from an
// incoming source. Managaer the operations needed in order to process
// checkouts, returns, and the retrieval of a patrons history.
//
// Assumptions:
//  -- data file will be correctly formatted
//
// Implementation:
//  -- reaching eof character breaks the for loop
//  -- prints error messages on invalid input from file
//---------------------------------------------------------------------------

#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

class Library;
#include "command.h"
#include <iostream>

class CommandManager {

  public:
    /**
     * runCommands()
     *
     * Runs the commands coming in from the infile, utilizing the command
     * container to checkout, return, or retrieve a patron's history.
     *
     * @param inFile incoming file stream containing commands to be executed
     * @return bool if commands were successfully executed
     */
    bool runCommands(istream &inFile, Library *library);
};

#endif