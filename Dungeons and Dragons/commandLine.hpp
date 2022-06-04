#pragma once
#include <string>
#include <fstream>
#include <iostream>

class CommandLine
{
private:
    const std::string validCommands[6] = {"Open", "Close", "Save", "Save as", "Help", "Exit"};
    std::string command;
    std::string arguments;
public:
    CommandLine();

    void userInput();

    void open();
    void close();
    void save();
    void saveAs();
    void help();
    void exit();

    void executeCommand();
};

