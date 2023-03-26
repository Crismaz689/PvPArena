#include "../../HeaderFiles/Core/Monster.h";

std::string Monster::getName() {
	return this->name;
}

int Monster::getHP() {
	return this->hp;
}

void Monster::substractHP(int damage) {
	this->hp = this->hp - damage;
}

int Monster::getAttackValue() {
	return rand() % this->maxDmg + this->minDmg;
}

bool Monster::isAttackBlocked() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= chanceForBlock;
}