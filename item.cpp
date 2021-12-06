#include "item.h"

using namespace std;

Item::Item()
{
    itemType_ = ' ';
    
    // initialize known formats
    validFormat[7] = true;
}

Item::~Item()  {
}

char Item::getType() const {
    return itemType_;
}

bool Item::setFormat(char format) {
    bool success = false;
    int checkHash = toupper(format) - 'A';
    if (validFormat[checkHash]) {
        format_ = format;
        success = true;
    }
    return success;
}