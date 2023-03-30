#include "../../../HeaderFiles/Core/Player/Warrior.h";

int Warrior::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + this->strength;
}