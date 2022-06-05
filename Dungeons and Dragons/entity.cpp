#include "entity.hpp"

Entity::Entity(int _level, int _strength, int _mana, int _health, CellIndex _position) : level(_level), strength(_strength), mana(_mana), health(_health), position(0, 0)
{}

void Entity::setLevel(int _level)
{
    level = _level;
}

void Entity::setStrength(int _strength)
{
    strength = _strength;
}

void Entity::setMana(int _mana)
{
    mana = _mana;
}

void Entity::setHealth(int _health)
{
    health = _health;
}

void Entity::setPosition(CellIndex _index)
{
    position = _index;
}
