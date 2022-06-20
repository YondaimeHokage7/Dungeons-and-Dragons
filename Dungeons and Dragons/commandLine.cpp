#include "commandLine.hpp"
#include <cassert>

CommandLine::CommandLine() : command(""), arguments(""), currentlyOpened("")
{}

void CommandLine::userInput()
{
    while (1)
    {
        std::cout << "Enter a command: \n";
        std::cin >> command;
        std::getline(std::cin, arguments, '\n');
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
    std::string answer;
    std::cin >> answer;
    if (answer == "Yes")
    {
        Player player = Human();
        Map map(1);
        std::ofstream create(currentlyOpened);
        create << player << map;
        create.close();
        player.start(map);
        exitProgram(player, map);
    }
}

void CommandLine::loadGame()
{
    std::cout << "Loading...\n";
    Player player = Human();
    Map map(1);
    std::ifstream saveFile(arguments, std::ios::in);
    assert(saveFile.peek() != EOF);
    saveFile >> player;
    saveFile >> map;
    saveFile.close();
    std::cout << "Successfully loaded " << player.getRace().getName() << " level " << player.getLevel() << '\n';
    player.start(map, 0);
    exitProgram(player, map);
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
        save();
    }
    else if (command == "saveas")
    {
        saveAs();
    }
    else if (command == "help")
    {
        help();
    }
    else if (command == "exit")
    {
        exitCommandLine();
    }
}

void CommandLine::open()
{
    if (currentlyOpened != "")
    {
        std::cout << currentlyOpened << " is currently opened!\n";
        std::cout << "Close it and then try opening another file!\n";
    }
    else
    {
        std::ifstream userFile(arguments, std::ios::in);
        std::ofstream blankFile;
        if (userFile.is_open())
        {
            std::cout << "Successfully opened " << arguments << "!\n";
            currentlyOpened = arguments;
            userFile.close();
            blankFile.close();
            loadGame();
        }
        else
        {
            std::cout << "The given file does not exist!\n";
            userFile.close();
            blankFile.open(arguments, std::ios::out | std::ios::trunc);
            if (blankFile.is_open())
            {
                blankFile.close();
                std::cout << "Successfully created and opened " << arguments << "\n";
                currentlyOpened = arguments;
                startGame();
            }
            else
            {
                std::cerr << "There was an error creating the file " << arguments << "\n";
            }
        }
    }
}

void CommandLine::close()
{
    if (currentlyOpened != "")
    {
        std::cout << "Successfully closed " << currentlyOpened << '\n';
        std::ifstream opened(currentlyOpened);
        if (opened.peek() == EOF)
        {
            opened.close();
            std::cout << "No changes made to a newly created file!\n";
            std::cout << currentlyOpened << " was deleted!\n";
            remove(currentlyOpened.c_str());
        }
        currentlyOpened = "";
    }
    else
    {
        std::cout << "There is no currently opened file!\n";
    }
}


void CommandLine::save(const Player& player, const Map& map)
{
    if (currentlyOpened == "")
    {
        std::cout << "There is no currently opened file!";
    }
    else
    {
        std::ofstream saveFile(currentlyOpened);
        saveFile << player;
        saveFile << map;
        saveFile.close();
        std::cout << "Successfully saved changes in " << currentlyOpened << "!\n";
    }
}

void CommandLine::save()
{
    remove(currentlyOpened.c_str());
    std::cout << "No changes made to a newly created file!\n";
    std::cout << currentlyOpened << " was deleted!\n";
    currentlyOpened = "";
}

void CommandLine::saveAs()
{
    if (currentlyOpened == "")
    {
        std::cout << "There is no currently opened file!\n";
    }
    else
    {
        while (arguments == "")
        {
            std::cout << "No file name entered!\n";
            std::cout << "Where would you like to save your progress?\n";
            std::getline(std::cin, arguments, '\n');
        }
        std::ofstream saveFile(arguments);
        saveFile.close();
    }
    remove(currentlyOpened.c_str());
    std::cout << "No changes made to a newly created file!\n";
    std::cout << currentlyOpened << " was deleted!\n";
    currentlyOpened = "";
}

void CommandLine::saveAs(const Player& player, const Map& map)
{
    while (arguments == "")
    {
        std::cout << "No file name entered!\n";
        std::cout << "Where would you like to save your progress?";
        std::getline(std::cin, arguments, '\n');
    }
    std::ofstream saveFile(arguments);
    saveFile << player;
    saveFile << map;
    saveFile.close();
    std::cout << "Successfully saved progress in " << arguments << "!\n";
}


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

void CommandLine::exitProgram(const Player& player, const Map& map)
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
                save(player, map);
            }
            else if (command == "saveas")
            {
                std::cin >> arguments;
                validCommand = true;
                saveAs(player, map);
            }
            else
            {
                std::cout << "Invalid command!\n";
                std::getline(std::cin, command,'\n');
            }
        }
    }
    exit(0);
}

void CommandLine::exitCommandLine()
{
    exit(0);
}
