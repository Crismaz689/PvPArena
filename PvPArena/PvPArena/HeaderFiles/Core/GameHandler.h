#pragma once

#include <vector>

#include "./../UI/UI.h";
#include "./../Helpers/FileHandler.h";
#include "./Player/Player.h";
#include "./Player/Warrior.h";
#include "./Player/Mage.h";
#include "./Player/Sniper.h";
#include "./Player/Archer.h";
#include "./Player/Berserker.h";
#include "./Player/Paladin.h";
#include "./Item.h";
#include "./Quests/Quest.h";

class GameHandler {
private:
	std::vector<Quest*> availableQuests;
	
	std::vector<Item> availableItems;

	Player* playerA = nullptr;

	Player* playerB = nullptr;

	void initializeItems(int argc, char* const argv[], UI* ui);

	void initializeQuests(int argc, char* const argv[], UI* ui);

	void createPlayers(UI* ui);

	Player* createPlayer(UI* ui, int playerNumber);

public:
	GameHandler() {}

	~GameHandler();

	void startGame(UI* ui);

	void initialize(int argc, char* const argv[], UI* ui);
};