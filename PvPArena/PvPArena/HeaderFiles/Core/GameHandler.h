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

/// <summary>
/// responsible for main game handling
/// </summary>
class GameHandler {
private:
	const unsigned int QUESTS_PER_TURN = 5;

	std::vector<Quest*> availableQuests;
	
	Shop* shop = nullptr;

	UI* ui = nullptr;

	Player* playerA = nullptr;

	Player* playerB = nullptr;

	TurnHandler* turnHandler = nullptr;

	bool isPlayerChallanged = false;

	int challangeTurnCounter = 0;

	void initializeItems(int argc, char* const argv[]);

	void initializeQuests(int argc, char* const argv[]);

	void createPlayers();

	Player* createPlayer(int playerNumber);

	std::vector<Quest*> randomizeQuests();

	void handleTurn(Player* player, std::vector<Quest*> currentQuests);

	void handleQuestMenu(Player*& player, std::vector<Quest*>& currentQuests, bool& isPlayerDead);

	void chooseQuestMenu(Player*& player, std::vector<Quest*>& currentQuests, bool& isPlayerDead);

	bool takeQuest(Player*& player, Quest* quest, bool& isPlayerDead);

	void addGold(Player*& player, double goldToAdd);

	void removeStamina(Player*& player, int staminaToLose);

	void deleteQuest(std::vector<Quest*>& currentQuests, int chosenQuestIndex);

	void handleShopMenu(Player*& player);

	void chooseShopMenu(Player*& player);

	bool handleChallengeMenu(Player* currentPlayer);

public:
	/// <summary>
	/// default constructor
	/// </summary>
	GameHandler() {}

	/// <summary>
	/// destructor
	/// </summary>
	~GameHandler();

	/// <summary>
	/// starts the game
	/// </summary>
	void startGame();

	/// <summary>
	/// initialize structures with given arguments
	/// </summary>
	void initialize(int argc, char* const argv[], UI* ui);
};