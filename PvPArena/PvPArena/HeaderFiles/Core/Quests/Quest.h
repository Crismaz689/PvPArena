#pragma once

#include <string>

#include "../Enums/QuestType.h"

class Quest {
private:
	QuestType type;

	std::string description;

	int staminaCost;

	double reward;

public:
	Quest(QuestType type, std::string description, int staminaCost, double reward) : 
	type(type), description(description), staminaCost(staminaCost), reward(reward) {}

	int getStaminaCost();

	QuestType getType();

	double getReward();

	std::string getDescription();

	virtual bool start() = 0;

	virtual ~Quest() {}
};