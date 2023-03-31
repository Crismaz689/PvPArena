#include "../../../HeaderFiles/Core/Player/Warrior.h";

int Warrior::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + this->strength;
}


bool Warrior::calculateBlockChance() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= this->defense;
}