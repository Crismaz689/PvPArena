#include "../../../HeaderFiles/Core/Player/Archer.h";

int Archer::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + ((dexterity + this->INITIAL_DAMAGE) / (this->REPEAT_ATTACK_CHANCE_MULTIPLIER));
}

bool Archer::isCurrentAttackDoubled() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= dexterity * this->REPEAT_ATTACK_CHANCE_MULTIPLIER;
}

bool Archer::calculateDodgeChance() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= this->dexterity;
}