#include "Items.h"



Items::Items(int _id, const std::string _name) {
	iconTexture = std::make_unique<sf::Texture>();
	iconTexture->loadFromFile("gfx/"+_name);
	icon.setTexture(*iconTexture);
	icon.setScale(0.5, 0.5);
}


Items::~Items()
{
}

void Items::draw(sf::RenderWindow &_window)
{
	_window.draw(icon);
}

void Items::setPosition(sf::Vector2f _pos)
{
	icon.setPosition(_pos);
}
