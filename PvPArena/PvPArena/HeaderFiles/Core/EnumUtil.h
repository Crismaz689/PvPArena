#pragma once

#include <string>

#include "./Enums/ClassName.h";
#include "./Enums/ItemType.h";
#include "./Enums/QuestType.h";

/// <summary>
/// enumeration helper class
/// </summary>
class EnumUtil {
private:
	EnumUtil() {}

	~EnumUtil() {}

public:
	/// <summary>
	/// converts string to class name
	/// </summary>
	/// <param name="word">class name as string</param>
	/// <returns>class name</returns>
	static ClassName convertStringToClassName(std::string word);

	/// <summary>
	/// converts int to string class name
	/// </summary>
	/// <param name="word">class name as int</param>
	/// <returns>class name as string</returns>
	static std::string convertIntToStringClassName(int value);

	/// <summary>
	/// converts string into item type
	/// </summary>
	/// <param name="word">item type as string</param>
	/// <returns>item type</returns>
	static ItemType convertStringToItemType(std::string word);

	/// <summary>
	/// converts item type to string
	/// </summary>
	/// <param name="word">item type</param>
	/// <returns>item type as string</returns>
	static std::string convertItemTypeToString(ItemType type);

	/// <summary>
	/// converts string to quest type
	/// </summary>
	/// <param name="word">quest as string</param>
	/// <returns>quest type</returns>
	static QuestType convertStringToQuestType(std::string word);
};