#ifndef __DRAGON_HPP
#define __DRAGON_HPP

#include "entity.hpp"

/// A class representing an entity of type Dragon
class Dragon : public Entity
{
private:
    /// A static integer keeping track of the number of dragon generated
    static int numberOfDragons;

    /// An integer holding the scales block %
    int scales;

public:
    /// Default parameter constructor
    Dragon(int _level = 1, CellIndex _position = (0, 0));

    /// A function that performs a basic attack on a given entity
    void attack(Entity&);

    /// A function that casts a a spell on a given entity
    void castSpell(Entity&); 

    /// A function that deals damage to the object
    void takeDamage(int damage); 

    /// A function that increases the dragon level
    void levelUp();

    /// A function that is called when the dragon engages in a battle with another entity
    void engage(Entity& entity);

};

#endif // !__DRAGON_HPP