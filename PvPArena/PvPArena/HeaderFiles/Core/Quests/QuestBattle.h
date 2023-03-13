#pragma once

#include "Quest.h"

class QuestBattle : public Quest {
private:
	std::string enemyName;

	int hp;

	int minDmg;

	int maxDmg;

	int chanceForBlock;

public:
	QuestBattle(QuestType type, std::string description, int staminaCost, double reward,
		std::string enemyName, int hp, int minDmg, int maxDmg, int chanceForBlock) :
		Quest(type, description, staminaCost, reward),
		enemyName(enemyName), hp(hp), minDmg(minDmg), maxDmg(maxDmg), chanceForBlock(chanceForBlock) {}

	std::string getEnemyName();

	bool start() override;

	~QuestBattle() {};
};