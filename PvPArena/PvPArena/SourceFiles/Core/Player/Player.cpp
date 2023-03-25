#include "../../../HeaderFiles/Core/Player/Player.h";

void Player::resetHp() {
	this->hp = this->maxHP;
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

void Player::setGold(double gold) {
	this->gold = gold;
}

void Player::setStamina(int stamina) {
	this->stamina = stamina;
}