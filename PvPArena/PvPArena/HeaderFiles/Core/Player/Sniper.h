#pragma once

#include "Player.h";

/// <summary>
/// representation of an sniper class
/// </summary>
class Sniper : public Player {
private:
	const int INITIAL_DAMAGE = 10;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Sniper(std::string name, ClassName className) : Player(name, className) {
		this->hp = 100;
		this->maxHP = this->hp;
		this->defense = 5;
		this->magicDefense = 5;
		this->strength = 3;
		this->intelligence = 3;
		this->dexterity = 14;
		this->criticalChance = 5;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~Sniper() {}

	/// <summary>
	/// gets calculated damage
	/// </summary>
	/// <returns>calculated damage</returns>
	int calculateDamage() override;

	/// <summary>
	/// gets current attack double
	/// </summary>
	/// <returns>information whether attack is doubled</returns>
	bool isCurrentAttackDoubled();

	/// <summary>
	/// gets calculated dodge
	/// </summary>
	/// <returns>is attack dodged</returns>
	bool calculateDodgeChance();
};