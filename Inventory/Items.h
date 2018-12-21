#pragma once
#include <string>
#include <random>
#include <SFML/Graphics.hpp>

class Items
{
public:
	enum Types {
		WEAPON,
		ARMOR,
		FOOD,
		POTIONS
	};
	inline Types getType () { return itemType; }
	Items(Types _typ, int _id, const std::string _name);
	~Items();
	void useItem();
	void draw(sf::RenderWindow &_window);
	void setPosition(sf::Vector2f _pos);
	void setScale(float _x, float _y);
	inline int setStack() { return stack++; }
	inline int getStack() { return stack; }
	int getId();
protected:
	int id;
	std::string name;
	sf::Sprite icon;
	std::unique_ptr<sf::Texture> iconTexture;
	int stack = 0;
	Types itemType;
	std::mt19937 rnd;
	std::uniform_int_distribution<int> dist;
};

class Weapon : public Items 
{
private:
	int maxDmg;
	int minDmg;
public:
	Weapon(Types _typ, int _id, const std::string _name, int _maxDmg, int _minDmg);
	int Attack();
};

class Armor : public Items
{
private:
	int armorValue;
public:
	using Items::Items;
	Armor(Types _typ, int _id, const std::string _name, int _armorValue);
	int getArmor();
};

