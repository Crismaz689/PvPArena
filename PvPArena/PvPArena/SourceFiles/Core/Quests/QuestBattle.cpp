#include "../../../HeaderFiles/Core/Quests/QuestBattle.h";

std::string QuestBattle::getEnemyName() {
	return this->enemyName;
}

bool QuestBattle::start(Player*& player, UI* ui) {
	Monster monster(this->enemyName, this->enemyHp, this->enemyMinDmg, this->enemyMaxDmg, this->enemyChanceForBlock);

	return Arena::fightAgainstMonster(player, monster, ui);
}