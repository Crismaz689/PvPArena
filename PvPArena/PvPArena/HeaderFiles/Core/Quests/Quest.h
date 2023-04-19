#pragma once

#include <string>

#include "../../UI/UI.h";
#include "../Enums/QuestType.h";

class UI;

/// <summary>
/// representation of a quest
/// </summary>
class Quest {
protected:
	/// <summary>
	/// type of quest
	/// </summary>
	QuestType type;

	/// <summary>
	/// quest description
	/// </summary>
	std::string description;

	/// <summary>
	/// stamina cost
	/// </summary>
	int staminaCost;

	/// <summary>
	/// reward (gold)
	/// </summary>
	double reward;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="type"></param>
	/// <param name="description"></param>
	/// <param name="staminaCost"></param>
	/// <param name="reward"></param>
	Quest(QuestType type, std::string description, int staminaCost, double reward) : 
	type(type), description(description), staminaCost(staminaCost), reward(reward) {}

	/// <summary>
	/// gets stamina cost
	/// </summary>
	/// <returns>stamina cost</returns>
	int getStaminaCost();

	/// <summary>
	/// gets quest type
	/// </summary>
	/// <returns>quest type</returns>
	QuestType getType();

	/// <summary>
	/// gets reward (gold)
	/// </summary>
	/// <returns>reward (gold)</returns>
	double getReward();

	/// <summary>
	/// gets description
	/// </summary>
	/// <returns>quest description</returns>
	std::string getDescription();

	/// <summary>
	/// starts a quest - abstract
	/// </summary>
	/// <param name="player">player who takes a quest</param>
	/// <param name="ui">user interface</param>
	/// <returns>was successfully finished</returns>
	virtual bool start(Player*& player, UI* ui) = 0;

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Quest() {}
};