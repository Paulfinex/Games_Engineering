#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
//...

using namespace sf;
using namespace std;
std::vector<Ship *> ships;
const Keyboard::Key controls[2] = {
	Keyboard::Left,   
	Keyboard::Right

};

sf::Texture spritesheet;
sf::Sprite invader;
const int gameWidth = 800;
const int gameHeight = 600;
void Load() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
	cerr << "Failed to load spritesheet!" << std::endl;
	}
	//invader.setTexture(spritesheet);
	Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), { 100,100 });
	ships.push_back(inv);
}


void Update(RenderWindow &window) {
	// Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	// check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}
	for (auto &s : ships) {
		s->Update(dt);
	};
}

void Render(RenderWindow &window) {
	// Draw Everything
   // window.draw(invader);
	for (const auto s : ships) {
		window.draw(*s);
	}
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}
