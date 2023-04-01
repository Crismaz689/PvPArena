#pragma once

#include <vector>

#include "Item.h";
#include "./Player/Player.h";

class Shop {
private:
	std::vector<Item> items;

public:
	Shop(std::vector<Item> items) : items(items) {}

	~Shop() { this->items.clear(); }

	std::vector<Item> getAvailableItems(Player* player);

	void removeItem(Item item);
};