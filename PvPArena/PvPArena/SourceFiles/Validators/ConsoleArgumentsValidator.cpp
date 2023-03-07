#include "../../HeaderFiles/Validators/ConsoleArgumentsValidator.h"
#include "../../HeaderFiles/Exceptions/FileInvalidExtensionException.h";
#include "../../HeaderFiles/Exceptions/FileNotFoundException.h";

ConsoleArgumentType ConsoleArgumentsValidator::checkArguments(int argc, char* const argv[], UI* ui) {
	return this->checkIsHelpCalled(argc, argv) ? ConsoleArgumentType::Help :
		this->checkAreFilesCalled(argc, argv, ui) ? ConsoleArgumentType::Files :
		ConsoleArgumentType::None;
}

bool ConsoleArgumentsValidator::checkIsHelpCalled(int argc, char* const argv[]) {
	return argc == 2 && std::string(argv[1]) == this->HELP_PARAMETER;
}

bool ConsoleArgumentsValidator::checkAreFilesCalled(int argc, char* const argv[], UI* ui) {
	return argc == 5 && ((std::string(argv[1]) == this->QUESTS_FILE_PARAMETER && std::string(argv[3]) == this->ITEMS_FILE_PARAMETER)
		|| (std::string(argv[1]) == this->ITEMS_FILE_PARAMETER && std::string(argv[3]) == this->QUESTS_FILE_PARAMETER)
		&& this->checkFiles(argc, argv, ui));
}

bool ConsoleArgumentsValidator::checkFiles(int argc, char* const argv[], UI* ui) {
	char* fileNames[] = { argv[this->FIRST_FILE_ARGUMENT_POSITION], argv[this->SECOND_FILE_ARGUMENT_POSITION]};

	return this->checkFilesExtensions(fileNames, ui) && this->checkDoFilesExist(fileNames, ui);
}

bool ConsoleArgumentsValidator::checkFilesExtensions(char* const fileNames[], UI* ui) {
	try {
		return this->checkFileExtension(fileNames[0]) && this->checkFileExtension(fileNames[1]);
	}
	catch (FileInvalidExtensionException& exception) {
		ui->showErrorMessage(exception.what());
		
		return false;
	}
	catch (std::out_of_range& exception) {
		ui->showErrorMessage(exception.what());

		return false;
	}
}

bool ConsoleArgumentsValidator::checkFileExtension(char* const fileName) {
	std::string fileNameAsString = std::string(fileName);

	return (fileNameAsString.substr(fileNameAsString.length() - 3, 3) == this->TXT_FILE_EXTENSION ||
		fileNameAsString.substr(fileNameAsString.length() - 3, 3) == this->CSV_FILE_EXTENSION) ? true :
		throw FileInvalidExtensionException(fileName);
}

bool ConsoleArgumentsValidator::checkDoFilesExist(char* const fileNames[], UI* ui) {
	try {
		return this->checkDoesFileExist(fileNames[0]) && this->checkDoesFileExist(fileNames[1]);
	}
	catch (FileNotFoundException& exception) {
		ui->showErrorMessage(exception.what());

		return false;
	}
}

bool ConsoleArgumentsValidator::checkDoesFileExist(char* const fileName) {
	return std::filesystem::exists(fileName) ? true : 
		throw FileNotFoundException(fileName);
}