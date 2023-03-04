#include <iostream>

#include "ConsoleArgumentsValidator.h";

int main(int argc, char* const argv[]) {
    ConsoleArgumentsValidator* consoleValidator = new ConsoleArgumentsValidator();

    if (consoleValidator->checkArguments(argc, argv)) {
        std::cout << "tak";
    }
    else {
        std::cout << "nie";
    }

    delete consoleValidator;

    return 0;
}