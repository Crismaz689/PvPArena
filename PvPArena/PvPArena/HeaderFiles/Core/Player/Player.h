#pragma once

#include <string>
#include <vector>

#include "../Enums/ClassName.h";
#include "../Item.h";

class Player {
protected:
	const int MAX_STAMINA_LEVEL = 100;

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

	std::vector<Item> items;

	ClassName className;

public:
	static inline ItemType EQUIPMENT[Item::NUMBER_OF_ARMOR_PARTS] = {
		ItemType::Helmet, ItemType::Chest, ItemType::Weapon, ItemType::Pants, ItemType::Boots };

	Player(std::string name, ClassName className) : name(name), className(className), gold(0), stamina(100) {}

	virtual int calculateDamage() = 0;

	virtual bool isHitCritical();

	virtual ~Player() {}

	void resetStats();

	std::string getName();

	double getGold();

	int getStamina();

	int getHp();

	int getMaxHp();

	int getDefense();

	int getMagicDefense();

	int getStrength();

	int getIntelligence();

	int getDexterity();

	int getCriticalChance();

	ClassName getClassName();

	void setStamina(int stamina);

	void setGold(double gold);

	void substractHp(int hpToSubtract);

	std::vector<Item> getItems();
};