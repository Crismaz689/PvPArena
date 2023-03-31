#pragma once

#include <string>

#include "./Enums/ClassName.h";
#include "./Enums/ItemType.h";

class Item {
private:
	int hp;
	int defense;
	int magicDefense;
	int strength;
	int intelligence;
	int dexterity;
	int criticalChance;

	std::string name;
	double price;
	ItemType type;
	ClassName className;

public:
	static const int NUMBER_OF_ARMOR_PARTS = 5;

	Item(int hp, int defense, int magicDefense, int strength, int intelligence, int dexterity,
		int criticalChance, std::string name, double price, ItemType type, ClassName className) :
		hp(hp), defense(defense), magicDefense(magicDefense), strength(strength), intelligence(intelligence),
		dexterity(dexterity), criticalChance(criticalChance), name(name), price(price), type(type), className(className) {}

	~Item() {}

	ItemType getType();

	std::string getName();

	double getPrice();

	ClassName getClassName();

	int getHp();

	int getDefense();

	int getMagicDefense();

	int getStrength();

	int getIntelligence();

	int getDexterity();

	int getCriticalChance();
};