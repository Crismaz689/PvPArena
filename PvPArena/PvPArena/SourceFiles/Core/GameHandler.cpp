#include "../../HeaderFiles/Core/GameHandler.h";

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
}

void GameHandler::initializeQuests(int argc, char* const argv[], UI* ui) {
	FileHandler fileHandler;
	std::string fileName = argv[1] == std::string("-q") ?
		std::string(argv[2]) :
		std::string(argv[4]);

	this->availableQuests = fileHandler.readQuestsFromFile(fileName, ui);
}

void GameHandler::createPlayers(UI* ui) {
	this->playerA = createPlayer(ui, 1);
	this->playerB = createPlayer(ui, 2);
}

Player* GameHandler::createPlayer(UI* ui, int playerNumber) {
	ui->showCreatePlayerIntroduction(playerNumber);
	std::string name = ui->getPlayerName();

	ui->showCreatePlayerClassSelection(playerNumber);
	ui->showClassList();
	ClassName className = ui->getClassName();

	switch (className) {
		case ClassName::Warrior:
			return new Warrior(name, className);
		case ClassName::Mage:
			return new Mage(name, className);
		case ClassName::Paladin:
			return new Paladin(name, className);
		case ClassName::Archer:
			return new Archer(name, className);
		case ClassName::Sniper:
			return new Sniper(name, className);
		default:
			return new Berserker(name, className);
	}
}

void GameHandler::initialize(int argc, char* const argv[], UI* ui) {
	this->initializeItems(argc, argv, ui);
	this->initializeQuests(argc, argv, ui);
	this->createPlayers(ui);
}

void GameHandler::startGame(UI* ui) {

}