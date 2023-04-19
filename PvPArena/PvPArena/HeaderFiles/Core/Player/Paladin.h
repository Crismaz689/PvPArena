#pragma once

#include "Player.h"

/// <summary>
/// representation of a paladin class
/// </summary>
class Paladin : public Player {
private:
	const int INITIAL_DAMAGE = 2;

	const int DAMAGE_DIVIDER = 2;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Paladin(std::string name, ClassName className) : Player(name, className) {
		this->hp = 120;
		this->maxHP = this->hp;
		this->defense = 5;
		this->magicDefense = 5;
		this->strength = 15;
		this->intelligence = 5;
		this->dexterity = 5;
		this->criticalChance = 5;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~Paladin() {}

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