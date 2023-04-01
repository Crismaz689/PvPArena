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

void ConsoleUI::showCriticalErrorMessage(std::string message) {
	std::cout << "\n\n================= CRITICAL ERROR ====================\n\n";
	std::cout << "Error with following message occured: " << message << "\n";
	std::cout << "Program has stopped.";
	std::cout << "\n\n================= CRITICAL ERROR ====================\n\n";
}

void ConsoleUI::showErrorMessage(std::string message) {
	std::cout << "[ERROR]: " << message << "\n";
}

void ConsoleUI::showArenaResult(Player* player, bool didWin) {
	std::cout << "\n[DUEL RESULT]: " << player->getName();

	if (didWin) {
		std::cout << " has won the fight!\n";
	}
	else {
		std::cout << " has lost the fight!\n";
	}
}

void ConsoleUI::showInfoMessage(std::string message) {
	std::cout << "[INFO]: " << message << "\n";
}

void ConsoleUI::showExceptionMessage(std::string message) {
	std::cout << "\n\n================= ERROR ====================\n\n";
	std::cout << "Error with following message occured: " << message << "\n";
	std::cout << "\n\n================= ERROR ====================\n\n";
}

void ConsoleUI::showCreatePlayerIntroduction(int playerNumber) {
	this->wipe();
	std::cout << "\n=== [Player " << playerNumber << " is choosing the name] === \n";
}

void ConsoleUI::wipe() {
	std::system("CLS");
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

void ConsoleUI::waitForContinue() {
	std::system("PAUSE");
}

void ConsoleUI::enter() {
	std::cout << "\n";
}

void ConsoleUI::showTurnInfo(Player* player, int currentTurn, int currentDay) {
	std::cout << "===== [DAY: " << currentDay << "] =====\n";
	std::cout << "===== [TURN: " << currentTurn << "] =====\n";
	std::string message = player->getName() + ", it's your turn!\n\n";
	this->showInfoMessage(message);

	std::cout << "[STAMINA: " << player->getStamina() << "]\t\t\t" << "[GOLD: " << player->getGold() << "]\t\t\t" << "[HP: " << player->getHp() << "/" << player->getMaxHp() << "]\n";
}

void ConsoleUI::showTurnMenu(bool isChallenged) {
	if (isChallenged)
		std::cout << "1. " << "Fight (accept)\n";
	else
		std::cout << "1. " << "Fight\n";
	std::cout << "2. " << "Quests\n";
	std::cout << "3. " << "Shop\n";
	std::cout << "4. " << "Check status\n";
	std::cout << "5. " << "Show equipment\n";
	std::cout << "6. " << "Finish the day\n";
}

int ConsoleUI::getTurnMenuOption() {
	std::string option = "";
	int optionAsInt = 0;
	bool isOptionValid = false;

	while (!isOptionValid) {
		std::cout << "[I choose]: ";
		std::cin >> option;

		try {
			optionAsInt = stoi(option);

			if (optionAsInt > 0 && optionAsInt < 7) {
				isOptionValid = true;
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

	return optionAsInt;
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
	std::cout << "Your class is: " << EnumUtil::convertIntToStringClassName(classNameValue - 1) << "\n\n";
	std::system("PAUSE");

	return (ClassName)(classNameValue - 1);
}

void ConsoleUI::showQuestsMenu() {
	std::cout << "===== QUEST OPTIONS =====\n";
	std::cout << "1. Show quest list\n";
	std::cout << "2. Back to main menu\n\n";
}

void ConsoleUI::showShopMenu() {
	std::cout << "===== SHOP OPTIONS =====\n";
	std::cout << "1. Show available items\n";
	std::cout << "2. Back to main menu\n\n";
}

int ConsoleUI::getQuestMenuOption() {
	std::string option = "";
	int optionAsInt = 0;
	bool isOptionValid = false;

	while (!isOptionValid) {
		std::cout << "[QUEST MENU]: What do you want to do now?: ";
		std::cin >> option;

		try {
			optionAsInt = stoi(option);

			if (optionAsInt > 0 && optionAsInt < 3) {
				isOptionValid = true;
			}
			else {
				std::cerr << "[ERROR]: You have to choose number between 1 and 2!\n\n";
			}
		}
		catch (std::invalid_argument& exception) {
			this->showExceptionMessage(exception.what());
			std::cout << "\n\n";
		}
	}

	return optionAsInt;
}

int ConsoleUI::getShopMenuOption() {
	std::string option = "";
	int optionAsInt = 0;
	bool isOptionValid = false;

	while (!isOptionValid) {
		std::cout << "[SHOP MENU]: What do you want to do now?: ";
		std::cin >> option;

		try {
			optionAsInt = stoi(option);

			if (optionAsInt > 0 && optionAsInt < 3) {
				isOptionValid = true;
			}
			else {
				std::cerr << "[ERROR]: You have to choose number between 1 and 2!\n\n";
			}
		}
		catch (std::invalid_argument& exception) {
			this->showExceptionMessage(exception.what());
			std::cout << "\n\n";
		}
	}

	return optionAsInt;
}


void ConsoleUI::showAvailableItems(Player* player, std::vector<Item> items) {
	int numberOfClassItems = 0;

	std::cout << "===== AVAILABLE ITEMS FOR YOUR CLASS =====\n";
	std::cout << "0. Back to shop menu\n\n";

	if (items.size() == 0) {
		std::cout << "There are no items for your class in the shop.." << "\n\n";

		return;
	}

	for (int i = 0; i < items.size(); ++i) {
		if (items[i].getClassName() == player->getClassName()) {
			std::cout << (numberOfClassItems + 1) << ". " << items[i].getName() << "\n";
			numberOfClassItems++;
		}
	}
}

int ConsoleUI::getCurrentShopOption(std::vector<Item> items) {
	std::string chosenItemIndex = "";
	int chosenItemtIndexAsInt = 0;
	bool isOptionValid = false;

	while (!isOptionValid) {
		std::cout << "[SHOP MENU]: Which item do you want to see in detail?: ";
		std::cin >> chosenItemIndex;

		try {
			chosenItemtIndexAsInt = stoi(chosenItemIndex);

			if (chosenItemtIndexAsInt >= 0 && chosenItemtIndexAsInt < items.size() + 1) {
				isOptionValid = true;
			}
			else {
				std::cerr << "[ERROR]: You have to choose number between 1 and " << items.size() << "!\n\n";
			}
		}
		catch (std::invalid_argument& exception) {
			this->showExceptionMessage(exception.what());
			std::cout << "\n\n";
		}
	}

	return chosenItemtIndexAsInt - 1;
}

void ConsoleUI::showCurrentQuests(std::vector<Quest*> currentQuests) {
	std::cout << "===== AVAILABLE QUESTS =====\n";
	
	if (currentQuests.size() == 0) {
		std::cout << "No available quests.." << "\n\n";
	}

	std::cout << "0. Back to quest menu\n\n";
	for (int i = 0; i < currentQuests.size(); ++i) {
		if (currentQuests[i]->getType() == QuestType::Battle) {
			std::cout << (i + 1) << ". [BATTLE] " << currentQuests[i]->getDescription() << "\n";
			std::cout << "> You need " << currentQuests[i]->getStaminaCost() << " stamina points to take the quest. You will be rewarded with " << currentQuests[i]->getReward() << " gold.\n\n";
		}
		else {
			std::cout << (i + 1) << ". [HELP] " << currentQuests[i]->getDescription() << "\n";
			std::cout << "> You need " << currentQuests[i]->getStaminaCost() << " stamina points to take the quest. You will be rewarded with " << currentQuests[i]->getReward() << " gold.\n\n";
		}
	}
}

int ConsoleUI::getCurrentQuestOption(std::vector<Quest*> currentQuests) {
	std::string chosenQuestIndex = "";
	int chosenQuestIndexAsInt = 0;
	bool isOptionValid = false;

	while (!isOptionValid) {
		std::cout << "[QUEST MENU]: Which quest do you want to take?: ";
		std::cin >> chosenQuestIndex;

		try {
			chosenQuestIndexAsInt = stoi(chosenQuestIndex);

			if (chosenQuestIndexAsInt >= 0 && chosenQuestIndexAsInt < currentQuests.size() + 1) {
				isOptionValid = true;
			}
			else {
				std::cerr << "[ERROR]: You have to choose number between 1 and " << currentQuests.size() << "!\n\n";
			}
		}
		catch (std::invalid_argument& exception) {
			this->showExceptionMessage(exception.what());
			std::cout << "\n\n";
		}
	}

	return chosenQuestIndexAsInt - 1;
}

void ConsoleUI::showLostScreen(Player* player) {
	this->showInfoMessage("Player " + player->getName() + " has lost the game!");
}

void ConsoleUI::showFightStart() {
	this->wipe();
	std::cout << "\n\n=======================================\n";
	std::cout << "============== FIGHT STARTS ==============\n";
	std::cout << "=======================================\n\n";
}

void ConsoleUI::showPlayerDetails(Player* player) {
	this->showInfoMessage("You are playing as " + EnumUtil::convertIntToStringClassName((int)player->getClassName()) + "!");
	this->enter();

	std::cout << "HP: " << player->getHp() << "/" << player->getMaxHp() << "\n";
	std::cout << "Defense: " << player->getDefense() << "\n";
	std::cout << "Magic defense: " << player->getMagicDefense() << "\n";
	std::cout << "Strength: " << player->getStrength() << "\n";
	std::cout << "Intelligence: " << player->getIntelligence() << "\n";
	std::cout << "Dexterity: " << player->getDexterity() << "\n";
	std::cout << "Critical chance: " << player->getCriticalChance() << "\n";

	this->waitForContinue();
	this->wipe();
}

void ConsoleUI::showPlayerEquipment(Player* player) {
	std::cout << "\t\t[ITEM NAME]\t[HP]\t[DEFENSE]\t[MAGIC DEFENSE]\t[STRENGTH]\t[INTELLIGENCE]\t[DEXTERITY]\t[CRITICAL CHANCE]\n\n";

	bool itemFound = false;
	for (int i = 0; i < Item::NUMBER_OF_ARMOR_PARTS; i++) {
		itemFound = false;
		for (auto& item : player->getItems()) {
			if (Player::EQUIPMENT[i] == item.getType()) {
				std::cout << "[" << EnumUtil::convertItemTypeToString(Player::EQUIPMENT[i]) << "]:\t";
				this->showItemInfo(item);
				itemFound = true;
				break;
			}
		}
		if (!itemFound)
			std::cout << "[" << EnumUtil::convertItemTypeToString(Player::EQUIPMENT[i]) << "]:\t-no item-\n";
	}
	
	this->waitForContinue();
	this->wipe();
}

void ConsoleUI::showItemInfo(Item item) {
	std::cout << item.getName() << "\t" << std::to_string(item.getHp()) << "\t" << std::to_string(item.getDefense()) << "\t\t "
		<< std::to_string(item.getMagicDefense()) << "\t\t " << std::to_string(item.getStrength()) << "\t\t " 
		<< std::to_string(item.getIntelligence()) << "\t\t " << std::to_string(item.getDexterity()) << "\t\t " 
		<< std::to_string(item.getCriticalChance()) << "\n";
}

void ConsoleUI::showItemDetails(std::vector<Item> items, int itemIndex) {
	Item item = items[itemIndex];

	this->enter();
	
	std::cout << "[ITEM NAME]: " << item.getName() << "\n";
	std::cout << "[HP]: " << item.getHp() << "\n";
	std::cout << "[DEFENSE]: " << item.getDefense() << "\n";
	std::cout << "[MAGIC DEFENSE]: " << item.getMagicDefense() << "\n";
	std::cout << "[STRENGTH]: " << item.getStrength() << "\n";
	std::cout << "[INTELLIGENCE]: " << item.getIntelligence() << "\n";
	std::cout << "[DEXTERITY]: " << item.getDexterity() << "\n";
	std::cout << "[CRITICAL CHANCE]: " << item.getCriticalChance() << "\n";
	std::cout << "[PRICE]: " << item.getPrice() << "\n";

	this->enter();
}

bool ConsoleUI::showBuyDecision() {
	std::string answerAsString = "";
	char answer = ' ';
	bool isOptionValid = false;

	while (!isOptionValid) {
		std::cout << "[SHOP MENU] Do you want to buy the item ? Y/N: ";
		std::cin >> answerAsString;

		try {
			if (answerAsString.size() > 1) {
				std::cerr << "[ERROR]: Available options: Y/N y/n!\n\n";
				continue;
			}

			answer = answerAsString[0];

			if (answer  == 'Y' || answer == 'y' ||
				answer == 'N' || answer == 'n') {
				isOptionValid = true;
			}
			else {
				std::cerr << "[ERROR]: Available options: Y/N y/n!\n\n";
			}
		}
		catch (std::invalid_argument& exception) {
			this->showExceptionMessage(exception.what());
			std::cout << "\n\n";
		}
	}

	this->wipe();

	return std::tolower(answer) == 'y';
}