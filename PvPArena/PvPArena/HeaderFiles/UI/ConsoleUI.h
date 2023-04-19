#pragma once

#include <iostream>
#include <string>

#include "UI.h"
#include "../Core/EnumUtil.h";
#include "../Core/Quests/QuestBattle.h";
#include "../Core/Quests/QuestHelp.h";

/// <summary>
/// representation of console user interface
/// </summary>
class ConsoleUI : public UI{
public:
	/// <summary>
	/// default constructor
	/// </summary>
	ConsoleUI() {}

	/// <summary>
	/// destructor
	/// </summary>
	~ConsoleUI() {}

	/// <summary>
	/// shows help instructions
	/// </summary>
	void showHelpInstructions() override;

	/// <summary>
	/// shows default error message
	/// </summary>
	void showDefaultErrorMessage() override;

	/// <summary>
	/// shows critical error message
	/// </summary>
	/// <param name="message">error to display</param>
	void showCriticalErrorMessage(std::string message) override;

	/// <summary>
	/// shows error message
	/// </summary>
	/// <param name="message">error to display</param>
	void showErrorMessage(std::string message) override;

	/// <summary>
	/// shows arena result
	/// </summary>
	/// <param name="player">player who took part in a battle</param>
	/// <param name="didWin">state did player win</param>
	void showArenaResult(Player* player, bool didWin) override;

	/// <summary>
	/// show exception message
	/// </summary>
	/// <param name="message">exception message to dipslay</param>
	void showExceptionMessage(std::string message) override;

	/// <summary>
	/// shows player introduction
	/// </summary>
	/// <param name="playerNumber">player number</param>
	void showCreatePlayerIntroduction(int playerNumber) override;

	/// <summary>
	/// show players class selection
	/// </summary>
	/// <param name="playerNumber">player number</param>
	void showCreatePlayerClassSelection(int playerNumber) override;

	/// <summary>
	/// creates an enter
	/// </summary>
	void enter() override;

	/// <summary>
	/// shows available class list
	/// </summary>
	void showClassList() override;

	/// <summary>
	/// show information message
	/// </summary>
	/// <param name="message">message to display</param>
	void showInfoMessage(std::string message) override;

	/// <summary>
	/// waits for user action
	/// </summary>
	void waitForContinue() override;

	/// <summary>
	/// shows turn info
	/// </summary>
	/// <param name="player">current player</param>
	/// <param name="currentTurn">current turn number</param>
	/// <param name="currentDay">current day number</param>
	void showTurnInfo(Player* player, int currentTurn, int currentDay) override;

	/// <summary>
	/// shows turn menu
	/// </summary>
	/// <param name="isChallenged">is player challenged by another player</param>
	void showTurnMenu(bool isChallenged) override;

	/// <summary>
	/// wipes
	/// </summary>
	void wipe() override;

	/// <summary>
	/// shows quests menu
	/// </summary>
	void showQuestsMenu() override;

	/// <summary>
	/// gets quest menu option
	/// </summary>
	/// <returns>quest menu option</returns>
	int getQuestMenuOption() override;
	
	/// <summary>
	/// gets turn menu option
	/// </summary>
	/// <returns>turn menu option</returns>
	int getTurnMenuOption() override;

	/// <summary>
	/// shows current quests
	/// </summary>
	/// <param name="currentQuests">list of quests</param>
	void showCurrentQuests(std::vector<Quest*> currentQuests) override;

	/// <summary>
	/// shows current quest option
	/// </summary>
	/// <param name="currentQuests">option</param>
	/// <returns>chosen option</returns>
	int getCurrentQuestOption(std::vector<Quest*> currentQuests) override;

	/// <summary>
	/// shows lost screen
	/// </summary>
	/// <param name="player">player who lost</param>
	void showLostScreen(Player* player) override;

	/// <summary>
	/// gets player name
	/// </summary>
	/// <returns>player name</returns>
	std::string getPlayerName() override;

	/// <summary>
	/// gets player class name
	/// </summary>
	/// <returns>player class name</returns>
	ClassName getClassName() override;

	/// <summary>
	/// shows fight start info
	/// </summary>
	void showFightStart() override;

	/// <summary>
	/// shows player details
	/// </summary>
	/// <param name="player">player</param>
	void showPlayerDetails(Player* player) override;

	/// <summary>
	/// shows player equipment
	/// </summary>
	/// <param name="player">player</param>
	void showPlayerEquipment(Player* player) override;

	/// <summary>
	/// show item info
	/// </summary>
	/// <param name="item">item</param>
	void showItemInfo(Item item) override;

	/// <summary>
	/// shows shop menu
	/// </summary>
	void showShopMenu() override;

	/// <summary>
	/// gets shop menu option
	/// </summary>
	/// <returns>chosen option</returns>
	int getShopMenuOption() override;

	/// <summary>
	/// shows available items in shop
	/// </summary>
	/// <param name="player">player</param>
	/// <param name="items">available items</param>
	void showAvailableItems(Player* player, std::vector<Item> items) override;

	/// <summary>
	/// gets current shop option
	/// </summary>
	/// <param name="items">available items</param>
	/// <returns>chosen item index</returns>
	int getCurrentShopOption(std::vector<Item> items) override;

	/// <summary>
	/// shows item details
	/// </summary>
	/// <param name="items">available items</param>
	/// <param name="itemIndex">chosen item index</param>
	void showItemDetails(std::vector<Item> items, int itemIndex) override;

	/// <summary>
	/// shows decision about buying
	/// </summary>
	/// <returns>decision if item should be bought</returns>
	bool showBuyDecision() override;

	/// <summary>
	/// shows decision about dueling
	/// </summary>
	/// <param name="isAlreadyChallenged">is player already challenged</param>
	/// <returns>was duel performed</returns>
	bool showDuelDecision(bool isAlreadyChallenged) override;

	/// <summary>
	/// shows the winner of the game
	/// </summary>
	/// <param name="player">winner</param>
	void showWinner(Player* player);
};