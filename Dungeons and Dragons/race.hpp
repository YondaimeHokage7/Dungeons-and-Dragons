#ifndef __RACE_HPP
#define __RACE_HPP

#include <string>

class Race
{
private:
    std::string race;
    int strength;
    int mana;
    int health;
public:
    Race(std::string _race = "Generic", int _strength = 0, int _mana = 0, int _health = 0);

    int getRaceStrength() const
    {
        return strength;
    }

    int getRaceMana() const
    {
        return mana;
    }

    int getRaceHealth() const
    {
        return health;
    }

    std::string getName() const
    {
        return race;
    }

};

#endif // !__RACE_HPP
