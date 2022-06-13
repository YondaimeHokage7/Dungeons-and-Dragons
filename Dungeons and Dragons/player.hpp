#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "human.hpp"
#include "mage.hpp"
#include "entity.hpp"
#include "race.hpp"
#include "inventory.hpp"
#include "map.hpp"
#include "dragon.hpp"
#include "treasure.hpp"
#include <iostream>

class Player : public Entity
{
private:
    int bonusStrength;
    int bonusMana;
    int bonusHealth;
    Race race;
    Inventory inventory;
public:
    Player(Race _race);

    void start(Map& map, bool newCharacter = 1);
    
    const Race& getRace() const { return race; } //ako ne raboti mahni const

    virtual void attack(Entity& target);

    virtual void castSpell(Entity& target);

    virtual void takeDamage(int damage);

    void printInventory(std::ostream& os = std::cout) const;

    void move(Map& map);

    void levelUp();

    void specialCheck(Map& map);

    void handleLocation(Map& map);

    void engage(Entity& dragon);

    void foundTreasure(Treasure& treasure);

    int getBonusStrength() const { return bonusStrength; }

    int getBonusMana() const { return bonusMana; }

    int getBonusHealth() const { return bonusHealth; }

    void restoreHealth();

    const Inventory& getInventory() const;

    friend std::istream& operator>>(std::istream& is, Player& player);

};

std::ostream& operator << (std::ostream& os, const Player& player);

#endif // !__PLAYER_HPP



