#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Inventory.h"

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
	//stworzone itemy dopiero zostana dodane to torby po lootedItem()
	std::vector<Items*> bag;
public:
	Player(sf::RenderWindow &_window);
	~Player();
	void update();
	void draw();
	//tworzy item i dodaje do torby (kontener: items)
	void lootItem(const std::string &_name);
	//ponizej powinno byc jaka bron zaklada z torby(wskaznik)
	void equipWeapon(Slot _slot);
	void unequipeWeapon(Slot _slot);
};

