#pragma once
#include "Items.h"

class Inventory
{
private:
	sf::RenderWindow &window;
	std::vector<std::unique_ptr<sf::RectangleShape>> bagSlots;
	std::vector < std::unique_ptr<Items>> items;
	std::unique_ptr<sf::Texture> slotTexture;
public:
	Inventory(sf::RenderWindow &_window);
	~Inventory();
	void init();
	void drawSlots();
	void addItem();
};

