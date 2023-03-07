#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "../Core/EnumUtil.h";
#include "../Core/Item.h";
#include "../Core/Enums/ItemFilePosition.h";
#include "../Exceptions/FileCouldNotBeOpenedException.h";
#include "../UI/UI.h";

class FileHandler {
private:
	const char DELIMITER = ';';

	void openFile(std::fstream& file, std::_Iosb<int>::_Openmode mode, std::string fileName);

	void closeFile(std::fstream& file);

	bool isFileOpened(std::fstream& file, std::string fileName);

public:
	FileHandler() {}

	~FileHandler() {}

	std::vector<Item> readItemsFromFile(std::string fileName, UI* ui);
};