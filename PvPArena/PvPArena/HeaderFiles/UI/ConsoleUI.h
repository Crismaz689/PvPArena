#pragma once

#include <iostream>
#include <string>

#include "UI.h"

class ConsoleUI : public UI{
public:
	ConsoleUI() {}

	~ConsoleUI() {}

	void ShowHelpInstructions();

	void ShowDefaultErrorMessage();

	void ShowErrorMessage(std::string message);
};