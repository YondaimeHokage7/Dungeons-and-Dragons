#include "entity.hpp"

Entity::Entity(int _strength, int _mana, int _health) : strength(_strength), mana(_mana), health(_health)
{}

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
