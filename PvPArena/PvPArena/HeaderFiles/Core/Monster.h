#pragma one

#include <string>

/// <summary>
/// representation of a monster
/// </summary>
class Monster {
private:
	std::string name;
	int hp;
	int minDmg;
	int maxDmg;
	int chanceForBlock;

public:
	/// <summary>
	/// constructor
	/// </summary>
	Monster(std::string name, int hp, int minDmg, int maxDmg, int chanceForBlock) :
		name(name), hp(hp), minDmg(minDmg), maxDmg(maxDmg), chanceForBlock(chanceForBlock) {}

	/// <summary>
	/// destructor
	/// </summary>
	~Monster() {}

	/// <summary>
	/// gets a name
	/// </summary>
	/// <returns>monsters name</returns>
	std::string getName();

	/// <summary>
	/// gets a hp
	/// </summary>
	/// <returns>monsters hp</returns>
	int getHP();

	/// <summary>
	/// substracts hp
	/// </summary>
	void substractHp(int damage);

	/// <summary>
	/// gets attack value
	/// </summary>
	/// <returns>monsters attack value</returns>
	int getAttackValue();

	/// <summary>
	/// gets block value
	/// </summary>
	/// <returns>monsters block attack info</returns>
	bool isAttackBlocked();
};