#include "../../HeaderFiles/Core/Item.h";

ItemType Item::getType() {
	return this->type;
}

std::string Item::getName() {
	return this->name;
}

double Item::getPrice() {
	return this->price;
}

ClassName Item::getClassName() {
	return this->className;
}

int Item::getHp() {
	return this->hp;
}

int Item::getDefense() {
	return this->defense;
}

int Item::getMagicDefense() {
	return this->magicDefense;
}

int Item::getStrength() {
	return this->strength;
}

int Item::getIntelligence() {
	return this->intelligence;
}

int Item::getDexterity() {
	return this->dexterity;
}

int Item::getCriticalChance() {
	return this->criticalChance;
}