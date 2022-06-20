#ifndef __RACE_HPP
#define __RACE_HPP

#include <string>

/// A class representing a race
class Race
{
private:
    /// Race name
    std::string name;

    /// Race strength
    int strength;

    /// Race mana
    int mana;

    /// Race health
    int health;
public:
    /// Default parameter constructor
    Race(std::string _name = "Generic", int _strength = 0, int _mana = 0, int _health = 0);

    /// Race strength getter
    int getRaceStrength() const { return strength; }

    /// Race mana getter
    int getRaceMana() const { return mana; }

    /// Race health getter
    int getRaceHealth() const { return health; }

    /// Race name getter
    std::string getName() const { return name; }
};

#endif // !__RACE_HPP
