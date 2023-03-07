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
	std::cout << "\n\n================= ERROR ====================\n\n";
	std::cout << "Unknown error occured.\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= ERROR ====================\n\n";
}

void ConsoleUI::showErrorMessage(std::string message) {
	std::cout << "\n\n================= ERROR ====================\n\n";
	std::cout << "Error with following message occured: " << message << "\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= ERROR ====================\n\n";
}