#pragma once

#include "Player.h";

class Warrior : public Player {
private:
	const int INITIAL_DAMAGE = 5;

public:
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

	~Warrior() {}

	int calculateDamage() override;

	bool calculateBlockChance();
};