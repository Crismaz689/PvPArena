#include "ConsoleArgumentsValidator.h";
#include "ConsoleUI.h";

int main(int argc, char* const argv[]) {
    ConsoleArgumentsValidator* consoleValidator = new ConsoleArgumentsValidator();
    UI* consoleUI = new ConsoleUI();

    if (consoleValidator->checkArguments(argc, argv) == ConsoleArgumentType::Files) {
        std::cout << "tak"; // start
    }
    else if (consoleValidator->checkArguments(argc, argv) == ConsoleArgumentType::Help){
        consoleUI->ShowHelpInstructions();
    }
    else {
        consoleUI->ShowDefaultErrorMessage();
    }

    delete consoleValidator;
    delete consoleUI;

    return 0;
}