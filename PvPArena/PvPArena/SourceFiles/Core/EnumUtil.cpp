#include "../../HeaderFiles/Core/EnumUtil.h";

ClassName EnumUtil::convertStringToClassName(std::string word) {
	if (word == "Warrior")
		return ClassName::Warrior;
	else if (word == "Mage")
		return ClassName::Mage;
	else if (word == "Paladin")
		return ClassName::Paladin;
	else if (word == "Archer")
		return ClassName::Archer;
	else if (word == "Sniper")
		return ClassName::Sniper;
	else
		return ClassName::Berserker;
}

std::string EnumUtil::convertIntToStringClassName(int value) {
	switch (value) {
		case 0:
			return "Warrior";
		case 1:
			return "Mage";
		case 2:
			return "Paladin";
		case 3:
			return "Archer";
		case 4:
			return "Sniper";
		default:
			return "Berserker";
	}
}

ItemType EnumUtil::convertStringToItemType(std::string word) {
	if (word == "Helmet")
		return ItemType::Helmet;
	else if (word == "Chest")
		return ItemType::Chest;
	else if (word == "Weapon")
		return ItemType::Weapon;
	else if (word == "Pants")
		return ItemType::Pants;
	else
		return ItemType::Boots;
}

QuestType EnumUtil::convertStringToQuestType(std::string word) {
	return word == "Battle" ?
		QuestType::Battle :
		QuestType::Help;
}