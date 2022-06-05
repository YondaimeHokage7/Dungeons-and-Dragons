#include "player.hpp"
#include "functions.hpp"
#include <iostream>


Player::Player(Race _race) : race(_race), Entity(1, _race.getRaceStrength(), _race.getRaceMana(), _race.getRaceHealth(), (0, 0))
{
    setStrength(0.5 + (getStrength() + (double)inventory.getStrengthModifier() / 100 * getStrength()));
    setMana(0.5 + (getMana() + (double)inventory.getSpellModifier() / 100 * getMana()));
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
    setHealth(0.5 + (getHealth() - damage - (double)(inventory.getArmorModifier() / 100 * damage)));
}

void Player::move(Map& map)
{
    char answers[4][6]{"Up", "Down", "Left", "Right"};
    char direction[6];
    while (getPosition() != CellIndex(map.getRows() - 1, map.getColumns() - 1))
    {
        std::cout << "Current coordinates: " << getPosition() << '\n';
        std::cout << "Target: " << CellIndex(map.getRows() - 1, map.getColumns() - 1) << '\n';
        std::cout << "Where would you like to go?\n";
        std::cin.getline(direction, 6, '\n');
        if (myStrcmp(direction, answers[0]) && areConnected(getPosition(), getPosition().up(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved up!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            getPosition() = getPosition().up();
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();
        }
        else if (myStrcmp(direction, answers[1]) && areConnected(getPosition(), getPosition().down(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved down!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            getPosition() = getPosition().down();
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();
        }
        else if (myStrcmp(direction, answers[2]) && areConnected(getPosition(), getPosition().left(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved left!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            getPosition() = getPosition().left();
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();
        }
        else if (myStrcmp(direction, answers[3]) && areConnected(getPosition(), getPosition().right(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved right!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            getPosition() = getPosition().right();
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
            map.print();
        }
        else
        {
            if (myStrcmp(direction, answers[0]) || myStrcmp(direction, answers[1]) || myStrcmp(direction, answers[2]) || myStrcmp(direction, answers[3]))
            {
                std::cout << "You can't go there!";
            }
            else
            {
                std::cout << "Invalid input!";
            }
        }
    }
    std::cout << "You've reached the target position!\n";
    std::cout << "Would you like to go to the next level?\n";
    char answer[4];
    char yes[4]{"Yes"};
    std::cin.getline(answer, 4, '\n');
    if (myStrcmp(answer, yes))
    {
        this->levelUp();
        map.levelUp();
    }
    map.print();
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
}