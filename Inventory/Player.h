#pragma once
#include "Inventory.h"

class Player
{
private: 
	sf::RenderWindow &window;
	std::unique_ptr<Inventory> playerBag;
	bool isVisible;
public:
	Player(sf::RenderWindow &_window);
	~Player();
	void update();
	void draw();
	void showBag();
};

