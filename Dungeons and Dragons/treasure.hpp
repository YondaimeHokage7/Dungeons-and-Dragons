#pragma once
#include <iostream>
#include "item.hpp"
#include "map.hpp"
#include <string>

/// Default treasure file name
const std::string treasureFile = "treasure";

/// A class representing a treasure
class Treasure
{
private:
    /// The actual tresure
    Item item;
public:
    /// Constructor
    Treasure(const Map& map);
    /// Item getter
    const Item& getItem() const { return item; }
    /// A function generating the next treasure list
    void generateNext(int level);
    /// Overloaded >> operator
    friend std::istream& operator>>(std::istream& is, Treasure& _item);
};
/// Overloaded << operator
std::ostream& operator << (std::ostream& os, Treasure& _item);
