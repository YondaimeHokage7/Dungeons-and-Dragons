#pragma once
#include <iostream>
#include "item.hpp"
#include "map.hpp"
#include <string>

const std::string treasureFile = "treasure";

class Treasure
{
private:
    Item item;
public:
    Treasure(const Map& map);

    const Item& getItem() const { return item; }

    void generateNext(int level);

    friend std::istream& operator>>(std::istream& is, Treasure& _item);
};

std::ostream& operator << (std::ostream& os, Treasure& _item);
