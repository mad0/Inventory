#include "UI.h"
#include <iostream>

UI::UI(sf::RenderWindow &_window) :window(_window)
{
	slotTexture = new sf::Texture;
	slotTexture->loadFromFile("gfx/slot.png");
}

UI::~UI()
{
	delete slotTexture;
}

void UI::init()
{
	/*********         SLOTS           ****/
	for (int x = 0; x < 10; x++) {
		std::unique_ptr<sf::RectangleShape> uiSlot = std::make_unique<sf::RectangleShape>(sf::Vector2f(64, 64));
		uiSlot->setTexture(slotTexture);
		uiSlot->setPosition(128+(x*66), 656);
		ui_slots.emplace_back(std::move(uiSlot));
	}
	
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 2; y++) {
			std::unique_ptr<sf::RectangleShape> bagSlot = std::make_unique<sf::RectangleShape>(sf::Vector2f(32, 32));
			bagSlot->setTexture(slotTexture);
			bagSlot->setPosition(sf::Vector2f(400 + (x * 32), 100 + (y * 32)));
			bag_slots.emplace_back(std::move(bagSlot));
		}
		
	}
}


void UI::drawUI()
{
	for (auto &l : ui_slots)
		window.draw(*l);
	
}

void UI::drawBag()
{
	for (auto &o : bag_slots)
		window.draw(*o);
}
