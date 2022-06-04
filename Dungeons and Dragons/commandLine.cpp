#include "commandLine.hpp"



CommandLine::CommandLine() : command(""), arguments("")
{}

void CommandLine::userInput()
{
    std::cout << "Enter a command!";
    std::cin >> command;
    std::getline(std::cin, arguments);
    executeCommand();
}

void CommandLine::executeCommand()
{
    if (command == validCommands[0])
    {
        open();
    }
    else if (command == validCommands[1])
    {
        //close();
    }
    else if (command == validCommands[2])
    {
        //save();
    }
    else if (command == validCommands[3])
    {
        //saveAs();
    }
    else if (command == validCommands[4])
    {
        //help();
    }
    else if (command == validCommands[5])
    {
        //exit();
    }
}

void CommandLine::open()
{
    std::ifstream userFile(arguments, std::ios::in);
    std::ofstream blankFile;
    if (userFile.is_open())
    {
        std::cout << "Successfully opened " << arguments << "!\n";
    }
    else
    {
        std::cout << "The given file does not exist!";
        blankFile.open(arguments, std::ios::out | std::ios::trunc);
        if (blankFile.is_open())
        {
            std::cout << "Successfully created and opened " << arguments << "!\n";
        }
        else
        {
            std::cout << "There was an error creating " << arguments << "\n";
        }
    }
}
