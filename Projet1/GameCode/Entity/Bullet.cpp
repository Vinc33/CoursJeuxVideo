#include "Bullet.h"

//Constructeurs/Destructeur
Bullet::Bullet(float posX, float posY,float velocity)
{
	this->velocity.x = velocity;
	this->velocity.y = velocity;
	setPosition(posX, posY);
}

Bullet::~Bullet()
{

}

//Methodes
void Bullet::move()
{
	float x = getPosition().x + velocity.x;
	float y = getPosition().y + velocity.y;
	setPosition(x, y);
}
