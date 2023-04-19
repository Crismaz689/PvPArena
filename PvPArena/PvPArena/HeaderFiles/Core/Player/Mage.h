#pragma once

#include "Player.h";

/// <summary>
/// representation of a mage class
/// </summary>
class Mage : public Player {
private:
	const int INITIAL_DAMAGE = 6;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Mage(std::string name, ClassName className) : Player(name, className) {
		this->hp = 80;
		this->maxHP = this->hp;
		this->defense = 2;
		this->magicDefense = 15;
		this->strength = 3;
		this->intelligence = 25;
		this->dexterity = 5;
		this->criticalChance = 0;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~Mage() {}

	/// <summary>
	/// gets calculated damage
	/// </summary>
	/// <returns>calculated damage</returns>
	int calculateDamage() override;

	/// <summary>
	/// gets current attack double
	/// </summary>
	/// <returns>information whether attack is critial</returns>
	bool isHitCritical() override;

	/// <summary>
	/// gets magic attack defense
	/// </summary>
	/// <returns>is magic attack defended</returns>
	bool isDefendedByMagicAttack();
};