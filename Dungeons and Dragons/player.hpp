#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "entity.hpp"
#include "race.hpp"
#include "human.hpp"
#include "mage.hpp"
#include "warrior.hpp"

class Player : public Entity
{
private:
    Race race;
public:
    Player(Race _race);

    std::string getRace() const;

};


#endif // !__PLAYER_HPP
