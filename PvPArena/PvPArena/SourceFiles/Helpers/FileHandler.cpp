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
			int letters = 0;
			int wordNumber = 0;

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