#include "dragon.hpp"

Dragon::Dragon() : Entity(25, 25, 50)
{}

void Dragon::attack(Entity& target)
{
    target.takeDamage(getStrength());
}

void Dragon::castSpell(Entity& target)
{
    target.takeDamage(getMana());
}

void Dragon::takeDamage(int damage)
{
    setHealth(0.5 + (getHealth() - (damage - (double)scales / 100 * damage)));
    //health = health - (damage - scales / 100 * damage);
}