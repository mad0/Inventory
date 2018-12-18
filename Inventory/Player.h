#pragma once
#include "UI.h"
#include "Inventory.h"

class Player
{
private: 
	sf::RenderWindow &window;
	std::unique_ptr<UI> ui;
	std::unique_ptr<Inventory> playerBag;
public:
	Player(sf::RenderWindow &_window);
	~Player();
	void update();
	void draw();
	void showBag();
};

