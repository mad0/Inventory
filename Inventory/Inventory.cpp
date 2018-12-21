#include "Inventory.h"
#include <iostream>
#include <typeinfo>
#include "Items.h"

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


void Inventory::addItem(Items * _item)
{
	std::cout << &_item;
	//if (_item->getType() == Items::WEAPON) {
		_item->setPosition(bagSlots[Bag.size()]->getPosition());
		_item->setScale(0.5, 0.5);
		Bag.push_back(_item);
	//}

	std::cout << "Items in inventoru: " << Bag.size() << "\n";
	//if (Bag[0]->getType() == Weapon::Sword)
	//std::cout << "ATTACK: " << dynamic_cast<Weapon*>(Bag[0].get())->Attack() << "\n";
}


