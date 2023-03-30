#include "../../../HeaderFiles/Core/Player/Mage.h";

int Mage::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + this->intelligence;
}

// Mage cannot attack with critical hit
bool Mage::isHitCritical() {
	return false;
}