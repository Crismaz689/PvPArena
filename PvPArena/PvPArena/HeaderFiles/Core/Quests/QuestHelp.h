#pragma once

#include <chrono>
#include <thread>

#include "Quest.h"

/// <summary>
/// representation of help quest
/// </summary>
class QuestHelp : public Quest {
private:
	int idleTimeInSeconds;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="type"></param>
	/// <param name="description"></param>
	/// <param name="staminaCost"></param>
	/// <param name="reward"></param>
	/// <param name="idleTimeInSeconds"></param>
	QuestHelp(QuestType type, std::string description, int staminaCost, double reward,
		int idleTimeInSeconds) :
		Quest(type, description, staminaCost, reward), idleTimeInSeconds(idleTimeInSeconds) {}

	/// <summary>
	/// gets idle time (in seconds)
	/// </summary>
	/// <returns>idle time (in seconds)</returns>
	int getIdleTime();

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
	~QuestHelp() {}
};