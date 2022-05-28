#ifndef __ENTITY_HPP
#define __ENTITY_HPP

class Entity
{
private:
    int strength;
    int mana;
    int health;
public:
    Entity(int _strength = 0, int _mana = 0, int _health = 0);

    void attack(Entity&);

    void castSpell(Entity&);

    void takeDamage(int damage);

};


#endif // !__ENTITY_HPP

