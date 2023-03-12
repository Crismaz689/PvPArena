#pragma once

#include <iostream>
#include <string>

#include "UI.h"
#include "../Core/EnumUtil.h";

class ConsoleUI : public UI{
public:
	ConsoleUI() {}

	~ConsoleUI() {}

	void showHelpInstructions() override;

	void showDefaultErrorMessage() override;

	void showCriticalErrorMessage(std::string message) override;

	void showErrorMessage(std::string message) override;

	void showExceptionMessage(std::string message) override;

	void showCreatePlayerIntroduction(int playerNumber) override;

	void showCreatePlayerClassSelection(int playerNumber) override;

	void showClassList() override;

	void showInfoMessage(std::string message) override;

	void waitForContinue() override;

	void showTurnInfo(Player* player, int currentTurn, int currentDay) override;

	void showTurnMenu(bool isChallenged) override;

	void wipe() override;

	int getTurnMenuOption() override;

	std::string getPlayerName() override;

	ClassName getClassName() override;
};