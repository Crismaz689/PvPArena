#pragma once

#include "../Core/Player/Archer.h";
#include "../Core/Player/Sniper.h";
#include "../Core/Player/Berserker.h";
#include "../Core/Player/Warrior.h";
#include "../Core/Player/Mage.h";
#include "../Core/Player/Paladin.h";
#include "../UI/UI.h";
#include "Player/Player.h";
#include "Monster.h";

/// <summary>
/// class responsible for player and monsters dueling
/// </summary>
class Arena {
private:
	Arena() {}

	static void attackPlayerByMonster(Monster& monster, Player*& player, UI* ui);

	static void attackMonsterByPlayer(Player*& player, Monster& monster, UI* ui);

	static void attackPlayerByPlayer(Player*& playerA, Player*& playerB, UI* ui);

	static bool isAttackBlockedByPlayer(Player* playerA, Player* playerB, UI* ui);

public:
	/// <summary>
	/// destructor
	/// </summary>
	~Arena() {}

	/// <summary>
	/// starts the fight against a monster
	/// </summary>
	/// <param name="monster">monster to duel</param>
	/// <param name="player">dueled player</param>
	/// <param name="ui">user interface</param>
	static bool fightAgainstMonster(Player*& player, Monster& monster, UI* ui);

	/// <summary>
	/// starts the fight between the players
	/// </summary>
	/// <param name="playerA">first player</param>
	/// <param name="playerB">second player</param>
	/// <param name="ui">user interface</param>
	static bool fightPlayerAgainstPlayer(Player*& playerA, Player*& playerB, UI* ui);
};