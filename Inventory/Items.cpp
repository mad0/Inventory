#include "Items.h"



Items::Items(int _id, const std::string _name) {
	iconTexture = std::make_unique<sf::Texture>();
	iconTexture->loadFromFile("gfx/"+_name);
	icon.setTexture(*iconTexture);
}


Items::~Items()
{
}

void Items::setPosition()
{
	icon.setPosition(0,0);
}

void Items::draw(sf::RenderWindow &_window)
{
	_window.draw(icon);
}
