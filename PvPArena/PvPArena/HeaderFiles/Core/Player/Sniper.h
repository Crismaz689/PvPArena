#pragma once

#include "Player.h";

class Sniper : public Player {
public:
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

	~Sniper() {}

	int calculateDamage() override;
};