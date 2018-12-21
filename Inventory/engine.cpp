#include "engine.h"

Items * Engine::takeItem(int _id)
{
	for (auto &o : itemsData) {
		if (o->getId() == _id) {
			//std::cout << &o;
			return o;
		}
	}	
}

Engine::Engine()
{
	itemsData.emplace_back(new Weapon(Items::WEAPON, 45, "Weap1.png", 10, 15));
	itemsData.emplace_back(new Armor(Items::ARMOR, 22, "Helmet.png", 100));
	std::cout<<itemsData.at(0);
	std::cout<<itemsData.at(1);
	window.create(sf::VideoMode(1280, 720), "Gra");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	ui = std::make_unique<UI>(window);
	ui->init();
	player = std::make_unique<Player>(window);
}

Engine::~Engine()
{
}

void Engine::loop()
{
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			//zaklada bron z ekwipunku na lewa reke (tu p owinno byc JAKA BRON)
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
				//player->equipWeapon(Slot::leftHand);
				//items[0]->setPosition(ui->getSlot(0));
			}
			//lootuje item do torby
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L) {
				player->lootItem(takeItem(45));
			}
			//wyswietla zawartosc torby
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
				player->showBag();
			}
		}
		this->update();
		this->draw();
	}
}

void Engine::update()
{
	player->update();
}

void Engine::draw()
{
	window.clear();
	ui->draw();
	player->draw();
	window.display();
}
