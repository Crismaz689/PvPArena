#include "../../../HeaderFiles/Core/Player/Paladin.h";

int Paladin::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + (this->strength / this->DAMAGE_DIVIDER) + (this->intelligence / this->DAMAGE_DIVIDER);
}

bool Paladin::calculateBlockChance() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= this->defense + ((this->strength / this->DAMAGE_DIVIDER) + (this->intelligence / this->DAMAGE_DIVIDER));
}