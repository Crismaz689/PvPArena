#include "../../HeaderFiles/UI/ConsoleUI.h"

void ConsoleUI::showHelpInstructions() {
	std::cout << "\n\n================= HELP ====================\n\n";
	std::cout << "You should run game in the following way: \n";
	std::cout << "PvPArena.exe -i items.txt -q quests.txt";
	std::cout << "\nor\n";
	std::cout << "PvPArena.exe -q quests.txt -i items.txt";
	std::cout << "\nFiles have to be stored under PvPArena\\PvPArena\\PvPArena folder.\n";
	std::cout << "\n\n================= HELP ====================\n\n";
}

void ConsoleUI::showDefaultErrorMessage() {
	std::cout << "\n\n================= CRITICAL ERROR ====================\n\n";
	std::cout << "Unknown error occured.\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= CRITICAL ERROR ====================\n\n";
}

void ConsoleUI::showErrorMessage(std::string message) {
	std::cout << "\n\n================= CRITICAL ERROR ====================\n\n";
	std::cout << "Error with following message occured: " << message << "\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= CRITICAL ERROR ====================\n\n";
}

void ConsoleUI::showExceptionMessage(std::string message) {
	std::cout << "\n\n================= ERROR ====================\n\n";
	std::cout << "Error with following message occured: " << message << "\n";
	std::cout << "\n\n================= ERROR ====================\n\n";
}

void ConsoleUI::showCreatePlayerIntroduction(int playerNumber) {
	std::system("CLS");
	std::cout << "\n=== [Player " << playerNumber << " is choosing the name] == = \n";
}

void ConsoleUI::showCreatePlayerClassSelection(int playerNumber) {
	std::cout << "=== [Player " << playerNumber << " is choosing class (by number)] === \n";
}

void ConsoleUI::showClassList() {
	std::cout << "1. Warrior\n";
	std::cout << "2. Mage\n";
	std::cout << "3. Paladin\n";
	std::cout << "4. Archer\n";
	std::cout << "5. Sniper\n";
	std::cout << "6. Berserker\n";
}

std::string ConsoleUI::getPlayerName() {
	std::string name = "";

	while (name.size() <= 2) {
		std::cout << "[Character name]: ";
		std::cin >> name;

		if (name.size() <= 2) {
			std::cerr << "[ERROR]: Character name has to contain at least 3 characters!\n\n";
		}
	}
	std::cout << "Your name is: " << name << "\n\n";

	return name;
}

ClassName ConsoleUI::getClassName() {
	std::string className = "";
	int classNameValue = 0;
	bool isClassNameValid = false;

	while (!isClassNameValid) {
		std::cout << "[Class number]: ";
		std::cin >> className;

		try {
			classNameValue = stoi(className);

			if (classNameValue > 0 && classNameValue < 7) {
				isClassNameValid = true;
			}
			else {
				std::cerr << "[ERROR]: You have to choose number between 1 and 6!\n\n";
			}
		}
		catch (std::invalid_argument& exception) {
			this->showExceptionMessage(exception.what());
			std::cout << "\n\n";
		}
	}
	std::cout << "Your class is: " << EnumUtil::convertIntToStringClassName(classNameValue) << "\n\n";
	std::system("PAUSE");

	return (ClassName)classNameValue;
}