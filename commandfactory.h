////---------------------------------------------------------------------------
//// commandfactory.h
////---------------------------------------------------------------------------
//// A command factory class to create new instances of command objects.
////
//// Assumptions:
////  -- Each command will have a unique char identifier
////  --
//// Implementation:
////  --
////---------------------------------------------------------------------------
//#pragma once
//#include "command.h"
//
//class CommandFactory {
//public:
//    //constructor
//    CommandFactory();
//
//    /** createCommand
//     * @brief creates a new empty command object of a certain type
//     * @param type char specifying the command type to create
//     * @post new command object created
//     * @return pointer to the new command object
//     */
//    Command* createCommand(char type) const;
//
//private:
//    //arrya of command types
//    Command* commandTypes[26];
//
//    // hash function
//    int hash(char ch) const;
//};
