#pragma once

#include "Player.h";

/// <summary>
/// representation of a berserker class
/// </summary>
class Berserker : public Player {
private:
	const int INITIAL_DAMAGE = 3;

	const int DAMAGE_VALUE_DIVIDER_FOR_HP = 100;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Berserker(std::string name, ClassName className) : Player(name, className) {
		this->hp = 120;
		this->maxHP = this->hp;
		this->defense = 5;
		this->magicDefense = 5;
		this->strength = 14;
		this->intelligence = 2;
		this->dexterity = 3;
		this->criticalChance = 5;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~Berserker() {}

	/// <summary>
	/// gets calculated damage
	/// </summary>
	/// <returns>calculated damage</returns>
	int calculateDamage() override;

	/// <summary>
	/// gets calculated block
	/// </summary>
	/// <returns>is attack blocked</returns>
	bool calculateBlockChance();
};