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
    if (monster.isAttackBlocked()) {
        ui->showInfoMessage("Monster has blocked your attack!");
    }
    else {
        bool isAttackRepeated = false;
        bool isCriticalHit = player->isHitCritical();
        int playerAttackDamageValue = isCriticalHit ?
            player->calculateDamage() * 2 :
            player->calculateDamage();

        monster.substractHp(playerAttackDamageValue);

        ui->showInfoMessage(player->getName() + " attacks " + monster.getName() + " and deals " + std::to_string(playerAttackDamageValue) + " damage!");

        if (isCriticalHit) {
            ui->showInfoMessage("That was a critical hit!");
        }

        if (monster.getHP() <= 0) {
            ui->showInfoMessage(monster.getName() + " has died!");
        }
        else {
            ui->showInfoMessage(monster.getName() + " has " + std::to_string(monster.getHP()) + " HP");
        }

        if (player->getClassName() == ClassName::Archer && monster.getHP() <= 0) {
            player = dynamic_cast<Archer*>(player);

            isCriticalHit = player->isHitCritical();
            playerAttackDamageValue = isCriticalHit ?
                player->calculateDamage() * 2 :
                player->calculateDamage();
        }
        else if (player->getClassName() == ClassName::Sniper && monster.getHP() <= 0) {
            player = dynamic_cast<Sniper*>(player);

            isCriticalHit = player->isHitCritical();
            playerAttackDamageValue = isCriticalHit ?
                player->calculateDamage() * 2 :
                player->calculateDamage();
        }

        ui->showInfoMessage(player->getName() + " attacks second time " + monster.getName() + " and deals " + std::to_string(playerAttackDamageValue) + " damage!");

        if (isCriticalHit) {
            ui->showInfoMessage("That was a critical hit!");
        }

        if (monster.getHP() <= 0) {
            ui->showInfoMessage(monster.getName() + " has died!");
        }
        else {
            ui->showInfoMessage(monster.getName() + " has " + std::to_string(monster.getHP()) + " HP");
        }

    }
}

void Arena::attackPlayerByPlayer(Player*& playerA, Player*& playerB, UI* ui) {
}