#include "UI.h"
#include <iostream>
#include <typeinfo>

UI::UI(sf::RenderWindow &_window) :window(_window)
{
	slotTexture = std::make_unique<sf::Texture>();
	slotTexture->loadFromFile("gfx/slot.png");
}

UI::~UI()
{
}

void UI::init()
{
	for (int x = 0; x < 10; x++) {
		std::unique_ptr<sf::RectangleShape> uiSlot = std::make_unique<sf::RectangleShape>(sf::Vector2f(64, 64));
		uiSlot->setTexture(&(*slotTexture));
		uiSlot->setPosition(128 + (x * 66), 1016);
		bar.emplace_back(std::move(uiSlot));
	}
}

void UI::draw()
{
	for (auto &l : bar)
		window.draw(*l);
}

void UI::update()
{

}

sf::Vector2f UI::getSlot(int _slot)
{
	return bar.at(_slot)->getPosition();
}
