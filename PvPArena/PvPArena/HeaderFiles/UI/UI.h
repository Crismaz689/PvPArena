#pragma once

#include <string>

#include "../Core/Enums/ClassName.h";
#include "../Core/Player/Player.h";
#include "../Core/Quests/Quest.h";
#include "../Core/Shop.h";

class Quest;

class UI {
public:
	UI() {}

	virtual ~UI() {}

	virtual void showHelpInstructions() = 0;

	virtual void showDefaultErrorMessage() = 0;

	virtual void showCriticalErrorMessage(std::string message) = 0;

	virtual void showErrorMessage(std::string message) = 0;

	virtual void showArenaResult(Player* player, bool didWin) = 0;

	virtual void showExceptionMessage(std::string message) = 0;

	virtual void showCreatePlayerIntroduction(int playerNumber) = 0;

	virtual void showCreatePlayerClassSelection(int playerNumber) = 0;

	virtual void showClassList() = 0;

	virtual void enter() = 0;

	virtual void waitForContinue() = 0;

	virtual void showInfoMessage(std::string message) = 0;

	virtual void showTurnInfo(Player* player, int currentTurn, int currentDay) = 0;

	virtual void showTurnMenu(bool isChallenged) = 0;

	virtual void wipe() = 0;

	virtual void showQuestsMenu() = 0;

	virtual int getQuestMenuOption() = 0;

	virtual int getTurnMenuOption() = 0;

	virtual void showCurrentQuests(std::vector<Quest*> currentQuests) = 0;

	virtual int getCurrentQuestOption(std::vector<Quest*> currentQuests) = 0;

	virtual void showLostScreen(Player* player) = 0;

	virtual std::string getPlayerName() = 0;

	virtual ClassName getClassName() = 0;

	virtual void showFightStart() = 0;

	virtual void showPlayerDetails(Player* player) = 0;

	virtual void showPlayerEquipment(Player* player) = 0;

	virtual void showItemInfo(Item item) = 0;

	virtual void showShopMenu() = 0;

	virtual int getShopMenuOption() = 0;

	virtual void showAvailableItems(Player* player, std::vector<Item> items) = 0;

	virtual int getCurrentShopOption(std::vector<Item> items) = 0;

	virtual void showItemDetails(std::vector<Item> items, int itemIndex) = 0;

	virtual bool showBuyDecision() = 0;
};