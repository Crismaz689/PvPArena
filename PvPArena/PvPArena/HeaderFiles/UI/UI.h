#pragma once

#include <string>

class UI {
public:
	UI() {}

	virtual ~UI() {}

	virtual void showHelpInstructions() = 0;

	virtual void showDefaultErrorMessage() = 0;

	virtual void showErrorMessage(std::string message) = 0;
};