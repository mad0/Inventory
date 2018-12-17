#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UI
{
private:
	sf::RenderWindow &window;
	std::vector<std::unique_ptr<sf::RectangleShape>> ui_slots;
	std::vector<std::unique_ptr<sf::RectangleShape>> bag_slots;
	sf::Texture *slotTexture;
public:
	void init();
	UI(sf::RenderWindow &_window);
	~UI();
	void drawUI();
	void drawBag();
};

