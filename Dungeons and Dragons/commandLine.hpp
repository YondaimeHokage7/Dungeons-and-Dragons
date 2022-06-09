#pragma once
#include <string>
#include <fstream>
#include <iostream>

class CommandLine
{
private:
    std::string currentlyOpened;
    std::string command;
    std::string arguments;
public:
    CommandLine();

    void userInput();

    void open();
    void close();
    void save();
    //void saveAs();
    void help();
    void exitProgram();

    void executeCommand();

    std::string getCurrentlyOpened() const { return currentlyOpened; }
    std::string getCommand() const { return command; }
    std::string getArguments() const { return arguments; }
};

