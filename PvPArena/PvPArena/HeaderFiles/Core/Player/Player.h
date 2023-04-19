#pragma once

#include <string>
#include <vector>

#include "../Enums/ClassName.h";
#include "../Item.h";

/// <summary>
/// representation of a player
/// </summary>
class Player {
protected:
	/// <summary>
	/// maximum stamina level
	/// </summary>
	const int MAX_STAMINA_LEVEL = 100;

	/// <summary>
	/// maximum health points
	/// </summary>
	int maxHP = 0;

	/// <summary>
	/// health points
	/// </summary>
	int hp = 0;

	/// <summary>
	/// defense
	/// </summary>
	int defense = 0;

	/// <summary>
	/// magic defense
	/// </summary>
	int magicDefense = 0;

	/// <summary>
	/// strength
	/// </summary>
	int strength = 0;

	/// <summary>
	/// intelligence
	/// </summary>
	int intelligence = 0;

	/// <summary>
	/// dexterity
	/// </summary>
	int dexterity = 0;

	/// <summary>
	/// critical chance
	/// </summary>
	int criticalChance = 0;

	/// <summary>
	/// name
	/// </summary>
	std::string name;

	/// <summary>
	/// gold
	/// </summary>
	double gold;

	/// <summary>
	/// stamina
	/// </summary>
	int stamina;

	/// <summary>
	/// owned items
	/// </summary>
	std::vector<Item> items;

	/// <summary>
	/// class name
	/// </summary>
	ClassName className;

	/// <summary>
	/// updates statistic based on equipment
	/// </summary>
	/// <param name="itemToReplace">item to replace</param>
	/// <param name="itemToAdd">item to add</param>
	void updatePlayerEquipment(Item itemToReplace, Item itemToAdd);

	/// <summary>
	/// updates statistic based on equipment
	/// </summary>
	/// <param name="itemToAdd">item to add</param>
	void updatePlayerEquipment(Item itemToAdd);

	/// <summary>
	/// adds item to owned items
	/// </summary>
	/// <param name="item">item to add</param>
	void addItem(Item item);

	/// <summary>
	/// removes item from owned items
	/// </summary>
	/// <param name="item">item to remove</param>
	void removeItem(Item item);

public:
	/// <summary>
	/// types of equipments parts
	/// </summary>
	static inline ItemType EQUIPMENT[Item::NUMBER_OF_ARMOR_PARTS] = {
		ItemType::Helmet, ItemType::Chest, ItemType::Weapon, ItemType::Pants, ItemType::Boots };

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Player(std::string name, ClassName className) : name(name), className(className), gold(0), stamina(100) {}

	/// <summary>
	/// gets calculated damage - abstract
	/// </summary>
	/// <returns>calculated damage</returns>
	virtual int calculateDamage() = 0;

	/// <summary>
	/// gets critical hit info
	/// </summary>
	/// <returns>is hit critital</returns>
	virtual bool isHitCritical();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Player() {}

	/// <summary>
	/// resets statistics
	/// </summary>
	void resetStats();

	/// <summary>
	/// gets a name
	/// </summary>
	/// <returns>players name</returns>
	std::string getName();

	/// <summary>
	/// gets a gold
	/// </summary>
	/// <returns>players gold</returns>
	double getGold();

	/// <summary>
	/// gets a stamina
	/// </summary>
	/// <returns>players stamina</returns>
	int getStamina();

	/// <summary>
	/// gets a hp
	/// </summary>
	/// <returns>players hp</returns>
	int getHp();

	/// <summary>
	/// gets a max hp
	/// </summary>
	/// <returns>players max hp</returns>
	int getMaxHp();

	/// <summary>
	/// gets a defense
	/// </summary>
	/// <returns>players defense</returns>
	int getDefense();
	
	/// <summary>
	/// gets a magic defense
	/// </summary>
	/// <returns>players magic defense</returns>
	int getMagicDefense();

	/// <summary>
	/// gets a strength
	/// </summary>
	/// <returns>players strength</returns>
	int getStrength();

	/// <summary>
	/// gets a intelligence
	/// </summary>
	/// <returns>players intelligence</returns>
	int getIntelligence();

	/// <summary>
	/// gets a dexterity
	/// </summary>
	/// <returns>players dexterity</returns>
	int getDexterity();

	/// <summary>
	/// gets a critical chance
	/// </summary>
	/// <returns>players critical chance</returns>
	int getCriticalChance();

	/// <summary>
	/// gets a class name
	/// </summary>
	/// <returns>players class name</returns>
	ClassName getClassName();

	/// <summary>
	/// sets stamina
	/// </summary>
	/// <param name="stamina">stamina to set</param>
	void setStamina(int stamina);

	/// <summary>
	/// sets gold
	/// </summary>
	/// <param name="gold">gold to set</param>
	void setGold(double gold);

	/// <summary>
	/// substracts hp
	/// </summary>
	/// <param name="hpToSubtract">amount hp to substract</param>
	void substractHp(int hpToSubtract);

	/// <summary>
	/// gets owned items
	/// </summary>
	/// <returns>owned ites</returns>
	std::vector<Item> getItems();

	/// <summary>
	/// buys an item
	/// </summary>
	/// <param name="item">item to buy</param>
	void buyItem(Item item);
};