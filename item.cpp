#include "item.h"

using namespace std;

Item::Item(char incomingItem)
{
    itemType_ = incomingItem;
}

Item::Item()
{
    itemType_ = ' ';
}

Item::~Item() {
    
}

char Item::getType() const {
    return itemType_;
}