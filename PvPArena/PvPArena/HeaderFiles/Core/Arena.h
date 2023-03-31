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

class Arena {
private:
	Arena() {}

	static void attackPlayerByMonster(Monster& monster, Player*& player, UI* ui);

	static void attackMonsterByPlayer(Player*& player, Monster& monster, UI* ui);

	static void attackPlayerByPlayer(Player*& playerA, Player*& playerB, UI* ui);

public:
	~Arena() {}

	static bool fightAgainstMonster(Player*& player, Monster& monster, UI* ui);

	static bool fightPlayerAgainstPlayer(Player*& playerA, Player*& playerB, UI* ui);
};