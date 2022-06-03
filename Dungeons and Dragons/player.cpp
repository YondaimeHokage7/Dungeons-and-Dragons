#include "player.hpp"
#include <iostream>


Player::Player(Race _race) : level(1), position(CellIndex(0, 0)), race(_race), Entity(_race.getRaceStrength(), _race.getRaceMana(), _race.getRaceHealth())
{
    setStrength(0.5 + (getStrength() + (double)inventory.getStrengthModifier() / 100 * getStrength()));
    setMana(0.5 + (getMana() + (double)inventory.getSpellModifier() / 100 * getMana()));
}

void Player::attack(Entity& target)
{
    target.takeDamage(0.5 + (getStrength() + (double)inventory.getStrengthModifier() / 100 * getStrength()));
}

void Player::castSpell(Entity& target)
{
    target.takeDamage(0.5 + (getMana() + (double)inventory.getSpellModifier() / 100 * getMana()));
}

void Player::takeDamage(int damage)
{
    setHealth(0.5 + (getHealth() - damage - (double)(inventory.getArmorModifier() / 100 * damage)));
}

void Player::move(Map& map)
{
    char answers[4][6]{"Up", "Down", "Left", "Right"};
    char direction[6];
    std::cout << "Where would you like to go?\n";
    std::cin.getline(direction, 6, '\n');
    if (myStrcmp(direction, answers[0]) && areConnected(position, position.up(), map.getConnections(), map.getSize()))
    {
        std::cout << "You moved up!\n";
        map.setElement(position.getRow(), position.getColumn(), '.');
        position = position.up();
        map.setElement(position.getRow(), position.getColumn(), 'X');
        map.print();
    }
    else if (myStrcmp(direction, answers[1]) && areConnected(position, position.down(), map.getConnections(), map.getSize()))
    {
        std::cout << "You moved down!\n";
        map.setElement(position.getRow(), position.getColumn(), '.');
        position = position.down();
        map.setElement(position.getRow(), position.getColumn(), 'X');
        map.print();
    }
    else if (myStrcmp(direction, answers[2]) && areConnected(position, position.left(), map.getConnections(), map.getSize()))
    {
        std::cout << "You moved left!\n";
        map.setElement(position.getRow(), position.getColumn(), '.');
        position = position.left();
        map.setElement(position.getRow(), position.getColumn(), 'X');
        map.print();
    }
    else if (myStrcmp(direction, answers[3]) && areConnected(position, position.right(), map.getConnections(), map.getSize()))
    {
        std::cout << "You moved right!\n";
        map.setElement(position.getRow(), position.getColumn(), '.');
        position = position.right();
        map.setElement(position.getRow(), position.getColumn(), 'X');
        map.print();
    }
}