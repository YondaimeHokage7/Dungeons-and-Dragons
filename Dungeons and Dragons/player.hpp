#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "entity.hpp"
#include "race.hpp"
#include "human.hpp"
#include "item.hpp"
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

    std::string getRace() const;

    void attack(Entity&);

    void castSpell(Entity&);

    void takeDamage(int damage);

    void printInventory() const;

    void move(Map& map);
};


#endif // !__PLAYER_HPP
