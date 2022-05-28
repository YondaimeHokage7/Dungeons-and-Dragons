#ifndef __ENTITY_HPP
#define __ENTITY_HPP

class Entity
{
private:
    int strength;
    int mana;
    int health;

    void takeDamage(int damage);

public:
    Entity(int _strength = 0, int _mana = 0, int _health = 0);

    void attack(Entity&);

    void castSpell(Entity&);
};


#endif // !__ENTITY_HPP

