#pragma once

#include "cellIndex.hpp"

class Entity
{
private:
    int level;
    int strength;
    int mana;
    int health;
    CellIndex position;
public:
    Entity(int _level = 1, int _strength = 0, int _mana = 0, int _health = 0, CellIndex _position = (0, 0));

    int getLevel() const { return level; }

    int getStrength() const { return strength; }

    int getMana() const { return mana; }

    int getHealth() const { return health; }

    void setPosition(CellIndex _index) { position = _index; }

    void setLevel(int _level);

    void setStrength(int _strength);

    void setMana(int _mana);

    void setHealth(int _health);

    CellIndex& getPosition() { return position; }

    virtual void attack(Entity& target) = 0;

    virtual void castSpell(Entity& target) = 0;

    virtual void takeDamage(int damage) = 0;

    virtual void levelUp() = 0;
};
