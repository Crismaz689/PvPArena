#pragma once

#include "Player.h"

class Paladin : public Player {
public:
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

	~Paladin() {}

	int calculateDamage() override;
};