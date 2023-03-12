#pragma once

#include <string>

#include "../Core/Enums/ClassName.h";
#include "../Core/Player/Player.h";

class UI {
public:
	UI() {}

	virtual ~UI() {}

	virtual void showHelpInstructions() = 0;

	virtual void showDefaultErrorMessage() = 0;

	virtual void showCriticalErrorMessage(std::string message) = 0;

	virtual void showErrorMessage(std::string message) = 0;

	virtual void showExceptionMessage(std::string message) = 0;

	virtual void showCreatePlayerIntroduction(int playerNumber) = 0;

	virtual void showCreatePlayerClassSelection(int playerNumber) = 0;

	virtual void showClassList() = 0;

	virtual void waitForContinue() = 0;

	virtual void showInfoMessage(std::string message) = 0;

	virtual void showTurnInfo(Player* player, int currentTurn, int currentDay) = 0;

	virtual void showTurnMenu(bool isChallenged) = 0;

	virtual void wipe() = 0;

	virtual int getTurnMenuOption() = 0;

	virtual std::string getPlayerName() = 0;

	virtual ClassName getClassName() = 0;
};