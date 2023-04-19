#include "../../../HeaderFiles/Core/Player/Mage.h";

int Mage::calculateDamage() {
	return rand() % this->INITIAL_DAMAGE + this->intelligence;
}

// Mage cannot attack by critical hit
bool Mage::isHitCritical() {
	return false;
}

bool Mage::isDefendedByMagicAttack() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= this->magicDefense;
}