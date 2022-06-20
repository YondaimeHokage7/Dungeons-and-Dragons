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

/// A class representing an entity of type Player
class Player : public Entity
{
private:
    /// Bonus strength points added by the player after leveling up
    int bonusStrength;
    /// Bonus mana points added by the player after leveling up
    int bonusMana;
    /// Bonus health points added by the player after leveling up
    int bonusHealth;
    /// The race of the player
    Race race;
    /// The inventory of the player
    Inventory inventory;
public:
    /// Parameter Constructor
    Player(Race _race);
    /// Starts the game 
    void start(Map& map, bool newCharacter = 1);
    /// Race getter
    const Race& getRace() const { return race; }
    /// A function that is executed when the player performs a basic attack
    void attack(Entity& target);
    /// A function that is executed when the player casts a spell
    void castSpell(Entity& target);
    /// A function that is executed when the player is attacked
    void takeDamage(int damage);
    /// A function printing the inventory
    void printInventory(std::ostream& os = std::cout) const;
    /// A function used to move the player around the map
    void move(Map& map);
    /// A function increasing the level of the player by 1
    void levelUp();
    /// A function checking if there is a monster/treasure on the current position
    void specialCheck(Map& map);
    /// A function handling the process of moving, checking for a mosnter/treasure and printing appropriate messages
    void handleLocation(Map& map);
    /// A function that is executed when a player engages a dragon
    void engage(Entity& dragon);
    /// A function that is executed when a treasure is found
    void foundTreasure(Treasure& treasure);
    /// Bonus strength getter
    int getBonusStrength() const { return bonusStrength; }
    /// Bonus mana getter
    int getBonusMana() const { return bonusMana; }
    /// Bonus Health getter
    int getBonusHealth() const { return bonusHealth; }
    /// A function triggered after the end of a battle restoring the health of the player to 50%
    void restoreHealth();
    /// Inventory getter
    const Inventory& getInventory() const;
    /// Overloaded >> operator
    friend std::istream& operator>>(std::istream& is, Player& player);
};
/// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Player& player);

#endif // !__PLAYER_HPP



