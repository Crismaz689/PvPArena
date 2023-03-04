#include "ConsoleArgumentsValidator.h"

#include <iostream>

bool ConsoleArgumentsValidator::checkArguments(int argc, char* const argv[]) {
	return this->checkIsHelpCalled(argc, argv) || this->checkAreFilesCalled(argc, argv);
}

bool ConsoleArgumentsValidator::checkIsHelpCalled(int argc, char* const argv[]) {
	return argc == 2 && std::string(argv[1]) == this->HELP_PARAMETER;
}

bool ConsoleArgumentsValidator::checkAreFilesCalled(int argc, char* const argv[]) {
	return argc == 5 && ((std::string(argv[1]) == this->QUESTS_FILE_PARAMETER && std::string(argv[3]) == this->ITEMS_FILE_PARAMETER)
		|| (std::string(argv[1]) == this->ITEMS_FILE_PARAMETER && std::string(argv[3]) == this->QUESTS_FILE_PARAMETER)
		&& this->checkFiles(argc, argv));
}

bool ConsoleArgumentsValidator::checkFiles(int argc, char* const argv[]) {
	char* fileNames[] = { argv[this->FIRST_FILE_ARGUMENT_POSITION], argv[this->SECOND_FILE_ARGUMENT_POSITION]};

	return this->checkFilesExtensions(fileNames) && this->checkDoFilesExist(fileNames);
}

bool ConsoleArgumentsValidator::checkFilesExtensions(char* const fileNames[]) {
	return this->checkFileExtension(fileNames[0]) && this->checkFileExtension(fileNames[1]);
}

bool ConsoleArgumentsValidator::checkFileExtension(char* const fileName) {
	std::string fileNameAsString = std::string(fileName);

	return fileNameAsString.substr(fileNameAsString.length() - 3, 3) == this->TXT_FILE_EXTENSION ||
		fileNameAsString.substr(fileNameAsString.length() - 3, 3) == this->CSV_FILE_EXTENSION;
}

bool ConsoleArgumentsValidator::checkDoFilesExist(char* const fileNames[]) {
	return this->checkDoesFileExist(fileNames[0]) && this->checkDoesFileExist(fileNames[1]);
}

bool ConsoleArgumentsValidator::checkDoesFileExist(char* const fileName) {
	return std::filesystem::exists(fileName);
}