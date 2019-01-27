//bullet.cpp
#include "bullet.h"
#include "spaceinv.h"
using namespace sf;
using namespace std;
bool _mode;
unsigned char bulletPointer;
Bullet bullets[256];
//Create definition for the constructor
//...

//bool _mode;

void Bullet::_Update(const float & dt)
{
}

Bullet::Bullet()
{
}
void Bullet::Update(const float &dt) {
	bullets[bulletPointer].move(0, dt * 200.0f * (bullets[bulletPointer]._mode ? 1.0f : -1.0f));
}

void Bullet::Render(sf::RenderWindow & window)
{
	bullets[bulletPointer].setTexture(spritesheet);
	bullets[bulletPointer].setTextureRect(IntRect(64, 32, 32, 32));
	window.draw(bullets[bulletPointer]);
}

void Bullet::Fire(const sf::Vector2f & pos, const bool mode)
{
	bullets[++bulletPointer].setOrigin(16, 16);
	bullets[bulletPointer].setPosition(pos);
}
