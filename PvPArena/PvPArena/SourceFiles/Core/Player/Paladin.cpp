#include "../../../HeaderFiles/Core/Player/Paladin.h";

int Paladin::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + (this->strength / this->DAMAGE_DIVIDER) + (this->intelligence / this->DAMAGE_DIVIDER);
}