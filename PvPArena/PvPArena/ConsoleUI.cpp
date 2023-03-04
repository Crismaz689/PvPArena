#include "ConsoleUI.h"

void ConsoleUI::ShowHelpInstructions() {
	std::cout << "\n\n================= HELP ====================\n\n";
	std::cout << "You should run game in the following way: \n";
	std::cout << "PvPArena.exe -i items.txt -q quests.txt";
	std::cout << "\nor\n";
	std::cout << "PvPArena.exe -q quests.txt -i items.txt";
	std::cout << "\nFiles have to be stored under PvPArena\\PvPArena\\PvPArena folder.\n";
	std::cout << "\n\n================= HELP ====================\n\n";
}

void ConsoleUI::ShowDefaultErrorMessage() {
	std::cout << "\n\n================= ERROR ====================\n\n";
	std::cout << "Unknown error occured.\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= ERROR ====================\n\n";
}

void ConsoleUI::ShowErrorMessage(std::string message) {
	std::cout << "\n\n================= ERROR ====================\n\n";
	std::cout << "Error with following message occured: " << message << "\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= ERROR ====================\n\n";
}