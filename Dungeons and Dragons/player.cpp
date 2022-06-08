#include "player.hpp"
#include "treasure.hpp"
#include "gameplayFunctions.hpp"

Player::Player(Race _race) : race(_race), armor(0), Entity(1, _race.getRaceStrength(), _race.getRaceMana(), _race.getRaceHealth(), (0, 0))
{
    bonusStrength = 0.5 + (double)inventory.getStrengthModifier() / 100 * getStrength();
    bonusMana = 0.5 + (double)inventory.getSpellModifier() / 100 * getMana();
    setStrength(0.5 + (getStrength() + bonusStrength));
    setMana(0.5 + (getMana() + bonusMana));
}

void Player::attack(Entity& target)
{
    target.takeDamage(0.5 + (getStrength() + (double)inventory.getStrengthModifier() / 100 * getStrength()));
}

void Player::castSpell(Entity& target)
{
    target.takeDamage(0.5 + (getMana() + (double)inventory.getSpellModifier() / 100 * getMana()));
}

void Player::takeDamage(int damage)
{
    setHealth(0.5 + (getHealth() - damage - ((double)inventory.getArmorModifier() / 100 * damage)));
    std::cout << "You took " << (int)(damage - ((double)inventory.getArmorModifier() / 100 * damage)) << " damage\n";
}

void Player::printInventory() const
{
    inventory.print();
}

void Player::move(Map& map)
{
    char answers[4][6]{"Up", "Down", "Left", "Right"};
    char direction[6];
    char answer[4];
    while (/*getPosition() != CellIndex(map.getRows() - 1, map.getColumns() - 1)*/!myStrcmp(direction, "Exit"))
    {
        //std::cout << "Current coordinates: " << getPosition() << '\n';
        //std::cout << "Target: " << CellIndex(map.getRows() - 1, map.getColumns() - 1) << '\n';
        std::cout << "Where would you like to go?\n";
        std::cin.getline(direction, 6, '\n');
        if (myStrcmp(direction, answers[0]) && areConnected(getPosition(), getPosition().up(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved up!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().up());
            handleLocation(map);
            /*else if (getPosition() == 'T')
            {
                char keep[4];
                std::cout << "You've found a treasure!\n";
                Treasure treasure(map);
                std::cout << "The treasure you've found is: \n";
                std::cout << "Would you like to keep it?\n";
                if (myStrcmp(keep, "Yes"))
                {
                    if (treasure.getItem().getType() == "Weapon")
                    {
                        inventory.setWeapon(treasure.getItem());
                        setStrength(getStrength() - bonusStrength);
                        bonusStrength = (double)treasure.getItem().getModifier() / 100 * getStrength();
                        setStrength(getStrength() + bonusStrength);
                    }
                    else if (treasure.getItem().getType() == "Spell")
                    {
                        inventory.setSpell(treasure.getItem());
                        setMana(getMana() - bonusMana);
                        bonusMana = (double)treasure.getItem().getModifier() / 100 * getMana();
                        setMana(getMana() + bonusMana);
                    }
                    else if (treasure.getItem().getType() == "Armor")
                    {
                        inventory.setArmor(treasure.getItem());
                        armor = 0;
                        armor = treasure.getItem().getModifier();
                    }
                }
                else if (myStrcmp(keep, "No"))
                {
                    std::cout << "The item was destroyed!\n";
                }
            }*/
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();

        }
        else if (myStrcmp(direction, answers[1]) && areConnected(getPosition(), getPosition().down(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved down!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().down());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();
            /*if (getPosition() == CellIndex(map.getRows() - 1, map.getColumns() - 1))
            {
                std::cout << "You've reached the target location.\n";
                std::cout << "Would you like to go to the enxt level?";
                std::cin >> answer;
                if (myStrcmp(answer, "Yes"))
                {
                    this->levelUp();
                    map.levelUp();
                }
            }*/
        }
        else if (myStrcmp(direction, answers[2]) && areConnected(getPosition(), getPosition().left(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved left!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().left());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();

        }
        else if (myStrcmp(direction, answers[3]) && areConnected(getPosition(), getPosition().right(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved right!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().right());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();
        }
        else
        {
            if (myStrcmp(direction, answers[0]) || myStrcmp(direction, answers[1]) || myStrcmp(direction, answers[2]) || myStrcmp(direction, answers[3]))
            {
                std::cout << "You can't go there!";
            }
            else if (myStrcmp(direction, "Exit"))
            {
                //
            }
            else
            {
                std::cout << "Invalid input!";
                std::cin.clear();

            }
        }
    }
}

void Player::levelUp()
{
    int points{30};
    setLevel(getLevel() + 1);
    std::cout << "You reached level " << getLevel() << "!\n";
    std::cout << "You can now choose how to spend " << points << " points across your stats!\n";
    int strengthPoints{0};
    int manaPoints{0};
    int healthPoints{0};
    int answer;
    while (points > 0)
    {
        std::cout << "How many points would you like to add to your strength?\n";
        std::cin >> answer;
        ensureValidity(answer, points);
        strengthPoints = answer;
        points = points - strengthPoints;

        if (points > 0)
        {
            std::cout << "How many points would you like to add to your mana?\n";
            std::cin >> answer;
            ensureValidity(answer, points);
            manaPoints = answer;
            points = points - manaPoints;
        }

        if (points > 0)
        {
            std::cout << "How many points would you like to add to your mana?\n";
            std::cin >> answer;
            ensureValidity(answer, points);
            healthPoints = answer;
            points = points - healthPoints;
        }
    }
    setStrength(getStrength() + strengthPoints);
    setMana(getMana() + manaPoints);
    setHealth(getHealth() + healthPoints);
    setPosition(CellIndex(0, 0));
}

void Player::specialCheck(Map& map)
{
    if (map.getElement(getPosition()) == 'M')
    {
        std::cout << "Yikes! There is a dragon here!\n";
        Dragon dragon(map.getLevel(), getPosition());
        battle(*this, dragon);
        //if player.getHealth() <= 0 
    }
    else if (map.getElement(getPosition()) == 'T')
    {
        std::cout << "You've found a treasure!\n";
    }
    else if (map.getElement(getPosition()) == '.')
    {
        std::cout << "An ordinary place\n";
    }
}

void Player::handleLocation(Map& map)
{
    specialCheck(map);
    if (getPosition() == CellIndex(map.getRows() - 1, map.getColumns() - 1))
    {
        char answer[4];
        std::cout << "You've reached the target location.\n";
        std::cout << "Would you like to go to the next level?\n";
        std::cin >> answer;
        if (myStrcmp(answer, "Yes"))
        {
            this->levelUp();
            map.levelUp();
        }
        map.print();
    }
}

void Player::engage(Entity& entity)
{
    char answer[13];
    std::cout << "You are attacking!\n";
    std::cout << "How would you like to attack?\n";
    std::cin.getline(answer, 13, '\n');
    if (myStrcmp(answer, "Basic attack"))
    {
        attack(entity);
    }
    else if (myStrcmp(answer, "Cast a spell"))
    {
        castSpell(entity);
    }
}