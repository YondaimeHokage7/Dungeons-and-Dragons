#ifndef __DRAGON_HPP
#define __DRAGON_HPP

#include "entity.hpp"

class Dragon : public Entity
{
private:
    static int numberOfDragons;
    int scales;
public:
    Dragon(int _level = 1, CellIndex _position = (0, 0));

    void attack(Entity&);

    void castSpell(Entity&);

    void takeDamage(int damage);

    void levelUp();
};

#endif // !__DRAGON_HPP