#pragma once

#include <iostream>
#include <string>

const std::string treasure = "treasure";
const std::string extenstion = ".txt";

/// A class representing an item
class Item
{
private:
    /// String keeping the item type
    std::string type;
    /// String keeping the item name
    std::string name;
    /// Integer representing the item modifier
    int modifier;
public:
    /// Default parameter constructor
    Item(std::string _name = "A completely useless item", std::string _type = "Item", int _modifier = 0);
    /// Item type getter
    std::string getType() const { return type; }
    /// Item name getter
    std::string getName() const { return name; }
    /// Item modifier getter
    int getModifier() const { return modifier; }
    /// Item modifiier setter
    void setModifier(int _modifier) { modifier = _modifier; }
    /// Overloaded >> operator
    friend std::istream& operator>>(std::istream& is, Item& item);
};
/// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Item& item);
/// Overloaded != operator
bool operator!=(Item& item1, Item& item2);
