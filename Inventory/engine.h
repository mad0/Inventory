#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Player.h"

class Engine {

private:
	std::unique_ptr<UI> ui;
	std::unique_ptr<Player> player;
	sf::RenderWindow window;
public:
	Engine();
	~Engine();
	void loop();
	void update();
	void draw();
};
