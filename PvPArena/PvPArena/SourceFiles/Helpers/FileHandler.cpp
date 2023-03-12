#include "../../HeaderFiles/Helpers/FileHandler.h";

void FileHandler::openFile(std::fstream& file, std::_Iosb<int>::_Openmode mode, std::string fileName) {
	file.open(fileName, mode);
}

void FileHandler::closeFile(std::fstream& file) {
	file.close();
}

bool FileHandler::isFileOpened(std::fstream& file, std::string fileName) {
	return file.good() ?
		true :
		throw FileCouldNotBeOpenedException(fileName);
}


std::vector<Item> FileHandler::readItemsFromFile(std::string fileName, UI* ui) { // std::istream file
	// result object
	std::vector<Item> items;

	try {
		// variable for file handling
		std::fstream file;

		this->openFile(file, std::ios::in, fileName);
		if (this->isFileOpened(file, fileName)) {

			// variables for handling file line
			std::string line = "";
			std::string word = "";

			// variables for Item class
			int hp = 0;
			int defense = 0;
			int magicDefense = 0;
			int strength = 0;
			int intelligence = 0;
			int dexterity = 0;
			int criticalChance = 0;

			std::string itemName = "";
			double price = 0;
			ItemType itemType = ItemType::Boots;
			ClassName clsName = ClassName::Warrior;

			while (std::getline(file, line)) {
				int letterPosition = 0;
				int wordNumber = 0;
				std::string word = "";

				while ((letterPosition = line.find(DELIMITER)) != std::string::npos) {
					word = line.substr(0, letterPosition);
					line.erase(0, letterPosition + 1); // + 1 due to delimiter length

					switch ((ItemFilePosition)wordNumber) {
					case ItemFilePosition::ItemName:
						itemName = word;
						break;
					case ItemFilePosition::ClassName:
						clsName = EnumUtil::convertStringToClassName(word);
						break;
					case ItemFilePosition::ItemType:
						itemType = EnumUtil::convertStringToItemType(word);
						break;
					case ItemFilePosition::Hp:
						hp = stoi(word);
						break;
					case ItemFilePosition::Defense:
						defense = stoi(word);
						break;
					case ItemFilePosition::MagicDefense:
						magicDefense = stoi(word);
						break;
					case ItemFilePosition::Strength:
						strength = stoi(word);
						break;
					case ItemFilePosition::Intelligence:
						intelligence = stoi(word);
						break;
					case ItemFilePosition::Dexterity:
						dexterity = stoi(word);
						break;
					case ItemFilePosition::CriticalChance:
						criticalChance = stoi(word);
						break;
					}
					wordNumber++;
				}

				price = stod(line); // last position in line
				Item itemToAdd(hp, defense, magicDefense, strength, intelligence, dexterity, criticalChance, itemName, price, itemType, clsName);
				items.push_back(itemToAdd);
			}
			this->closeFile(file);
		}
	}
	catch (FileCouldNotBeOpenedException exception) {
		ui->showErrorMessage(exception.what());
	}

	return items;
}

std::vector<Quest*> FileHandler::readQuestsFromFile(std::string fileName, UI* ui) {

	// result object
	std::vector<Quest*> quests;

	try {
		// variable for file handling
		std::fstream file;

		this->openFile(file, std::ios::in, fileName);
		if (this->isFileOpened(file, fileName)) {

			// variables for handling file line
			std::string line = "";
			std::string word = "";

			// Quest members
			QuestType questType = QuestType::Battle;
			std::string questDescription = "";
			int staminaCost = 0;
			double reward = 0;

			// QuestHelp members
			int idleTimeInSeconds = 0;

			// QuestBattle members
			std::string enemyName = "";
			int hp = 0;
			int minDmg = 0;
			int maxDmg = 0;
			int chanceForBlock = 0;

			while (std::getline(file, line)) {
				questType = QuestType::Battle;
				int letterPosition = 0;
				int wordNumber = 0;
				std::string word = "";

				while ((letterPosition = line.find(DELIMITER)) != std::string::npos) {
					word = line.substr(0, letterPosition);
					line.erase(0, letterPosition + 1); // + 1 due to delimiter length

					if (wordNumber == 0) {
						if (EnumUtil::convertStringToQuestType(word) == QuestType::Help) {
							questType = QuestType::Help;
						}

						wordNumber++;
						continue;
					}

					if (questType == QuestType::Help) {
						switch ((QuestHelpFilePosition)wordNumber) {
							case QuestHelpFilePosition::Description:
								questDescription = word;
								break;
							case QuestHelpFilePosition::IdleTimeInSeconds:
								idleTimeInSeconds = stoi(word);
								break;
							case QuestHelpFilePosition::StaminaCost:
								staminaCost = stoi(word);
								break;
						}
					}
					else {
						switch ((QuestBattleFilePosition)wordNumber) {
							case QuestBattleFilePosition::Description:
								questDescription = word;
								break;
							case QuestBattleFilePosition::EnemyName:
								enemyName = word;
								break;
							case QuestBattleFilePosition::EnemyHp:
								hp = stoi(word);
								break;
							case QuestBattleFilePosition::EnemyMinDmg:
								minDmg = stoi(word);
								break;
							case QuestBattleFilePosition::EnemyMaxDmg:
								maxDmg = stoi(word);
								break;
							case QuestBattleFilePosition::EnemyChanceForBlock:
								chanceForBlock = stoi(word);
								break;
							case QuestBattleFilePosition::StaminaCost:
								staminaCost = stoi(word);
								break;
						}
					}

					wordNumber++;
				}

				reward = stod(line); // last position in line

				if (questType == QuestType::Help) {
					quests.push_back(new QuestHelp(questType, questDescription, staminaCost, reward, idleTimeInSeconds));
				}
				else {
					quests.push_back(new QuestBattle(questType, questDescription, staminaCost, reward, enemyName,
						hp, minDmg, maxDmg, chanceForBlock));
				}
				
			}
			this->closeFile(file);
		}
	}
	catch (FileCouldNotBeOpenedException exception) {
		ui->showErrorMessage(exception.what());
	}

	return quests;
}