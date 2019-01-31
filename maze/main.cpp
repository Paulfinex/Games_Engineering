#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "entity.h"

//...

using namespace sf;
using namespace std;
constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
Player* player = new Player();
static Vector2f plPos;


void Load() {

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
	player->update(dt);

	
	//}
	//if (Keyboard::isKeyPressed(controls[1])) {
	//	player->direction = 1.0f;
	//}
	//if (Keyboard::isKeyPressed(controls[2])) {
	//	Bullet::Fire(player->getPosition(), false);
	//}

	//player->Update(dt);
	//player->direction = 0.0f;
	//for (auto &s : ships) {
	//	s->Update(dt);
	//};


}

void Render(RenderWindow &window) {
	// Draw Everything
   // window.draw(invader);
	player->render(window);
	//for (const auto s : ships) {
	//	window.draw(*s);
	//}

}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Maze");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}
