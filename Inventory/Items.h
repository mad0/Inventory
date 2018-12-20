#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Items
{
private:
	int id;
	std::string name;
	sf::Sprite icon;
	std::unique_ptr<sf::Texture> iconTexture;
	int stack = 0;
public:
	Items(int _id, const std::string _name);
	~Items();
	virtual void draw(sf::RenderWindow &_window) = 0;
	virtual void setPosition(sf::Vector2f _pos) = 0;
	virtual void setScale(float _x, float _y) = 0;
	virtual void setStack() = 0;
	virtual void getStack() = 0;
};

class Weapon : Items 
{

};

