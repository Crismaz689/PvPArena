#pragma once

#include <string>
#include <vector>

#include "../Enums/ClassName.h";
#include "../Item.h";

class Player {
protected:
	int maxHP = 0;

	int hp = 0;

	int defense = 0;

	int magicDefense = 0;

	int strength = 0;

	int intelligence = 0;

	int dexterity = 0;

	int criticalChance = 0;

	std::string name;

	double gold;

	int stamina;

	std::vector<Item> ownedItems;

	ClassName className;

public:
	Player(std::string name, ClassName className) : name(name), className(className), gold(0), stamina(100) {}

	virtual int calculateDamage() = 0;

	virtual ~Player() {}
};