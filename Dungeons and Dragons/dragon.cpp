#include "dragon.hpp"

Dragon::Dragon() : Entity(25, 25, 50)
{}

void Dragon::attack(Entity& target, int attackDamage)
{
    target.takeDamage(attackDamage);
}

void Dragon::castSpell(Entity& target, int spellDamage)
{
    target.takeDamage(spellDamage);
}

void Dragon::takeDamage(int damage)
{
    setHealth(0.5 + (getHealth() - (damage - (double)scales / 100 * damage)));
    //health = health - (damage - scales / 100 * damage);
}