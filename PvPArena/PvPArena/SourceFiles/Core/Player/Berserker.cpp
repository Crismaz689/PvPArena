#include "../../../HeaderFiles/Core/Player/Berserker.h";

int Berserker::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + this->strength + (this->hp / this->DAMAGE_VALUE_DIVIDER_FOR_HP);
}