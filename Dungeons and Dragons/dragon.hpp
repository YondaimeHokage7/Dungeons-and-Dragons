#ifndef __DRAGON_HPP
#define __DRAGON_HPP

#include "entity.hpp"

class Dragon : public Entity
{
private:
    const static int scales = 15;
public:
    Dragon();

    void attack(Entity&, int attackDamage);

    void castSpell(Entity&, int spellDamage);

    void takeDamage(int damage);
};

#endif // !__DRAGON_HPP