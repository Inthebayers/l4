#include "item.h"

using namespace std;

Item::Item(char incomingItem)
{
    itemType = incomingItem;
}

Item::Item()
{
    itemType = ' ';
}

char Item::getType() const {
    return itemType;
}