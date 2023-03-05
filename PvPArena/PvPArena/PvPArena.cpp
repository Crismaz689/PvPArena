#include "./HeaderFiles/Validators/ConsoleArgumentsValidator.h";
#include "./HeaderFiles/UI/ConsoleUI.h";

int main(int argc, char* const argv[]) {
    ConsoleArgumentsValidator* consoleValidator = new ConsoleArgumentsValidator();
    UI* consoleUI = new ConsoleUI();
    ConsoleArgumentType validationStatus = consoleValidator->checkArguments(argc, argv, consoleUI);

    if (validationStatus  == ConsoleArgumentType::Files) {
        std::cout << "tak"; // start
    }
    else if (validationStatus == ConsoleArgumentType::Help){
        consoleUI->ShowHelpInstructions();
    }

    delete consoleValidator;
    delete consoleUI;

    return 0;
}