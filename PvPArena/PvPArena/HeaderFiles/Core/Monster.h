#pragma one

#include <string>

class Monster {
private:
	std::string name;
	int hp;
	int minDmg;
	int maxDmg;
	int chanceForBlock;

public:
	Monster(std::string name, int hp, int minDmg, int maxDmg, int chanceForBlock) :
		name(name), hp(hp), minDmg(minDmg), maxDmg(maxDmg), chanceForBlock(chanceForBlock) {}

	~Monster() {}

	std::string getName();

	int getHP();

	void substractHp(int damage);

	int getAttackValue();

	bool isAttackBlocked();
};