#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Items
{
private:
	int id;
	std::string name;
	sf::Sprite icon;
	sf::Texture *iconTexture;
public:
	Items(int _id, const std::string _name);
	~Items();
	void draw(sf::RenderWindow &_window);
};

