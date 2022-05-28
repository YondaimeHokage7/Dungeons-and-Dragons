#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "entity.hpp"
#include "race.hpp"
#include "human.hpp"
#include "item.hpp"
#include "inventory.hpp"

class Player : public Entity
{
private:
    Race race;
    Inventory inventory;
public:
    Player(Race _race);

    std::string getRace() const;

    void attack(Entity&, int attackDamage);

    void castSpell(Entity&, int spellDamage);

    void takeDamage(int damage);

    void printInventory() const;

};


#endif // !__PLAYER_HPP
