#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "entity.hpp"
#include "race.hpp"
#include "inventory.hpp"
#include "map.hpp"
#include "dragon.hpp"

class Player : public Entity
{
private:
    int bonusStrength;
    int bonusMana;
    int armor;
    Race race;
    Inventory inventory;
public:
    Player(Race _race);

    std::string getRace() const { return race.getName(); }

    virtual void attack(Entity& target);

    virtual void castSpell(Entity& target);

    virtual void takeDamage(int damage);

    void printInventory() const;

    void move(Map& map);

    void levelUp();

    void specialCheck(Map& map);

    void handleLocation(Map& map);

    void engage(Entity& dragon);
};


#endif // !__PLAYER_HPP



