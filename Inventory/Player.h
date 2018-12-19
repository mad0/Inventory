#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Inventory.h"

class Items;

enum Slot {
	leftHand,
	rightHand
};

class Player
{
private: 
	sf::RenderWindow &window;
	int hp;
	std::string name;
	Items *leftHand;
	Items *rightHand;
	Inventory *inventory;

	
public:
	Player(sf::RenderWindow &_window);
	~Player();
	void update();
	void draw();
	void lootItem(Items *_item);
	//ponizej powinno byc jaka bron zaklada z torby(wskaznik)
	void equipWeapon(Slot _slot);
	void unequipeWeapon(Slot _slot);
};

