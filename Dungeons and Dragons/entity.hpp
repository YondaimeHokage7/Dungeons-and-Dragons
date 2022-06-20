#pragma once

#include "cellIndex.hpp"

/// A class representing an entity
class Entity
{
private:
    /// Entity level
    int level;

    /// Entity strength
    int strength;

    /// Entity mana
    int mana;

    /// Entity health
    int health;

    /// Entity position
    CellIndex position;

public:
    /// Default parameter constructor
    Entity(int _level = 1, int _strength = 0, int _mana = 0, int _health = 0, CellIndex _position = (0, 0));

    /// Level getter
    int getLevel() const { return level; }

    /// Strength getter
    int getStrength() const { return strength; }

    /// Mana getter
    int getMana() const { return mana; }

    /// Health getter
    int getHealth() const { return health; }

    /// Position setter
    void setPosition(CellIndex _index) { position = _index; }

    /// Level setter
    void setLevel(int _level);

    /// Strength setter
    void setStrength(int _strength);

    /// Mana setter
    void setMana(int _mana);

    /// Health setter
    void setHealth(int _health);

    /// Position getter
    CellIndex& getPosition() { return position; }

    /// A pure virtual attack function
    virtual void attack(Entity& target) = 0;

    /// A pure virtual castSpell function
    virtual void castSpell(Entity& target) = 0;

    /// A pure virtual takeDamage function
    virtual void takeDamage(int damage) = 0;

    /// A pure virtual levelup function
    virtual void levelUp() = 0;

};
