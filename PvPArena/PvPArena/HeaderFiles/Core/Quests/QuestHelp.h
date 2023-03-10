#pragma once

#include "Quest.h"

class QuestHelp : public Quest {
private:
	int idleTimeInSeconds;

public:
	QuestHelp(QuestType type, std::string description, int staminaCost, double reward,
		int idleTimeInSeconds) :
		Quest(type, description, staminaCost, reward), idleTimeInSeconds(idleTimeInSeconds) {}

	int getIdleTime();

	bool start() override;

	~QuestHelp() {}
};