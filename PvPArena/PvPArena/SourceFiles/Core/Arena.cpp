#include "../../HeaderFiles/Core/Arena.h";

bool Arena::fightAgainstMonster(Player*& player, Monster& monster, UI* ui) {
    ui->showFightStart();

    while (true) {
        ui->showInfoMessage("Now " + player->getName() + " attacks " + monster.getName() + "...");
        Arena::attackMonsterByPlayer(player, monster, ui);
        if (monster.getHP() <= 0) {
            ui->showArenaResult(player, true);
            ui->showInfoMessage("After fight " + player->getName() + "'s hp = " + std::to_string(player->getHp()));

            return true;
        }
        ui->waitForContinue();
        
        ui->showInfoMessage("Now " + monster.getName() + " attacks " + player->getName() + "...");
        Arena::attackPlayerByMonster(monster, player, ui);
        if (player->getHp() <= 0) {
            ui->showArenaResult(player, false);
            ui->showInfoMessage("After fight " + monster.getName() + "'s hp = " + std::to_string(monster.getHP()));

            return false;
        }
        ui->waitForContinue();
    }
}

bool Arena::fightPlayerAgainstPlayer(Player*& playerA, Player*& playerB, UI* ui) {
	return true;
}

void Arena::attackPlayerByMonster(Monster& monster, Player*& player, UI* ui) {

}

void Arena::attackMonsterByPlayer(Player*& player, Monster& monster, UI* ui) {

}

void Arena::attackPlayerByPlayer(Player*& playerA, Player*& playerB, UI* ui) {
}