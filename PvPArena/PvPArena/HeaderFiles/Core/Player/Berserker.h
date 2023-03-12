#pragma once

#include "Player.h";

class Berserker : public Player {
public:
	Berserker(std::string name, ClassName className) : Player(name, className) {
		this->hp = 120;
		this->maxHP = this->hp;
		this->defense = 5;
		this->magicDefense = 5;
		this->strength = 14;
		this->intelligence = 2;
		this->dexterity = 3;
		this->criticalChance = 5;
	}

	~Berserker() {}

	int calculateDamage() override;
};