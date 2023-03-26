#include "../../../HeaderFiles/Core/Quests/QuestHelp.h";

int QuestHelp::getIdleTime() {
	return this->idleTimeInSeconds;
}

bool QuestHelp::start(Player*& player, UI* ui) {
	int remainingTime = this->idleTimeInSeconds;

	do {
		ui->showInfoMessage(player->getName() + " is doing the mission \"" + this->description + "\" is in progress, remaining time: " + std::to_string(remainingTime) + " seconds.");
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		remainingTime--;
	} while (remainingTime != 0);

	ui->showInfoMessage("Mission completed!");
	ui->showInfoMessage("You received " + std::to_string(this->reward) + " gold and lost " + std::to_string(this->staminaCost) + " stamina points.");
	ui->waitForContinue();
	ui->wipe();

	return true;
}