#include "player.hpp"
#include <iostream>


Player::Player(Race _race) : level(1), race(_race), Entity(_race.getRaceStrength(), _race.getRaceMana(), _race.getRaceHealth())
{
    setStrength(0.5 + (getStrength() + (double)inventory.getStrengthModifier() / 100 * getStrength()));
    setMana(0.5 + (getMana() + (double)inventory.getSpellModifier() / 100 * getMana()));
    //mana = mana + (double)inventory.getSpellModifier() / 100 * mana;
    //strength = strength + (double)inventory.getStrengthModifier() / 100 * strength;
}

std::string Player::getRace() const
{
    return race.getName();
}

void Player::attack(Entity& target)
{
    target.takeDamage(0.5 + (double)(getStrength() + inventory.getStrengthModifier() / 100 * getStrength()));
}

void Player::castSpell(Entity& target)
{
    target.takeDamage(0.5 + (double)(getMana() + inventory.getSpellModifier() / 100 * getMana()));
}

void Player::takeDamage(int damage)
{
    setHealth(0.5 + (getHealth() - damage - (double)(inventory.getArmorModifier() / 100 * damage)));
    //health = health - (damage - inventory.getArmorModifier() / 100 * damage);
}

void Player::printInventory() const
{
    inventory.print();
}