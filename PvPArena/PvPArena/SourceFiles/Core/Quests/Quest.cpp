#include "../../../HeaderFiles/Core/Quests/Quest.h";


int Quest::getStaminaCost() {
	return this->staminaCost;
}

double Quest::getReward() {
	return this->reward;
}

QuestType Quest::getType() {
	return this->type;
}

std::string Quest::getDescription() {
	return this->description;
}