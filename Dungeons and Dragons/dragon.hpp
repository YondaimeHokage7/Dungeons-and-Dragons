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

    virtual void attack(Entity&);

    virtual void castSpell(Entity&);

    virtual void takeDamage(int damage);

    void levelUp();

    void engage(Entity& entity);
};

#endif // !__DRAGON_HPP