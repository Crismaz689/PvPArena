#pragma once

#include <iostream>
#include <string>

#include "UI.h"
#include "../Core/EnumUtil.h";
#include "../Core/Quests/QuestBattle.h";
#include "../Core/Quests/QuestHelp.h";

class ConsoleUI : public UI{
public:
	ConsoleUI() {}

	~ConsoleUI() {}

	void showHelpInstructions() override;

	void showDefaultErrorMessage() override;

	void showCriticalErrorMessage(std::string message) override;

	void showErrorMessage(std::string message) override;

	void showArenaResult(Player* player, bool didWin) override;

	void showExceptionMessage(std::string message) override;

	void showCreatePlayerIntroduction(int playerNumber) override;

	void showCreatePlayerClassSelection(int playerNumber) override;

	void enter() override;

	void showClassList() override;

	void showInfoMessage(std::string message) override;

	void waitForContinue() override;

	void showTurnInfo(Player* player, int currentTurn, int currentDay) override;

	void showTurnMenu(bool isChallenged) override;

	void wipe() override;

	void showQuestsMenu() override;

	int getQuestMenuOption() override;

	int getTurnMenuOption() override;

	void showCurrentQuests(std::vector<Quest*> currentQuests) override;

	int getCurrentQuestOption(std::vector<Quest*> currentQuests) override;

	void showLostScreen(Player* player) override;

	std::string getPlayerName() override;

	ClassName getClassName() override;

	void showFightStart() override;

	void showPlayerDetails(Player* player) override;

	void showPlayerEquipment(Player* player) override;

	void showItemInfo(Item item) override;

	void showShopMenu() override;

	int getShopMenuOption() override;

	void showAvailableItems(Player* player, std::vector<Item> items) override;

	int getCurrentShopOption(std::vector<Item> items) override;

	void showItemDetails(std::vector<Item> items, int itemIndex) override;

	bool showBuyDecision() override;
};