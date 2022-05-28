#ifndef __ITEM_HPP
#define __ITEM_HPP

#include <string>

class Item
{
private:
    std::string name;
    int modifier;
public:
    Item(std::string _name = "A completely useless item", int _modifier = 0);

    std::string getName() const { return name; }

    int getModifier() const { return modifier; }
};
#endif // !__ITEM_HPP
