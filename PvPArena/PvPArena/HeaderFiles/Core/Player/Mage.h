#pragma once

#include "Player.h";

class Mage : public Player {
public:
	Mage(std::string name, ClassName className) : Player(name, className) {
		this->hp = 80;
		this->maxHP = this->hp;
		this->defense = 2;
		this->magicDefense = 15;
		this->strength = 3;
		this->intelligence = 25;
		this->dexterity = 5;
		this->criticalChance = 1;
	}

	~Mage() {}

	int calculateDamage() override;
};