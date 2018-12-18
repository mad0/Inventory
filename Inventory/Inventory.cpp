#include "Inventory.h"
#include <iostream>


Inventory::Inventory(sf::RenderWindow &_window): window(_window) {
	slotTexture = std::make_unique<sf::Texture>();
	slotTexture->loadFromFile("gfx/slot.png");
}


Inventory::~Inventory()
{
}

void Inventory::init()
{
	for (int x = 0; x < 5; x++) {
		std::unique_ptr<sf::RectangleShape> tmpRect = std::make_unique <sf::RectangleShape>();
		tmpRect->setTexture(&(*slotTexture));
		tmpRect->setPosition(10, 50);
		//tmpRect->setPosition(100+(x*32), 350);
		bagSlots.emplace_back(std::move(tmpRect));
	}
	
}

void Inventory::drawSlots()
{
	//for (auto &o : bagSlots)
	//	window.draw(*o);
	window.draw(*bagSlots[0]);
	std::cout << bagSlots.size();
}

void Inventory::addItem()
{
	std::unique_ptr<Items> tmpItem = std::make_unique<Items>(1, "food1.png");
	items.emplace_back(std::move(tmpItem));
	std::cout << "Added new item. Items in bag: " << items.size() << "\n";
}
