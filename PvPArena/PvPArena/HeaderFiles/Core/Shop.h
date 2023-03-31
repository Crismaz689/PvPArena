#pragma once

#include <vector>

#include "Item.h";

class Shop {
private:
	std::vector<Item> availableItems;

public:
	Shop(std::vector<Item> items) : availableItems(items) {}

	~Shop() { this->availableItems.clear(); }

	std::vector<Item> getItems();
};