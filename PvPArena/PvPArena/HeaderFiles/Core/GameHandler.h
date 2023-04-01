#pragma once

#include <algorithm>
#include <vector>

#include "./../UI/UI.h";
#include "./../Helpers/FileHandler.h";
#include "./../Helpers/MemoryHandler.h";
#include "./Player/Player.h";
#include "./Player/Warrior.h";
#include "./Player/Mage.h";
#include "./Player/Sniper.h";
#include "./Player/Archer.h";
#include "./Player/Berserker.h";
#include "./Player/Paladin.h";
#include "./Item.h";
#include "./TurnHandler.h";
#include "./Quests/Quest.h";
#include "./Shop.h";

class GameHandler {
private:
	const unsigned int QUESTS_PER_TURN = 5;

	std::vector<Quest*> availableQuests;
	
	Shop* shop = nullptr;

	UI* ui = nullptr;

	Player* playerA = nullptr;

	Player* playerB = nullptr;

	TurnHandler* turnHandler = nullptr;

	void initializeItems(int argc, char* const argv[]);

	void initializeQuests(int argc, char* const argv[]);

	void createPlayers();

	Player* createPlayer(int playerNumber);

	std::vector<Quest*> randomizeQuests();

	void clearCurrentQuests(std::vector<Quest*>& quests);

	void handleTurn(Player* player, std::vector<Quest*> currentQuests);

	void handleQuestMenu(Player*& player, std::vector<Quest*>& currentQuests, bool& isPlayerDead);

	void chooseQuestMenu(Player*& player, std::vector<Quest*>& currentQuests, bool& isPlayerDead);

	bool takeQuest(Player*& player, Quest* quest, bool& isPlayerDead);

	void addGold(Player*& player, double goldToAdd);

	void removeStamina(Player*& player, int staminaToLose);

	void deleteQuest(std::vector<Quest*>& currentQuests, int chosenQuestIndex);

	void handleShopMenu(Player*& player);

	void chooseShopMenu(Player*& player);

public:
	GameHandler() {}

	~GameHandler();

	void startGame();

	void initialize(int argc, char* const argv[], UI* ui);
};