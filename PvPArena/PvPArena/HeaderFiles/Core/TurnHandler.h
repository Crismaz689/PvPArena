#pragma once

/// <summary>
/// handles turns
/// </summary>
class TurnHandler {
private:
	unsigned int turnCounter;

public:
	/// <summary>
	/// number of turns in game
	/// </summary>
	const static unsigned int MAX_TURNS = 20;

	/// <summary>
	/// default constructor
	/// </summary>
	TurnHandler() : turnCounter(0) {}

	/// <summary>
	/// destructor
	/// </summary>
	~TurnHandler() {}

	/// <summary>
	/// ends turn
	/// </summary>
	void endTurn();

	/// <summary>
	/// gets number of turn
	/// </summary>
	/// <returns>turn number</returns>
	unsigned int getTurn();
};