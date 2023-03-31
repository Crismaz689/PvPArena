#pragma once

#include <string>

#include "./Enums/ClassName.h";
#include "./Enums/ItemType.h";
#include "./Enums/QuestType.h";

class EnumUtil {
private:
	EnumUtil() {}

	~EnumUtil() {}

public:
	static ClassName convertStringToClassName(std::string word);

	static std::string convertIntToStringClassName(int value);

	static ItemType convertStringToItemType(std::string word);

	static std::string convertItemTypeToString(ItemType type);

	static QuestType convertStringToQuestType(std::string word);
};