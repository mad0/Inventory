#include "Inventory.h"
#include <iostream>


Inventory::Inventory() {
}


Inventory::~Inventory()
{
}

void Inventory::init()
{
	
}

void Inventory::addItem()
{
	std::unique_ptr<Items> tmpItem = std::make_unique<Items>(1, "food1.png");
	tmpItem->setPosition();
	bag.emplace_back(std::move(tmpItem));
	std::cout << "Added new item. Items in bag: " << bag.size() << "\n";
}

void Inventory::delitem()
{
}

void Inventory::showInventory()
{

}
