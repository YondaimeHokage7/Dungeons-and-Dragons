#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "player.hpp"
#include "map.hpp"


class CommandLine
{
private:
    std::string currentlyOpened;
    std::string command;
    std::string arguments;
public:

    CommandLine();


    void userInput();
    void ensureValidCommand();
    void startGame();
    void loadGame();
    void open();
    void close();
    void save(const Player& player, const Map& map);
    void save();
    void saveAs(const Player& player, const Map& map);
    void saveAs();
    void help();
    void exitProgram(const Player& player, const Map& map);
    void exitCommandLine();

    void executeCommand();


    std::string getCurrentlyOpened() const { return currentlyOpened; }
    std::string getCommand() const { return command; }
    std::string getArguments() const { return arguments; }
};

