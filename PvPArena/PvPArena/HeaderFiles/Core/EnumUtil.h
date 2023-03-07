#pragma once

#include <string>

#include "./Enums/ClassName.h";
#include "./Enums/ItemType.h";

class EnumUtil {
private:
	EnumUtil() {}

	~EnumUtil() {}

public:
	static ClassName convertStringToClassName(std::string word);

	static ItemType convertStringToItemType(std::string word);
};