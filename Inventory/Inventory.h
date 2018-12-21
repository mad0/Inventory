#pragma once
#include <SFML/Graphics.hpp>

class Items;

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
	void addItem(Items * _item);
};

