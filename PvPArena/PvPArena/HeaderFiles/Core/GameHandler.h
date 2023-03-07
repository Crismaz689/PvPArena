#pragma once

#include <vector>

#include "./../UI/UI.h";
#include "./../Helpers/FileHandler.h";
#include "./Item.h";
#include "./Quests/Quest.h";

class GameHandler {
private:
	std::vector<Quest*> availableQuests;
	
	std::vector<Item> availableItems;

	void initializeItems(int argc, char* const argv[], UI* ui);

	void initializeQuests(int argc, char* const argv[], UI* ui);

public:
	GameHandler() {}

	~GameHandler();

	void startGame(UI* ui);

	void initialize(int argc, char* const argv[], UI* ui);
};