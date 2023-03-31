#include "../../../HeaderFiles/Core/Quests/QuestBattle.h";

std::string QuestBattle::getEnemyName() {
	return this->enemyName;
}

bool QuestBattle::start(Player*& player, UI* ui) {
	Monster monster(this->enemyName, this->enemyHp, this->enemyMinDmg, this->enemyMaxDmg, this->enemyChanceForBlock);
	bool fightResult = Arena::fightAgainstMonster(player, monster, ui);

	if (fightResult) {
		ui->showInfoMessage("Mission completed!");
		ui->showInfoMessage("You received " + std::to_string(this->reward) + " gold and lost " + std::to_string(this->staminaCost) + " stamina points.");
		ui->waitForContinue();
		ui->wipe();
	}

	return fightResult;
}