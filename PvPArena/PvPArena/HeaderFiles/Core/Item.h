#pragma once

#include <string>

#include "./Enums/ClassName.h";
#include "./Enums/ItemType.h";

/// <summary>
/// representation of an item
/// </summary>
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
	/// <summary>
	/// number of armor parts
	/// </summary>
	static const int NUMBER_OF_ARMOR_PARTS = 5;

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="hp"></param>
	/// <param name="defense"></param>
	/// <param name="magicDefense"></param>
	/// <param name="strength"></param>
	/// <param name="intelligence"></param>
	/// <param name="dexterity"></param>
	/// <param name="criticalChance"></param>
	/// <param name="name"></param>
	/// <param name="price"></param>
	/// <param name="type"></param>
	/// <param name="className"></param>
	Item(int hp, int defense, int magicDefense, int strength, int intelligence, int dexterity,
		int criticalChance, std::string name, double price, ItemType type, ClassName className) :
		hp(hp), defense(defense), magicDefense(magicDefense), strength(strength), intelligence(intelligence),
		dexterity(dexterity), criticalChance(criticalChance), name(name), price(price), type(type), className(className) {}

	/// <summary>
	/// destructor
	/// </summary>
	~Item() {}

	/// <summary>
	/// gets type
	/// </summary>
	/// <returns>type of an item</returns>
	ItemType getType();

	/// <summary>
	/// gets a name 
	/// </summary>
	/// <returns>name of an item</returns>
	std::string getName();

	/// <summary>
	/// gets a prive
	/// </summary>
	/// <returns>price of an item</returns>
	double getPrice();

	/// <summary>
	/// gets class name
	/// </summary>
	/// <returns>class name of an item</returns>
	ClassName getClassName();

	/// <summary>
	/// gets hp
	/// </summary>
	/// <returns>hp statistic of an item</returns>
	int getHp();

	/// <summary>
	/// gets defense
	/// </summary>
	/// <returns>defense statistic of an item</returns>
	int getDefense();

	/// <summary>
	/// gets magic defense
	/// </summary>
	/// <returns>magic defense statistic of an item</returns>
	int getMagicDefense();

	/// <summary>
	/// gets strength
	/// </summary>
	/// <returns>strength statistic of an item</returns>
	int getStrength();

	/// <summary>
	/// gets intelligence
	/// </summary>
	/// <returns>intelligence statistic of an item</returns>
	int getIntelligence();

	/// <summary>
	/// gets dexterity
	/// </summary>
	/// <returns>dexterity statistic of an item</returns>
	int getDexterity();

	/// <summary>
	/// gets critical chance
	/// </summary>
	/// <returns>critical chance statistic of an item</returns>
	int getCriticalChance();
};