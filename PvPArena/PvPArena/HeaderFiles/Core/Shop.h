#pragma once

#include <vector>

#include "Item.h";
#include "./Player/Player.h";

/// <summary>
/// handles shop
/// </summary>
class Shop {
private:
	std::vector<Item> items;

public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="items">available items</param>
	Shop(std::vector<Item> items) : items(items) {}

	/// <summary>
	/// destructor
	/// </summary>
	~Shop() { this->items.clear(); }

	/// <summary>
	/// gets available items
	/// </summary>
	/// <returns>available items</returns>
	std::vector<Item> getAvailableItems(Player* player);

	/// <summary>
	/// removes item from the shop
	/// </summary>
	void removeItem(Item item);
};