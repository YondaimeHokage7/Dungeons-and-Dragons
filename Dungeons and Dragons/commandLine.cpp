#include "commandLine.hpp"


void userInput()
{
    std::cout << "Enter a command: \n";
    std::cin >> command;
    std::getline(std::cin, arguments);
    arguments.erase(0,1);
    executeCommand();
}

void executeCommand()
{
    if (command == "open")
    {
        open();
    }
    else if (command == "close")
    {
        close();
    }
    else if (command == "save")
    {
        save();
    }
    else if (command == "saveas")
    {
        //saveAs();
    }
    else if (command == "help")
    {
        help();
    }
    else if (command == "exit")
    {
        exitProgram();
    }
}

void open()
{
    if (currentlyOpened != "")
    {
        std::cout << currentlyOpened << " is currently opened!\n";
        std::cout << "Close it and then try opening another file!\n";
    }
    std::ifstream userFile(arguments, std::ios::in);
    std::ofstream blankFile;
    if (userFile.is_open())
    {
        std::cout << "Successfully opened " << arguments << "!\n";
    }
    else
    {
        std::cout << "The given file does not exist!\n";
        userFile.close();
        blankFile.open(arguments, std::ios::out | std::ios::trunc);
        if (blankFile.is_open())
        {
            std::cout << "Successfully created and opened " << arguments << "\n";
        }
        else
        {
            std::cerr << "There was an error creating the file " << arguments << "\n";
        }
    }
    currentlyOpened = arguments;
}

void close()
{
    if (currentlyOpened != "")
    {
        std::cout << "Successfully closed " << currentlyOpened << '\n';
        currentlyOpened = "";
    }
    else
    {
        std::cout << "There is no currently opened file!\n";
    }
}

void save()
{
    if (currentlyOpened == "")
    {
        std::cout << "There is no currently opened file!";
    }
    else
    {

    }
}

void help()
{
    std::cout << "The following commands are supported: \n";
    std::cout << "open <file> \t Opens <file>\n";
    std::cout << "close \t\t Closes the currently opened file\n";
    std::cout << "save \t\t Saves the currently opened file\n";
    std::cout << "saveas <file> \t saves the currently opened file in <file>\n";
    std::cout << "help \t\t Prints information about the available commands\n";
    std::cout << "exit \t\t Exits the program\n";
}

void exitProgram()
{
    if (currentlyOpened != "")
    {
        std::cout << "You have unsaved changes in " << currentlyOpened << "!\n";
        std::cout << "Please choose whether you would like to save them, close without saving or save them in another document\n";
        std::cin >> command;
        bool validCommand{false};
        while (!validCommand)
        {
            if (command == "close")
            {
                validCommand = true;
                std::cout << "Exiting without saving...\n";
                close();
            }
            else if (command == "save")
            {
                validCommand = true;
                //
            }
            else if (command == "saveas")
            {
                validCommand = true;
                //saveas
            }
        }

    }
    exit(0);
}