//---------------------------------------------------------------------------
// commandmanager.h
//---------------------------------------------------------------------------
// CommandManager handles the operations of looping through the command
// data file. Interface between library object, command object, and data
// file.
//
// Assumptions:
//  -- data file will be correctly formatted
//  -- data file will contain no empty lines
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
     * @brief reads the the command type from the data file, creates a
     * command object and passes the istream down as a stringstream
     *
     * @param inFile incoming file stream containing commands to be executed
     * @return bool if commands were successfully executed
     */
    bool runCommands(istream &inFile, Library *library);
};

#endif