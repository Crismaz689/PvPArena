#pragma once

#include "../Arena.h";
#include "Quest.h"

class QuestBattle : public Quest {
private:
	std::string enemyName;

	int enemyHp;

	int enemyMinDmg;

	int enemyMaxDmg;

	int enemyChanceForBlock;

public:
	QuestBattle(QuestType type, std::string description, int staminaCost, double reward,
		std::string enemyName, int hp, int minDmg, int maxDmg, int chanceForBlock) :
		Quest(type, description, staminaCost, reward),
		enemyName(enemyName), enemyHp(hp), enemyMinDmg(minDmg), enemyMaxDmg(maxDmg), enemyChanceForBlock(chanceForBlock) {}

	std::string getEnemyName();

	bool start(Player*& player, UI* ui) override;

	~QuestBattle() {};
};