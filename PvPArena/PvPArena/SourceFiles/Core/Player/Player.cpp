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

void Player::buyItem(Item item) {
	this->gold = this->gold - item.getPrice();

	for (auto& itm : this->items) {
		if (itm.getType() == item.getType()) {
			this->updatePlayerEquipment(itm, item);

			return;
		}
	}
	
	this->updatePlayerEquipment(item);
}

void Player::updatePlayerEquipment(Item itemToReplace, Item itemToAdd) {
	this->removeItem(itemToReplace);
	this->addItem(itemToAdd);
}

void Player::updatePlayerEquipment(Item itemToAdd) {
	this->addItem(itemToAdd);
}

void Player::addItem(Item item) {
	this->maxHP = this->maxHP + item.getHp();
	this->hp = this->hp + item.getHp();
	this->defense = this->defense + item.getDefense();
	this->magicDefense = this->magicDefense + item.getMagicDefense();
	this->strength = this->strength + item.getStrength();
	this->intelligence = this->intelligence + item.getIntelligence();
	this->dexterity = this->dexterity + item.getDexterity();
	this->criticalChance = this->criticalChance + item.getCriticalChance();

	this->items.push_back(item);
}

void Player::removeItem(Item item) {
	this->maxHP = this->maxHP - item.getHp();
	this->hp = this->hp - item.getHp();
	this->defense = this->defense - item.getDefense();
	this->magicDefense = this->magicDefense - item.getMagicDefense();
	this->strength = this->strength - item.getStrength();
	this->intelligence = this->intelligence - item.getIntelligence();
	this->dexterity = this->dexterity - item.getDexterity();
	this->criticalChance = this->criticalChance - item.getCriticalChance();

	for (int i = 0; i < this->items.size(); ++i) {
		if (this->items[i].getName() == item.getName()) {
			auto it = this->items.begin();

			std::advance(it, i);
			this->items.erase(it);
			
			return;
		}
	}
}