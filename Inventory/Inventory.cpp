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
}

void Inventory::init()
{
	for (int x = 0; x < 10; x++) {
		std::unique_ptr<sf::RectangleShape> tempRect = std::make_unique<sf::RectangleShape>(sf::Vector2f(32,32));
		tempRect->setTexture(&(*slotTexture));
		tempRect->setPosition(300 + (32 * x), 400);
		bagSlots.emplace_back(std::move(tempRect));	
	}
	std::cout << "Bag size: " << bagSlots.size() << "\n";
}

//tworze nowy item!!!
void Inventory::addItem(const std::string _name)
{
	
	//std::cout << "Items in inventoru: "<<Bag.size()<<"\n";
}

