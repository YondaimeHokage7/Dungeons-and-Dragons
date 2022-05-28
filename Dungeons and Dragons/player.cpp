#include "player.hpp"

Player::Player(Race _race) : race(_race), Entity(_race.getRaceStrength(),_race.getRaceMana(),_race.getRaceHealth())
{}

std::string Player::getRace() const
{
    return race.getName();
}

