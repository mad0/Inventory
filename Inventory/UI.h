#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UI
{
private:
	sf::RenderWindow &window;
	std::unique_ptr<sf::Texture> slotTexture;
	std::vector<std::unique_ptr<sf::RectangleShape>> bar;
public:
	void init();
	UI(sf::RenderWindow &_window);
	~UI();
	void draw();
	void update();
	sf::Vector2f getSlot(int _slot);
};

