#ifndef __TREASURE_HPP
#define __TREASURE_HPP

#include "item.hpp"

class Treasure
{
private:
    Item item;
public:
    Treasure();

    Item getItem() const { return item; }
};

#endif // !__TREASURE_HPP