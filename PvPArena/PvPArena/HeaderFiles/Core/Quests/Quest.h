#pragma once

#include <string>

#include "../../UI/UI.h";
#include "../Enums/QuestType.h";

class UI;

class Quest {
protected:
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

	virtual bool start(UI* ui) = 0;

	virtual ~Quest() {}
};