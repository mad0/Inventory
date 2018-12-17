#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Items.h"

class Engine {
private:
	std::map<int, Items*> items;
	std::unique_ptr<UI> ui;
	sf::RenderWindow window;
	bool s_bag;
public:
	Engine();
	~Engine();
	void loop();
	void update();
	void draw();
};
