#include <iostream>
#include "inventory.hpp"

Inventory::Inventory()
{
    items[0] = Weapon("An ordinary sword",20);
    items[1] = Spell("Fireball",20);
    items[2] = Item();
}

void Inventory::print() const
{
    for (int i{0}; i < 3; i++)
    {
        std::cout << items[i].getName() << '\n';
    }
}

/*
void Inventory::addArmor()
{
    char answer[3];
    if (hasArmor)
    {
        std::cout << "You already have an armor in your inventory!\n";
        std::cout << "Would you like to replace " << items[2].getName() << "with --TREASURE--";
        std::cin >> answer;
        if (answer == "yes")
        {
            //
        }
    }
}
*/