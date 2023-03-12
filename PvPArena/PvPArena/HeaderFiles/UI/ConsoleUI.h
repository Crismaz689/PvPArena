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

	void showErrorMessage(std::string message) override;

	void showExceptionMessage(std::string message) override;

	void showCreatePlayerIntroduction(int playerNumber) override;

	void showCreatePlayerClassSelection(int playerNumber) override;

	void showClassList() override;

	std::string getPlayerName() override;

	ClassName getClassName() override;
};