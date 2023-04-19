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
    ui->showFightStart();

    while (true) {
        ui->showInfoMessage("Now " + playerA->getName() + " attacks " + playerB->getName() + "...");
        Arena::attackPlayerByPlayer(playerA, playerB, ui);
        if (playerB->getHp() <= 0) {
            ui->showArenaResult(playerA, true);
            ui->showInfoMessage("After fight " + playerA->getName() + "'s hp = " + std::to_string(playerA->getHp()));
            ui->enter();

            return true;
        }
        ui->waitForContinue();
        ui->enter();

        ui->showInfoMessage("Now " + playerB->getName() + " attacks " + playerB->getName() + "...");
        Arena::attackPlayerByPlayer(playerB, playerA, ui);
        if (playerA->getHp() <= 0) {
            ui->showArenaResult(playerB, false);
            ui->showInfoMessage("After fight " + playerB->getName() + "'s hp = " + std::to_string(playerB->getHp()));
            ui->enter();

            return false;
        }
        ui->waitForContinue();
        ui->enter();
    }
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
    if (Arena::isAttackBlockedByPlayer(playerA, playerB, ui))
        return;

    bool isAttackRepeated = false;
    bool isCriticalHit = playerA->isHitCritical();
    ClassName playerClassName = playerA->getClassName();

    int playerAttackDamageValue = isCriticalHit ?
        playerA->calculateDamage() * 2 :
        playerA->calculateDamage();

    playerB->substractHp(playerAttackDamageValue);

    ui->showInfoMessage(playerA->getName() + " attacks " + playerB->getName() + " and deals " + std::to_string(playerAttackDamageValue) + " damage!");

    if (isCriticalHit) {
        ui->showInfoMessage("That was a critical hit!");
    }

    if (playerB->getHp() <= 0) {
        ui->showInfoMessage(playerB->getName() + " has died!");
    }
    else {
        ui->showInfoMessage(playerB->getName() + " has " + std::to_string(playerB->getHp()) + " HP");
    }

    if (playerClassName == ClassName::Archer || playerClassName == ClassName::Sniper) {
        if (playerClassName == ClassName::Archer && playerB->getHp() <= 0) {
            auto playerAsArcher = dynamic_cast<Archer*>(playerA);

            isCriticalHit = playerAsArcher->isHitCritical();
            playerAttackDamageValue = isCriticalHit ?
                playerAsArcher->calculateDamage() * 2 :
                playerAsArcher->calculateDamage();
        }
        else if (playerClassName == ClassName::Sniper && playerB->getHp() <= 0) {
            auto playerAsSniper = dynamic_cast<Sniper*>(playerA);

            isCriticalHit = playerAsSniper->isHitCritical();
            playerAttackDamageValue = isCriticalHit ?
                playerAsSniper->calculateDamage() * 2 :
                playerAsSniper->calculateDamage();
        }

        playerB->substractHp(playerAttackDamageValue);

        ui->showInfoMessage(playerA->getName() + " attacks second time " + playerB->getName() + " and deals " + std::to_string(playerAttackDamageValue) + " damage!");

        if (isCriticalHit) {
            ui->showInfoMessage("That was a critical hit!");
        }

        if (playerB->getHp() <= 0) {
            ui->showInfoMessage(playerB->getName() + " has died!");
        }
        else {
            ui->showInfoMessage(playerB->getName() + " has " + std::to_string(playerB->getHp()) + " HP");
        }
    }
}

bool Arena::isAttackBlockedByPlayer(Player* playerA, Player* playerB, UI* ui) {
    bool isHitBlocked = false;

    switch (playerB->getClassName()) {
        case ClassName::Warrior: {
            if (playerA->getClassName() == ClassName::Mage)
                break;

            auto playerAsWarrior = dynamic_cast<Warrior*>(playerB);
            isHitBlocked = playerAsWarrior->calculateBlockChance();

            if (isHitBlocked) {
                ui->showInfoMessage(playerB->getName() + " has blocked your attack!");
                return true;
            }

            break;
        }
        case ClassName::Berserker: {
            if (playerA->getClassName() == ClassName::Mage)
                break;

            auto playerAsBerserker = dynamic_cast<Berserker*>(playerB);
            isHitBlocked = playerAsBerserker->calculateBlockChance();

            if (isHitBlocked) {
                ui->showInfoMessage(playerB->getName() + " has blocked your attack!");
                return true;
            }

            break;
        }
        case ClassName::Paladin: {
            if (playerA->getClassName() == ClassName::Mage)
                break;

            auto playerAsPaladin = dynamic_cast<Paladin*>(playerB);
            isHitBlocked = playerAsPaladin->calculateBlockChance();

            if (isHitBlocked) {
                ui->showInfoMessage(playerB->getName() + " has blocked your attack!");
                return true;
            }

            break;
        }
        case ClassName::Archer: {
            if (playerA->getClassName() == ClassName::Mage)
                break;

            auto playerAsArcher = dynamic_cast<Archer*>(playerB);
            isHitBlocked = playerAsArcher->calculateDodgeChance();

            if (isHitBlocked) {
                ui->showInfoMessage(playerB->getName() + " has dodged your attack!");
                return true;
            }

            break;
        }
        case ClassName::Sniper: {
            if (playerA->getClassName() == ClassName::Mage)
                break;

            auto playerAsSniper = dynamic_cast<Sniper*>(playerB);
            isHitBlocked = playerAsSniper->calculateDodgeChance();

            if (isHitBlocked) {
                ui->showInfoMessage(playerB->getName() + " has dodged your attack!");
                return true;
            }

            break;
        }
        case ClassName::Mage: {
            if (playerA->getClassName() == ClassName::Mage) {
                auto playerAsMage = dynamic_cast<Mage*>(playerB);
                isHitBlocked = playerAsMage->getMagicDefense();

                if (isHitBlocked) {
                    ui->showInfoMessage(playerB->getName() + " has blocked your your attack using magic defense!");
                    return true;
                }
            }

            break;
        }
    }

    return false;
}