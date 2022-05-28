#ifndef __RACE_HPP
#define __RACE_HPP

#include <string>

class Race
{
private:
    std::string name;
    int strength;
    int mana;
    int health;
public:
    Race(std::string _name = "Generic", int _strength = 0, int _mana = 0, int _health = 0);

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
        return name;
    }

};

#endif // !__RACE_HPP
