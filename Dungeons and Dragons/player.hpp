#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "entity.hpp"
#include "race.hpp"
#include "inventory.hpp"
#include "map.hpp"
#include "dragon.hpp"
#include "treasure.hpp"

class Player : public Entity
{
private:
    int bonusStrength;
    int bonusMana;
    int bonusHealth;
    int armor;
    Race race;
    Inventory inventory;
public:
    Player(Race _race);

    Race& getRace() { return race; }

    virtual void attack(Entity& target);

    virtual void castSpell(Entity& target);

    virtual void takeDamage(int damage);

    void printInventory() const;

    void move(Map& map);

    void levelUp();

    void specialCheck(Map& map);

    void handleLocation(Map& map);

    void engage(Entity& dragon);

    void foundTreasure(Treasure& treasure);

    void restoreHealth();

    void exit();
};


#endif // !__PLAYER_HPP



