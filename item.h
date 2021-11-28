//---------------------------------------------------------------------------
// item.h
//---------------------------------------------------------------------------
// An abstract class. 
// An item class for the library to store different types of items. 
// Current item types are book, but can be other types such as DVD, magazine, etc. 
// Assumptions:
//  -- 
// Implementation:
//  -- 
//---------------------------------------------------------------------------

#pragma once 
#include <string>
using namespace std;

class Item {
public:

    /**
     * 
     * @param incomingItem 
     */
    Item(string incomingItem);

    Item();
private:

protected:
    string itemType;

};