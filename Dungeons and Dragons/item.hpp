#pragma once

#include <iostream>
#include <string>

const std::string treasure = "treasure";
const std::string extenstion = ".txt";

class Item
{
private:
    std::string type;
    std::string name;
    int modifier;
public:
    Item(std::string _name = "A completely useless item", std::string _type = "Item", int _modifier = 0);

    std::string getType() const { return type; }

    std::string getName() const { return name; }

    int getModifier() const { return modifier; }

    void setModifier(int _modifier) { modifier = _modifier; }

    //void setName(std::string _name) { name = _name; }

   // void setType(std::string _type) { type = _type; }

    //void setModifier(int _modifier) { modifier = _modifier; }

    friend std::istream& operator>>(std::istream& is, Item& item);
};

std::ostream& operator << (std::ostream& os, const Item& item);
