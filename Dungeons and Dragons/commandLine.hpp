#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "player.hpp"
#include "map.hpp"

/// A command line class
class CommandLine
{
private:
    /// A string representing the name of the currently opened file
    std::string currentlyOpened;
    /// A string representing the command that needs to be executed
    std::string command;
    /// A string representing the arguments of the entered command
    std::string arguments;
public:

    /// Default constructor
    CommandLine();
    /// A Function that gets the user input
    void userInput();
    /// A Function that ensures a valdi command was entered
    void ensureValidCommand();
    /// A function that starts a new game
    void startGame();
    /// A function that loads the game
    void loadGame();
    /// A function that opens a file
    void open();
    /// A function that closes the currently opened file
    void close();
    /// A function that saves the progress of a given player on a given map in the currently opened file
    void save(const Player& player, const Map& map);
    /// A function that saves the changes made to the currently opened file
    void save();
    /// A function that saces the progress of a given player on a given map in a specified file
    void saveAs(const Player& player, const Map& map);
    /// A function that saves the changes made to the currently opened file in a specified file
    void saveAs();
    /// A function that prints help information
    void help();
    /// A function that exits the game
    void exitProgram(const Player& player, const Map& map);
    /// A function that exits the command line
    void exitCommandLine();
    /// A function that executes the appropriate command
    void executeCommand();
    /// A getter for the currently opened file
    std::string getCurrentlyOpened() const { return currentlyOpened; }
    /// A getter for the command
    std::string getCommand() const { return command; }
    /// A getter for the arguments of the command
    std::string getArguments() const { return arguments; }
};

