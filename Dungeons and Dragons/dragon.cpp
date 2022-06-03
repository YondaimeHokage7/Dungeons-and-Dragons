#include "dragon.hpp"

int Dragon::numberOfDragons = 0;

Dragon::Dragon(int _level, CellIndex _position) : scales(15), Entity(_level, (_level - 1) * 10 + 25, (_level - 1) * 10 + 25, (_level - 1) * 10 + 50, _position)
{
    for (int i{0}; i < _level - 1; i++)
    {
        levelUp();
    }
    numberOfDragons++;
}

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
}

void Dragon::levelUp()
{
    setLevel(getLevel() + 1);
    scales = scales + (double)5 / 100 * scales;
    setStrength(getStrength() + 10);
    setMana(getMana() + 10);
    setHealth(getHealth() + 10);
}
