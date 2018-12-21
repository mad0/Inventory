#include "Items.h"

Items::Items(Types _typ, int _id, const std::string _name) : itemType(_typ), id(_id), name(_name) {
	iconTexture = std::make_unique<sf::Texture>();
	iconTexture->loadFromFile("gfx/"+_name);
	icon.setTexture(*iconTexture);
	//random
	rnd = std::mt19937(time(0));
}


Items::~Items()
{
}

void Items::useItem()
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

void Items::setScale(float _x, float _y)
{
	icon.setScale(_x, _y);
}
int Items::getId()
{
	return id;
}
//WEAPON CLASS
Weapon::Weapon(Types _typ, int _id, const std::string _name, int _maxDmg, int _minDmg) : Items(_typ, _id, _name), maxDmg(_maxDmg), minDmg(_minDmg)
{
}
/////////////////// CHILDS //////////////////////////
int Weapon::Attack()
{
	std::uniform_int_distribution<int>(minDmg, maxDmg);
	return dist(rnd);
}
//ARMOR CLASS
Armor::Armor(Types _typ, int _id, const std::string _name, int _armorValue) : Items(_typ, _id, _name), armorValue(_armorValue)
{
}

int Armor::getArmor()
{
	return armorValue;
}
