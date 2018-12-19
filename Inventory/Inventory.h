#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Items.h"

class Inventory
{
private:
	std::unique_ptr<sf::Texture> slotTexture;
	std::vector<std::unique_ptr<sf::RectangleShape>> bagSlots;
	std::vector<Items*> Bag;
public:
	Inventory();
	~Inventory();
	void drawBag(sf::RenderWindow &_window);
	void init();
	void addItem(const std::string &_name);
	void showBag();
	Items * getItem();
};

