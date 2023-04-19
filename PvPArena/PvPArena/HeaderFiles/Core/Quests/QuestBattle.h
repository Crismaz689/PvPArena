#pragma once

#include "../Arena.h";
#include "Quest.h"

/// <summary>
/// representation of battle quest
/// </summary>
class QuestBattle : public Quest {
private:
	std::string enemyName;

	int enemyHp;

	int enemyMinDmg;

	int enemyMaxDmg;

	int enemyChanceForBlock;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="type"></param>
	/// <param name="description"></param>
	/// <param name="staminaCost"></param>
	/// <param name="reward"></param>
	/// <param name="enemyName"></param>
	/// <param name="hp"></param>
	/// <param name="minDmg"></param>
	/// <param name="maxDmg"></param>
	/// <param name="chanceForBlock"></param>
	QuestBattle(QuestType type, std::string description, int staminaCost, double reward,
		std::string enemyName, int hp, int minDmg, int maxDmg, int chanceForBlock) :
		Quest(type, description, staminaCost, reward),
		enemyName(enemyName), enemyHp(hp), enemyMinDmg(minDmg), enemyMaxDmg(maxDmg), enemyChanceForBlock(chanceForBlock) {}

	/// <summary>
	/// gets enemy name (monster)
	/// </summary>
	/// <returns>enemy name (monster)</returns>
	std::string getEnemyName();

	/// <summary>
	/// starts a quest
	/// </summary>
	/// <param name="player">player who takes a quest</param>
	/// <param name="ui">user interface</param>
	/// <returns>was successfully finished</returns>
	bool start(Player*& player, UI* ui) override;

	/// <summary>
	/// destructor
	/// </summary>
	~QuestBattle() {};
};