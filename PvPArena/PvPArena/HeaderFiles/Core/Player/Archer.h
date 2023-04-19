#pragma once

#include "Player.h";

/// <summary>
/// representation of an archer class
/// </summary>
class Archer : public Player {
private:
	const int REPEAT_ATTACK_CHANCE_MULTIPLIER = 3;

	const int INITIAL_DAMAGE = 4;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Archer(std::string name, ClassName className) : Player(name, className) {
		this->hp = 120;
		this->maxHP = this->hp;
		this->defense = 5;
		this->magicDefense = 5;
		this->strength = 10;
		this->intelligence = 3;
		this->dexterity = 18;
		this->criticalChance = 5;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~Archer() {}

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