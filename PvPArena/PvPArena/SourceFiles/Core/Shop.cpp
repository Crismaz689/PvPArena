#include "../../HeaderFiles/Core/Shop.h";

std::vector<Item> Shop::getAvailableItems(Player* player) {
	std::vector<Item> availableItems;

	for (int i = 0; i < this->items.size(); ++i) {
		if (player->getClassName() == this->items[i].getClassName()) {
			availableItems.push_back(this->items[i]);
		}
	}

	return availableItems;
}

void Shop::removeItem(Item item) {
	for (int i = 0; i < this->items.size(); ++i) {
		if (item.getName() == this->items[i].getName()) {
			auto it = this->items.begin();

			std::advance(it, i);
			this->items.erase(it);

			return;
		}
	}
}