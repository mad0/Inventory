#pragma once
#include "Items.h"

class Inventory
{
private:
	std::vector < std::unique_ptr<Items>> bag;
public:
	Inventory();
	~Inventory();
	void init();
	void addItem();
	void delitem();
	void showInventory();
};

