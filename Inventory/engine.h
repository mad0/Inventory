#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Player.h"
#include "Items.h"

class Engine {

private:
	std::unique_ptr<UI> ui;
	std::unique_ptr<Player> player;
	sf::RenderWindow window;
	std::vector<Items*> itemsData;
	Items * takeItem(int _id);
public:
	Engine();
	~Engine();
	void loop();
	void update();
	void draw();
};
