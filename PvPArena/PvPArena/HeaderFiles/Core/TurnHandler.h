#pragma once

class TurnHandler {
private:
	unsigned int turnCounter;

public:
	const static unsigned int MAX_TURNS = 20;

	TurnHandler() : turnCounter(0) {}

	~TurnHandler() {}

	void endTurn();

	unsigned int getTurn();
};