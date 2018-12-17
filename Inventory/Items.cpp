#include "Items.h"



Items::Items(int _id, const std::string _name) {
	iconTexture->loadFromFile("gfx"+_name);
	icon.setTexture(*iconTexture);
}


Items::~Items()
{
}

void Items::draw(sf::RenderWindow &_window)
{
	_window.draw(icon);
}