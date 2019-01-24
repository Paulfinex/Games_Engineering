//bullet.cpp
#include "bullet.h"
#include "game.h"
using namespace sf;
using namespace std;
unsigned char bulletPointer;
Bullet bullets[256];
//Create definition for the constructor
//...

void Bullet::Update(const float &dt) {
	move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
}

void Bullet::Render(sf::RenderWindow & window)
{
	window.draw(bullets[bulletPointer]);
}

void Bullet::Fire(const sf::Vector2f & pos, const bool mode)
{
	bullets[++bulletPointer].setPosition(pos);
	bullets[bulletPointer]._mode = mode;
}

Bullet::Bullet(IntRect ir)
{
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
}


void Bullet::_Update(const float & dt)
{
}

Bullet::Bullet()
{
}
