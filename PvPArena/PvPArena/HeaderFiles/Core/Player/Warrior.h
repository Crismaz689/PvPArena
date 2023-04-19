#pragma once

#include "Player.h";

/// <summary>
/// representation of a warrior class
/// </summary>
class Warrior : public Player {
private:
	const int INITIAL_DAMAGE = 5;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="name"></param>
	/// <param name="className"></param>
	Warrior(std::string name, ClassName className) : Player(name, className) {
		this->hp = 150;
		this->maxHP = this->hp;
		this->defense = 5;
		this->magicDefense = 5;
		this->strength = 15;
		this->intelligence = 2;
		this->dexterity = 3;
		this->criticalChance = 5;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~Warrior() {}

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