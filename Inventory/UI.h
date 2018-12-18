#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UI
{
private:
	sf::RenderWindow &window;
	std::unique_ptr<sf::Texture> slotTexture;
	int slotsNumber;
	bool showBag;
public:
	void init();
	UI(sf::RenderWindow &_window);
	~UI();
	void ui_draw();
	void update();
	void showInv();
	sf::Vector2f freeSlot();
};

