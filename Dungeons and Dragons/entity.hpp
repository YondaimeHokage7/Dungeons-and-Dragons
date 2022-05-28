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

    int getStrength() const { return strength; }

    int getMana() const { return mana; }

    int getHealth() const { return health; }

    virtual void attack(Entity&, int attackDamage) = 0;

    virtual void castSpell(Entity&, int spellDamage) = 0;

    virtual void takeDamage(int damage) = 0;

    void setStrength(int _strength);

    void setMana(int _mana);

    void setHealth(int _health);
};


#endif // !__ENTITY_HPP

