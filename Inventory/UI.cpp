#include "UI.h"
#include <iostream>
#include <typeinfo>

UI::UI(sf::RenderWindow &_window) :window(_window)
{
	slotTexture = std::make_unique<sf::Texture>();
	slotTexture->loadFromFile("gfx/slot.png");
	slotsNumber = 10;
	showBag = false;

}

UI::~UI()
{
}

void UI::init()
{
	
}


void UI::ui_draw()
{
	//for (auto &l : bar_slots)
	//	window.draw(*l);
	//if (showBag) {
	//	for (auto &o : bag_slots)
	//		window.draw(*o);
	//}
}

void UI::showInv()
{
	if (showBag)
		showBag = false;
	else showBag = true;
}

sf::Vector2f UI::freeSlot()
{
	return sf::Vector2f();
}


void UI::update()
{

}
