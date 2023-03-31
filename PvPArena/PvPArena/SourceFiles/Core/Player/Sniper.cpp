#include "../../../HeaderFiles/Core/Player/Sniper.h";

int Sniper::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + (dexterity - (dexterity / this->INITIAL_DAMAGE));
}

bool Sniper::isCurrentAttackDoubled() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= dexterity;
}

bool Sniper::calculateDodgeChance() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= this->dexterity + (dexterity - (dexterity / this->INITIAL_DAMAGE));
}