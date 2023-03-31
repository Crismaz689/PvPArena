#include "../../HeaderFiles/Core/Arena.h";

bool Arena::fightAgainstMonster(Player*& player, Monster& monster, UI* ui) {
    ui->showFightStart();

    while (true) {
        ui->showInfoMessage("Now " + player->getName() + " attacks " + monster.getName() + "...");
        Arena::attackMonsterByPlayer(player, monster, ui);
        if (monster.getHP() <= 0) {
            ui->showArenaResult(player, true);
            ui->showInfoMessage("After fight " + player->getName() + "'s hp = " + std::to_string(player->getHp()));
            ui->enter();

            return true;
        }
        ui->waitForContinue();
        ui->enter();
        
        ui->showInfoMessage("Now " + monster.getName() + " attacks " + player->getName() + "...");
        Arena::attackPlayerByMonster(monster, player, ui);
        if (player->getHp() <= 0) {
            ui->showArenaResult(player, false);
            ui->showInfoMessage("After fight " + monster.getName() + "'s hp = " + std::to_string(monster.getHP()));
            ui->enter();

            return false;
        }
        ui->waitForContinue();
        ui->enter();
    }
}

bool Arena::fightPlayerAgainstPlayer(Player*& playerA, Player*& playerB, UI* ui) {
	return true;
}

void Arena::attackPlayerByMonster(Monster& monster, Player*& player, UI* ui) {
    bool isHitBlocked = false;
    ClassName playerClassName = player->getClassName();

    switch (playerClassName) {
        case ClassName::Archer: {
                auto playerAsArcher = dynamic_cast<Archer*>(player);
                isHitBlocked = playerAsArcher->calculateDodgeChance();
            }
            break;
        case ClassName::Sniper: {
                auto playerAsSniper = dynamic_cast<Sniper*>(player);
                isHitBlocked = playerAsSniper->calculateDodgeChance();
            }
            break;
        case ClassName::Mage:
            isHitBlocked = false; // Mages cannot dodge physically attack
            break;
        case ClassName::Warrior: {
                auto playerAsWarrior = dynamic_cast<Warrior*>(player);
                isHitBlocked = playerAsWarrior->calculateBlockChance();
            }
            break;
        case ClassName::Berserker: {
                auto playerAsBerserker = dynamic_cast<Berserker*>(player);
                isHitBlocked = playerAsBerserker->calculateBlockChance();
            }
            break;
        case ClassName::Paladin: {
                auto playerAsPaladin = dynamic_cast<Paladin*>(player);
                isHitBlocked = playerAsPaladin->calculateBlockChance();
            }
            break;
    }

    if (isHitBlocked) {
        switch (playerClassName) {
            case ClassName::Archer:
            case ClassName::Sniper:
                ui->showInfoMessage(player->getName() + " has dodged the attack!");
                break;
            case ClassName::Mage: // impossible to get there
                break;
            case ClassName::Warrior:
            case ClassName::Berserker:
            case ClassName::Paladin:
                ui->showInfoMessage(player->getName() + " has blocked the attack!");
                break;
        }
    }
    else {
        int monsterAttackDamage = monster.getAttackValue();

        player->substractHp(monsterAttackDamage);
        ui->showInfoMessage(monster.getName() + " attacks " + player->getName() + " and deals " + std::to_string(monsterAttackDamage) + " damage!");
        if (player->getHp() <= 0) {
            ui->showInfoMessage(player->getName() + " has died!");
        }
        else {
            ui->showInfoMessage(player->getName() + " has " + std::to_string(player->getHp()) + " HP");
        }
    }
}

void Arena::attackMonsterByPlayer(Player*& player, Monster& monster, UI* ui) {
    if (monster.isAttackBlocked()) {
        ui->showInfoMessage("Monster has blocked your attack!");
    }
    else {
        bool isAttackRepeated = false;
        bool isCriticalHit = player->isHitCritical();
        ClassName playerClassName = player->getClassName();

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

        if (playerClassName == ClassName::Archer || playerClassName == ClassName::Sniper) {
            if (playerClassName == ClassName::Archer && monster.getHP() <= 0) {
                player = dynamic_cast<Archer*>(player);

                isCriticalHit = player->isHitCritical();
                playerAttackDamageValue = isCriticalHit ?
                    player->calculateDamage() * 2 :
                    player->calculateDamage();
            }
            else if (playerClassName == ClassName::Sniper && monster.getHP() <= 0) {
                player = dynamic_cast<Sniper*>(player);

                isCriticalHit = player->isHitCritical();
                playerAttackDamageValue = isCriticalHit ?
                    player->calculateDamage() * 2 :
                    player->calculateDamage();
            }

            monster.substractHp(playerAttackDamageValue);

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
}

void Arena::attackPlayerByPlayer(Player*& playerA, Player*& playerB, UI* ui) {
}