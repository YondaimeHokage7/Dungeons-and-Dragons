#include "gameplayFunctions.hpp"
#include "functions.hpp"

void battle(Player& player, Dragon& dragon)
{
    int first{randomBetween(0, 1)};
    if (first == 0)
    {
        while (player.getHealth() > 0 && dragon.getHealth() > 0)
        {
            dragon.engage(player);
            if (player.getHealth() > 0)
            {
                player.engage(dragon);
            }
        }
    }
    else
    {
        while (player.getHealth() > 0 && dragon.getHealth() > 0)
        {
            player.engage(dragon);
            if (dragon.getHealth() > 0)
            {
                dragon.engage(player);
            }
        }
    }
}