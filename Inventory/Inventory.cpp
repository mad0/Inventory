#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {
	slotTexture = std::make_unique<sf::Texture>();
	slotTexture->loadFromFile("gfx/slot.png");
}


Inventory::~Inventory()
{
}

void Inventory::drawBag(sf::RenderWindow & _window)
{
	for (auto &b : bagSlots) {
		_window.draw(*b);
	}
	for (auto &i : Bag)
		i->draw(_window);
}

void Inventory::init()
{
	//BAG SLOTS
	for (int x = 0; x < 10; x++) {
		std::unique_ptr<sf::RectangleShape> tempRect = std::make_unique<sf::RectangleShape>(sf::Vector2f(64,64));
		tempRect->setTexture(&(*slotTexture));
		tempRect->setPosition(300 + (64 * x), 400);
		bagSlots.emplace_back(std::move(tempRect));	
	}
	std::cout << "Bag size: " << bagSlots.size() << "\n";
}


void Inventory::addItem(const std::string&_name)
{
	std::unique_ptr<Items> tempItem = std::make_unique<Items>(1, _name);
	tempItem->setPosition(bagSlots[0]->getPosition());
	tempItem->setScale(0.5, 0.5);
	Bag.emplace_back(std::move(tempItem));
	std::cout << "Items in inventoru: "<<Bag.size()<<"\n";
}


