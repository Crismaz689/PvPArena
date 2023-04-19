#pragma once

#include <string>

#include "../Core/Enums/ClassName.h";
#include "../Core/Player/Player.h";
#include "../Core/Quests/Quest.h";
#include "../Core/Shop.h";

class Quest;

/// <summary>
/// representation of user interface
/// </summary>
class UI {
public:

	/// <summary>
	/// default constructor
	/// </summary>
	UI() {}

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~UI() {}

	/// <summary>
	/// shows help instructions
	/// </summary>
	virtual void showHelpInstructions() = 0;

	/// <summary>
	/// shows default error message
	/// </summary>
	virtual void showDefaultErrorMessage() = 0;

	/// <summary>
	/// shows critical error message
	/// </summary>
	/// <param name="message">error to display</param>
	virtual void showCriticalErrorMessage(std::string message) = 0;

	/// <summary>
	/// shows error message
	/// </summary>
	/// <param name="message">error to display</param>
	virtual void showErrorMessage(std::string message) = 0;

	/// <summary>
	/// shows arena result
	/// </summary>
	/// <param name="player">player who took part in a battle</param>
	/// <param name="didWin">state did player win</param>
	virtual void showArenaResult(Player* player, bool didWin) = 0;

	/// <summary>
	/// show exception message
	/// </summary>
	/// <param name="message">exception message to dipslay</param>
	virtual void showExceptionMessage(std::string message) = 0;

	/// <summary>
	/// shows player introduction
	/// </summary>
	/// <param name="playerNumber">player number</param>
	virtual void showCreatePlayerIntroduction(int playerNumber) = 0;

	/// <summary>
	/// show players class selection
	/// </summary>
	/// <param name="playerNumber">player number</param>
	virtual void showCreatePlayerClassSelection(int playerNumber) = 0;

	/// <summary>
	/// shows available class list
	/// </summary>
	virtual void showClassList() = 0;

	/// <summary>
	/// creates an enter
	/// </summary>
	virtual void enter() = 0;

	/// <summary>
	/// waits for user action
	/// </summary>
	virtual void waitForContinue() = 0;

	/// <summary>
	/// show information message
	/// </summary>
	/// <param name="message">message to display</param>
	virtual void showInfoMessage(std::string message) = 0;

	/// <summary>
	/// shows turn info
	/// </summary>
	/// <param name="player">current player</param>
	/// <param name="currentTurn">current turn number</param>
	/// <param name="currentDay">current day number</param>
	virtual void showTurnInfo(Player* player, int currentTurn, int currentDay) = 0;

	/// <summary>
	/// shows turn menu
	/// </summary>
	/// <param name="isChallenged">is player challenged by another player</param>
	virtual void showTurnMenu(bool isChallenged) = 0;

	/// <summary>
	/// wipes
	/// </summary>
	virtual void wipe() = 0;

	/// <summary>
	/// shows quests menu
	/// </summary>
	virtual void showQuestsMenu() = 0;

	/// <summary>
	/// gets quest menu option
	/// </summary>
	/// <returns>quest menu option</returns>
	virtual int getQuestMenuOption() = 0;

	/// <summary>
	/// gets turn menu option
	/// </summary>
	/// <returns>turn menu option</returns>
	virtual int getTurnMenuOption() = 0;

	/// <summary>
	/// shows current quests
	/// </summary>
	/// <param name="currentQuests">list of quests</param>
	virtual void showCurrentQuests(std::vector<Quest*> currentQuests) = 0;

	/// <summary>
	/// shows current quest option
	/// </summary>
	/// <param name="currentQuests">option</param>
	/// <returns>chosen option</returns>
	virtual int getCurrentQuestOption(std::vector<Quest*> currentQuests) = 0;

	/// <summary>
	/// shows lost screen
	/// </summary>
	/// <param name="player">player who lost</param>
	virtual void showLostScreen(Player* player) = 0;

	/// <summary>
	/// gets player name
	/// </summary>
	/// <returns>player name</returns>
	virtual std::string getPlayerName() = 0;

	/// <summary>
	/// gets player class name
	/// </summary>
	/// <returns>player class name</returns>
	virtual ClassName getClassName() = 0;

	/// <summary>
	/// shows fight start info
	/// </summary>
	virtual void showFightStart() = 0;

	/// <summary>
	/// shows player details
	/// </summary>
	/// <param name="player">player</param>
	virtual void showPlayerDetails(Player* player) = 0;

	/// <summary>
	/// shows player equipment
	/// </summary>
	/// <param name="player">player</param>
	virtual void showPlayerEquipment(Player* player) = 0;

	/// <summary>
	/// show item info
	/// </summary>
	/// <param name="item">item</param>
	virtual void showItemInfo(Item item) = 0;

	/// <summary>
	/// shows shop menu
	/// </summary>
	virtual void showShopMenu() = 0;

	/// <summary>
	/// gets shop menu option
	/// </summary>
	/// <returns>chosen option</returns>
	virtual int getShopMenuOption() = 0;

	/// <summary>
	/// shows available items in shop
	/// </summary>
	/// <param name="player">player</param>
	/// <param name="items">available items</param>
	virtual void showAvailableItems(Player* player, std::vector<Item> items) = 0;

	/// <summary>
	/// gets current shop option
	/// </summary>
	/// <param name="items">available items</param>
	/// <returns>chosen item index</returns>
	virtual int getCurrentShopOption(std::vector<Item> items) = 0;

	/// <summary>
	/// shows item details
	/// </summary>
	/// <param name="items">available items</param>
	/// <param name="itemIndex">chosen item index</param>
	virtual void showItemDetails(std::vector<Item> items, int itemIndex) = 0;

	/// <summary>
	/// shows decision about buying
	/// </summary>
	/// <returns>decision if item should be bought</returns>
	virtual bool showBuyDecision() = 0;

	/// <summary>
	/// shows decision about dueling
	/// </summary>
	/// <param name="isAlreadyChallenged">is player already challenged</param>
	/// <returns>was duel performed</returns>
	virtual bool showDuelDecision(bool isAlreadyChallenged) = 0;

	/// <summary>
	/// shows the winner of the game
	/// </summary>
	/// <param name="player">winner</param>
	virtual void showWinner(Player* player) = 0;
};