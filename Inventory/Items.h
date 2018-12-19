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
public:
	Items(int _id, const std::string _name);
	~Items();
	void draw(sf::RenderWindow &_window);
	void setPosition(sf::Vector2f _pos);
};

