#pragma once

#include "Player.h";

class Mage : public Player {
private:
	const int INITIAL_DAMAGE = 6;

public:
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

	~Mage() {}

	int calculateDamage() override;

	bool isHitCritical() override;
};