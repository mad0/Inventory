#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Items.h"
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
	bool isVisible;
	//stworzone itemy dopiero zostana dodane to torby po lootedItem()
	std::unique_ptr<Inventory> bag;
public:
	Player(sf::RenderWindow &_window);
	~Player();
	void update();
	void draw();
	//tworzy item i dodaje do torby (kontener: items)
	void lootItem(Items *_item);
	//ponizej powinno byc jaka bron zaklada z torby(wskaznik)
	void equipWeapon(Slot _slot);
	void unequipeWeapon(Slot _slot);
	void showBag();
};

