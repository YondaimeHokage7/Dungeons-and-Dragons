#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "entity.hpp"
#include "race.hpp"
#include "inventory.hpp"
#include "cellIndex.hpp"
#include "map.hpp"

class Player : public Entity
{
private:
    CellIndex position;
    int level;
    Race race;
    Inventory inventory;
public:
    Player(Race _race);

    std::string getRace() const { return race.getName(); }

    void attack(Entity& target);

    void castSpell(Entity& target);

    void takeDamage(int damage);

    void printInventory() const { inventory.print(); }

    void move(Map& map);
};


#endif // !__PLAYER_HPP
