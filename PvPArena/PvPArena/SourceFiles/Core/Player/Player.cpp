#include "../../../HeaderFiles/Core/Player/Player.h";

void Player::resetStats() {
	this->hp = this->maxHP;
	this->stamina = this->MAX_STAMINA_LEVEL;
}

std::string Player::getName() {
	return this->name;
}

double Player::getGold() {
	return this->gold;
}

int Player::getStamina() {
	return this->stamina;
}

int Player::getHp() {
	return this->hp;
}

int Player::getMaxHp() {
	return this->maxHP;
}

void Player::setGold(double gold) {
	this->gold = gold;
}

void Player::setStamina(int stamina) {
	this->stamina = stamina;
}

bool Player::isHitCritical() {
	int x = rand() % 101 + 1;

	return x > 0 && x <= criticalChance;
}

ClassName Player::getClassName() {
	return this->className;
}

void Player::substractHp(int hpToSubtract) {
	this->hp = this->hp - hpToSubtract;
}

int Player::getDefense() {
	return this->defense;
}

int Player::getMagicDefense() {
	return this->magicDefense;
}

int Player::getStrength() {
	return this->strength;
}

int Player::getIntelligence() {
	return this->intelligence;
}

int Player::getDexterity() {
	return this->dexterity;
}

int Player::getCriticalChance() {
	return this->criticalChance;
}

std::vector<Item> Player::getItems() {
	return this->items;
}