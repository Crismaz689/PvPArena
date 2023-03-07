#pragma once

#include <iostream>
#include <string>

#include "UI.h"

class ConsoleUI : public UI{
public:
	ConsoleUI() {}

	~ConsoleUI() {}

	void showHelpInstructions() override;

	void showDefaultErrorMessage() override;

	void showErrorMessage(std::string message) override;
};