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
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
				//sf::Texture potion;
				//potion.loadFromFile("gfx/potion1.png");
				//ui->getSlot(1)->setTexture(&potion);
				//player->showBag();
			}
		}
		this->update();
		this->draw();
	}
}

void Engine::update()
{

}

void Engine::draw()
{
	window.clear();
	//ui->draw();
	player->draw();
	window.display();
}
