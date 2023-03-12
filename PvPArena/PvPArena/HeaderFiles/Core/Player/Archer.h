#pragma once

#include "Player.h";

class Archer : public Player {
public:
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

	~Archer() {}

	int calculateDamage() override;
};