#pragma once
#include <string>
#include <fstream>
#include <iostream>

// The idea for extern is from here: https://stackoverflow.com/a/19929727
extern std::string currentlyOpened;
extern std::string command;
extern std::string arguments;

void userInput();
void open();
void close();
void save();
//void saveAs();
void help();
void exitProgram();
void executeCommand();

