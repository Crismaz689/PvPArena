#include "../../HeaderFiles/Core/GameHandler.h";


#include <iostream>

GameHandler::~GameHandler() {
	for (auto quest : this->availableQuests) {
		delete quest;
	}

	this->availableQuests.clear();
	this->availableItems.clear();
}

void GameHandler::initializeItems(int argc, char* const argv[], UI* ui) {
	FileHandler fileHandler;
	std::string fileName = argv[1] == std::string("-i") ?
		std::string(argv[2]) :
		std::string(argv[4]);

	this->availableItems = fileHandler.readItemsFromFile(fileName, ui);

	for (auto item : availableItems) {
		std::cout << item.test() << "\t" << item.test2() << "\n";
	}
}

void GameHandler::initializeQuests(int argc, char* const argv[], UI* ui) {
	//this->availableQuests = FileHandler::readQuestsFromFile;
}

void GameHandler::initialize(int argc, char* const argv[], UI* ui) {
	this->initializeItems(argc, argv, ui);
	this->initializeQuests(argc, argv, ui);
}

void GameHandler::startGame(UI* ui) {

}