#include "../../../HeaderFiles/Core/Player/Berserker.h";

int Berserker::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + this->strength + (this->hp / this->DAMAGE_VALUE_DIVIDER_FOR_HP);
}

bool Berserker::calculateBlockChance() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= this->defense + this->DAMAGE_VALUE_DIVIDER_FOR_HP;
}