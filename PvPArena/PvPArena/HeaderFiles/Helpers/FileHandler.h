#pragma once

#include <fstream>
#include <vector>

#include "../Core/EnumUtil.h";
#include "../Core/Item.h";
#include "../Core/Quests/Quest.h";
#include "../Core/Quests/QuestHelp.h";
#include "../Core/Quests/QuestBattle.h";
#include "../Core/Enums/ItemFilePosition.h";
#include "../Core/Enums/QuestBattleFilePosition.h";
#include "../Core/Enums/QuestHelpFilePosition.h";
#include "../Exceptions/FileCouldNotBeOpenedException.h";
#include "../UI/UI.h";

/// <summary>
/// handles file 
/// </summary>
class FileHandler {
private:
	const char DELIMITER = ';';

	void openFile(std::fstream& file, std::_Iosb<int>::_Openmode mode, std::string fileName);

	void closeFile(std::fstream& file);

	bool isFileOpened(std::fstream& file, std::string fileName);

public:
	/// <summary>
	/// default constructor
	/// </summary>
	FileHandler() {}

	/// <summary>
	/// destructor
	/// </summary>
	~FileHandler() {}

	/// <summary>
	/// reads items from given file
	/// </summary>
	/// <param name="fileName">filename</param>
	/// <param name="ui">user interface</param>
	/// <returns>list of read items</returns>
	std::vector<Item> readItemsFromFile(std::string fileName, UI* ui);

	/// <summary>
	/// reads quests from given file
	/// </summary>
	/// <param name="fileName">filename</param>
	/// <param name="ui">user interface</param>
	/// <returns>list of read quests as pointers</returns>
	std::vector<Quest*> readQuestsFromFile(std::string fileName, UI* ui);
};