#include "engine.h"

Engine::Engine() 
{
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
				player->lootItem("weap1.png");
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
