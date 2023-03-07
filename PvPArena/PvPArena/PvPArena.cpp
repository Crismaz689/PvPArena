#include "./HeaderFiles/Validators/ConsoleArgumentsValidator.h";
#include "./HeaderFiles/UI/ConsoleUI.h";
#include "./HeaderFiles/Core/GameHandler.h";

int main(int argc, char* const argv[]) {
    ConsoleArgumentsValidator* consoleValidator = new ConsoleArgumentsValidator();
    UI* consoleUI = new ConsoleUI();
    ConsoleArgumentType validationStatus = consoleValidator->checkArguments(argc, argv, consoleUI);

    if (validationStatus  == ConsoleArgumentType::Files) {
        GameHandler* gameHandler = new GameHandler();

        gameHandler->initialize(argc, argv, consoleUI);
        gameHandler->startGame(consoleUI);

        delete gameHandler;
    }
    else if (validationStatus == ConsoleArgumentType::Help){
        consoleUI->showHelpInstructions();
    }

    delete consoleValidator;
    delete consoleUI;

    return 0;
}