#include "../../HeaderFiles/Core/TurnHandler.h"

void TurnHandler::endTurn() {
	this->turnCounter++;
}

unsigned int TurnHandler::getTurn() {
	return this->turnCounter;
}