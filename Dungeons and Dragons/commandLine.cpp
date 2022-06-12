#include "commandLine.hpp"
#include "map.hpp"
#include "player.hpp"

CommandLine::CommandLine() : command(""), arguments(""), currentlyOpened("")
{}

void CommandLine::userInput()
{
    while (1)
    {
        std::cout << "Enter a command: \n";
        std::cin >> command;
        std::getline(std::cin, arguments);
        ensureValidCommand();
        arguments.erase(0, 1);
        executeCommand();
    }
}

void CommandLine::ensureValidCommand()
{
    while (command != "open" && command != "close" && command != "save" && command != "saveas" && command != "help" && command != "exit")
    {
        std::cout << "Invalid input!\n";
        help();
        std::cout << "Enter a command: \n";
        std::cin >> command;
    }
}

void CommandLine::startGame()
{
    std::cout << "Would you like to start playing?\n";
    char answer[4];
    std::cin.getline(answer, 4, '\n');
    if (myStrcmp(answer, "Yes"))
    {
        Player player = Human();
        Map map(1);
        player.start(map);
    }
}

void CommandLine::loadGame()
{
    std::cout << "Loading...";
    Player player = Human();
    Map map(1);
    std::ifstream saveFile(arguments, std::ios::in);
    saveFile >> player;
    saveFile >> map;
    std::cout << "Successfully loaded " << player.getRace().getName() << " level " << player.getLevel() << '\n';
    player.start(map,0);
}

void CommandLine::executeCommand()
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
        //save();
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

void CommandLine::open()
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
        //startGame(); NE! Tuk e load game ne startGame
        loadGame();
    }
    else
    {
        std::cout << "The given file does not exist!\n";
        userFile.close();
        blankFile.open(arguments, std::ios::out | std::ios::trunc);
        if (blankFile.is_open())
        {
            std::cout << "Successfully created and opened " << arguments << "\n";
            startGame();
        }
        else
        {
            std::cerr << "There was an error creating the file " << arguments << "\n";
        }
    }
    currentlyOpened = arguments;

}

void CommandLine::close()
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


void CommandLine::save()
{
    if (currentlyOpened == "")
    {
        std::cout << "There is no currently opened file!";
    }
    else
    {

    }
}

/*void CommandLine::saveAs()
{

}
*/

void CommandLine::help()
{
    std::cout << "The following commands are supported: \n";
    std::cout << "open <file> \t Opens <file>\n";
    std::cout << "close \t\t Closes the currently opened file\n";
    std::cout << "save \t\t Saves the currently opened file\n";
    std::cout << "saveas <file> \t saves the currently opened file in <file>\n";
    std::cout << "help \t\t Prints information about the available commands\n";
    std::cout << "exit \t\t Exits the program\n";
}

void CommandLine::exitProgram()
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