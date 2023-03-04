#pragma once

class UI {
public:
	UI() {}
	virtual ~UI() {}
	virtual void ShowHelpInstructions() = 0;
	virtual void ShowDefaultErrorMessage() = 0;
	virtual void ShowErrorMessage(std::string message) = 0;
};