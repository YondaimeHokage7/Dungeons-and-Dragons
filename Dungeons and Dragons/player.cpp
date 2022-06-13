#include "warrior.hpp"
#include "player.hpp"
#include "treasure.hpp"
#include "gameplayFunctions.hpp"

Player::Player(Race _race) : race(_race), bonusHealth(0), Entity(1, _race.getRaceStrength(), _race.getRaceMana(), _race.getRaceHealth(), (0, 0))
{
    bonusStrength = 0.5 + (double)inventory.getStrengthModifier() / 100 * getStrength();
    bonusMana = 0.5 + (double)inventory.getSpellModifier() / 100 * getMana();
    setStrength(0.5 + (getStrength() + bonusStrength));
    setMana(0.5 + (getMana() + bonusMana));
}

void Player::start(Map& map, bool newCharacter)
{
    if (newCharacter)
    {
        std::cout << "Please choose a race\n";
        std::cout << "Available races: \n";
        std::cout << "Human\n";
        std::cout << "Mage\n";
        std::cout << "Warrior\n";
        std::string race;
        std::cin.ignore();
        std::getline(std::cin, race,'\n');
        if (race == "Human")
        {
            Player newplayer = Human();
            *this = newplayer;
        }
        else if (race == "Mage")
        {
            Player newplayer = Mage();
            *this = newplayer;
        }
        else if (race == "Warrior")
        {
            Player newPlayer = Warrior();
            *this = newPlayer;
        }
        while (race != "Human" && race != "Mage" && race != "Warrior")
        {
            std::cout << "That's not a valid race!\n";
            std::cout << "Enter a new race:\n";
            std::getline(std::cin, race);
        }
        std::cout << "Successfully created a " << this->getRace().getName() << '\n';

    }
    this->move(map);
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
    setHealth(0.5 + (getHealth() - (damage - ((double)inventory.getArmorModifier() / 100 * damage))));
    std::cout << "You took " << (int)(0.5 + damage - ((double)inventory.getArmorModifier() / 100 * damage)) << " damage\n";
}

void Player::printInventory(std::ostream& os) const
{
    inventory.print(os);
}

void Player::move(Map& map)
{
    std::string answers[4]{"Up", "Down", "Left", "Right"};
    std::string direction;
    std::string answer;
    while (direction != "exit")
    {
        map.print();
        std::cout << "Where would you like to go?\n";
        std::getline(std::cin, direction);
        if (direction == answers[0] && areConnected(getPosition(), getPosition().up(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved up!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().up());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
        }
        else if (direction == answers[1] && areConnected(getPosition(), getPosition().down(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved down!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().down());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
        }
        else if (direction == answers[2] && areConnected(getPosition(), getPosition().left(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved left!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().left());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
        }
        else if (direction == answers[3] && areConnected(getPosition(), getPosition().right(), map.getConnections(), map.getNumberOfConnections()))
        {
            std::cout << "You moved right!\n";
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), '.');
            setPosition(getPosition().right());
            handleLocation(map);
            map.setElement(CellIndex(getPosition().getRow(), getPosition().getColumn()), 'X');
        }
        else
        {
            if (direction == answers[0] || direction == answers[1] || direction == answers[2] || direction == answers[3])
            {
                std::cout << "You can't go there!\n";
            }
            else if (direction == "exit")
            {
                std::cout << "Exiting...";
            }
            else
            {
                std::cout << "Invalid input!\n";
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
            std::cout << "How many points would you like to add to your health?\n";
            std::cin >> answer;
            ensureValidity(answer, points);
            bonusHealth = healthPoints = answer;
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
        std::cout << "Yikes! A dragon!\n";
        Dragon dragon(map.getLevel(), getPosition());
        battle(*this, dragon);
        map.remainingMonsters--;
    }
    else if (map.getElement(getPosition()) == 'T')
    {
        std::cout << "You've found a treasure!\n";
        Treasure treasure(map);
        foundTreasure(treasure);
        map.remainingTreasures--;
    }
}

void Player::handleLocation(Map& map)
{
    specialCheck(map);
    bool isDead{false};
    if (getHealth() <= 0)
    {
        std::cout << "You lost!\n";
        exit(0);
    }
    if (getPosition() == CellIndex(map.getRows() - 1, map.getColumns() - 1))
    {
        std::string answer;
        std::cout << "You've reached the target location.\n";
        std::cout << "Would you like to go to the next level?\n";
        std::getline(std::cin, answer);
        if (answer == "Yes")
        {
            this->levelUp();
            map.levelUp();
        }
    }
}

void Player::engage(Entity& entity)
{
    std::string answer;
    std::cout << "You are attacking!\n";
    std::cout << "How would you like to attack?\n";
    std::getline(std::cin, answer);
    if (answer == "Basic attack")
    {
        attack(entity);
    }
    else if (answer == "Cast a spell")
    {
        castSpell(entity);
    }
}

void Player::foundTreasure(Treasure& treasure)
{
    std::string answer;
    std::cout << treasure.getItem();
    std::cout << "Your inventory: \n";
    printInventory();
    std::cout << "Would you like to keep " << treasure.getItem().getName() << "?\n";
    std::getline(std::cin, answer);
    if (answer == "Yes")
    {
        inventory.add(treasure.getItem());
    }
}

void Player::restoreHealth()
{
    if (getHealth() > 0 && getHealth() < (int)(0.5 + (double)this->getRace().getRaceHealth() + bonusHealth) / 2)
    {
        setHealth(0.5 + (double)this->getRace().getRaceHealth() / 2);
        std::cout << "Your health was restored to " << (int)((double)(this->getRace().getRaceHealth() + bonusHealth) / 2) << '\n';
    }
}

const Inventory& Player::getInventory() const
{
    return inventory;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << player.getLevel() << ' ' << player.getStrength() << ' ' << player.getMana() << ' ' << player.getHealth() << ' '
        << player.getBonusStrength() << ' ' << player.getBonusMana() << ' ' << player.getBonusHealth() << '\n' << player.getRace().getName() << '\n' << player.getInventory();
    return os;
}

std::istream& operator>>(std::istream& is, Player& player)
{
    std::string _race;
    int _level;
    int _strength;
    int _mana;
    int _health;
    is >> _level >> _strength >> _mana >> _health >> player.bonusStrength >> player.bonusMana >> player.bonusHealth;
    is >> _race;
    if (_race == "Human")
        player.race = Human();
    else if (_race == "Mage")
        player.race = Mage();
    else if (_race == "Warrior")
        player.race = Warrior();
    player.setLevel(_level);
    player.setStrength(_strength);
    player.setMana(_mana);
    player.setHealth(_health);
    is >> player.inventory;
    return is;
}