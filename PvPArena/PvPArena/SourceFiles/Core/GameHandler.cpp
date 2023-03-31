#include "../../HeaderFiles/Core/GameHandler.h";

GameHandler::~GameHandler() {
	for (auto quest : this->availableQuests) {
		delete quest;
	}

	for (auto quest : this->doneQuests) {
		delete quest;
	}

	this->doneQuests.clear();
	this->availableQuests.clear();

	delete this->shop;
	delete this->turnHandler;
	delete this->playerA;
	delete this->playerB;

	this->shop = nullptr;
	this->playerA = nullptr;
	this->playerB = nullptr;
	this->turnHandler = nullptr;
}

void GameHandler::initializeItems(int argc, char* const argv[]) {
	FileHandler fileHandler;
	std::string fileName = argv[1] == std::string("-i") ?
		std::string(argv[2]) :
		std::string(argv[4]);

	std::vector<Item> items = fileHandler.readItemsFromFile(fileName, this->ui);
	this->shop = new Shop(items);
}

void GameHandler::initializeQuests(int argc, char* const argv[]) {
	FileHandler fileHandler;
	std::string fileName = argv[1] == std::string("-q") ?
		std::string(argv[2]) :
		std::string(argv[4]);

	this->availableQuests = fileHandler.readQuestsFromFile(fileName, this->ui);
}

void GameHandler::createPlayers() {
	this->playerA = createPlayer(1);
	this->playerB = createPlayer(2);
}

Player* GameHandler::createPlayer(int playerNumber) {
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
	this->turnHandler = new TurnHandler();
	this->ui = ui;
	this->initializeItems(argc, argv);
	this->initializeQuests(argc, argv);
	this->createPlayers();
	this->ui->wipe();
}

std::vector<Quest*> GameHandler::randomizeQuests() {
	std::vector<Quest*> result;
	int questsAmount = this->availableQuests.size();

	if (questsAmount > 0) {
		int questsAmountToRandomize = questsAmount > 5 ?
			this->QUESTS_PER_TURN :
			questsAmount;

		int i = 0;
		std::vector<int> questsIds;

		while (i < questsAmountToRandomize) {
			int randomNumber = rand() % questsAmount;

			if (!(std::find(questsIds.begin(), questsIds.end(), randomNumber) != questsIds.end())) {
				questsIds.push_back(randomNumber);
				i++;
			}
		}

		for (auto id : questsIds) {
			result.push_back(this->availableQuests[id]);
		}
	}
	
	return result;
}

void GameHandler::handleQuestMenu(Player*& player, std::vector<Quest*>& currentQuests, bool& isPlayerDead) {
	int chosenOption = 0;

	do {
		this->ui->showQuestsMenu();
		chosenOption = this->ui->getQuestMenuOption();
		this->ui->wipe();

		switch (chosenOption) {
		case 1:
			this->chooseQuestMenu(player, currentQuests, isPlayerDead);

			if (isPlayerDead) return;

			break;
		}
	} while (chosenOption != 2);
}

void GameHandler::handleShopMenu(Player*& player) {
	int chosenOption = 0;

	do {
		this->ui->showShopMenu();
		chosenOption = this->ui->getShopMenuOption();
		this->ui->wipe();

		switch (chosenOption) {
		case 1:
			this->chooseShopMenu(player);

			break;
		}
	} while (chosenOption != 2);
}

void GameHandler::chooseShopMenu(Player*& player) {
	int chosenItemIndex = 0;

	do {
		this->ui->showAvailableItems(this->shop);
		chosenItemIndex = this->ui->getCurrentShopOption(this->shop);

		if (chosenItemIndex + 1 != 0) { // getCurrentSopOption() returns option - 1
			this->ui->showItemDetails(this->shop, chosenItemIndex);
			bool doYouWantToBuyAnItem = this->ui->showBuyDecision();

			if (doYouWantToBuyAnItem) {
				// check gold amount
				// add item to a user
				// delete item from shop
				// show transaction status

				// void ConsoleUI::showItemDetails(Shop* shop, int itemIndex)
				// bool ConsoleUI::showBuyDecision()
			}
		}
	} while (chosenItemIndex + 1 != 0);
	this->ui->wipe();
}

void GameHandler::chooseQuestMenu(Player*& player, std::vector<Quest*>& currentQuests, bool& isPlayerDead) {
	int chosenQuestIndex = 0;

	do {
		this->ui->showCurrentQuests(currentQuests);
		chosenQuestIndex = this->ui->getCurrentQuestOption(currentQuests);

		if (chosenQuestIndex + 1 != 0) { // getCurrentQuestOption() returns option - 1
			if (this->takeQuest(player, currentQuests[chosenQuestIndex], isPlayerDead))
				this->deleteQuest(currentQuests, chosenQuestIndex);

			if (isPlayerDead) 
				return;
		}
	} while (chosenQuestIndex + 1!= 0);
	this->ui->wipe();
}

void GameHandler::deleteQuest(std::vector<Quest*>& currentQuests, int chosenQuestIndex) {
	std::string questDescriptionToDelete = currentQuests[chosenQuestIndex]->getDescription();

	std::vector<Quest*>::iterator it = currentQuests.begin();
	std::advance(it, chosenQuestIndex);
	currentQuests.erase(it);

	for (int i = 0; i < this->availableQuests.size(); ++i) {
		if (this->availableQuests[i]->getDescription() == questDescriptionToDelete) {
			std::vector<Quest*>::iterator it = this->availableQuests.begin();
			std::advance(it, i);
			this->availableQuests.erase(it);

			return;
		}
	}
};

bool GameHandler::takeQuest(Player*& player, Quest* quest, bool& isPlayerDead) {
	if (player->getStamina() < quest->getStaminaCost()) {
		this->ui->showErrorMessage("You do not have enough stamina points to take this action.");
		this->ui->waitForContinue();
		this->ui->wipe();

		return false;
	}

	bool questCompleted = quest->start(player, this->ui);

	if (!questCompleted) {
		this->ui->showLostScreen(player);
		isPlayerDead = !questCompleted;
	}
	else {
		addGold(player, quest->getReward());
		removeStamina(player, quest->getStaminaCost());
	}

	return true;
}

void GameHandler::addGold(Player*& player, double goldToAdd) {
	double playerGold = player->getGold();
	double totalGold = playerGold + goldToAdd;

	player->setGold(totalGold);
}

void GameHandler::removeStamina(Player*& player, int staminaToLose) {
	double playerStamina = player->getStamina();
	double substractedStamina = playerStamina - staminaToLose;

	player->setStamina(substractedStamina);
}

void GameHandler::handleTurn(Player* player, std::vector<Quest*> currentQuests) {
	int currentTurn = this->turnHandler->getTurn() + 1;
	int currentDay = ((currentTurn - 1) / 2) + 1;
	int chosenOption = 0;

	do {
		this->ui->showTurnInfo(player, currentTurn, currentDay);
		this->ui->showTurnMenu(false);
		chosenOption = this->ui->getTurnMenuOption();
		this->ui->wipe();
		bool isPlayerDead = false;

		switch (chosenOption) {
			case 1:
				break;
			case 2:
				this->handleQuestMenu(player, currentQuests, isPlayerDead);

				if (isPlayerDead) return;
				break;
			case 3:
				this->handleShopMenu(player);
				break;
			case 4:
				this->ui->showPlayerDetails(player);
				break;
			case 5:
				this->ui->showPlayerEquipment(player);
				break;
			case 6:
				this->ui->showInfoMessage("You finished your turn!");
				this->turnHandler->endTurn();
				this->ui->waitForContinue();
				this->ui->wipe();
				break;
			default:
				this->ui->showErrorMessage("You have to choose option between 1 and 6");
				break;
		}
	} while (chosenOption != 6 );
}

void GameHandler::clearCurrentQuests(std::vector<Quest*>& quests) {
	for (auto quest : quests) {
		delete quest;
	}

	quests.clear();
}

void GameHandler::startGame() {
	int currentTurn = this->turnHandler->getTurn();
	Player* currentPlayer = nullptr;
	std::vector<Quest*> currentQuests;

	while (currentTurn < TurnHandler::MAX_TURNS) {
		currentPlayer = currentTurn % 2 == 0 ?
			this->playerA :
			this->playerB;

		currentPlayer->resetStats();
		currentQuests = randomizeQuests();

		this->handleTurn(currentPlayer, currentQuests);

		if (currentPlayer->getHp() <= 0) return;
		currentTurn = this->turnHandler->getTurn();
	}
}