#include "Bullet.h"

//Constructeurs/Destructeur
Bullet::Bullet(float posX, float posY, sf::Vector2f velocity, std::string spriteName, int hauteur, int largeur) : AnimateEntity(spriteName, hauteur, largeur)
{
	this->velocity.x = velocity.x;
	this->velocity.y = velocity.y;
	sprite.setPosition(posX, posY);
}

Bullet::~Bullet()
{

}

//Methodes
void Bullet::move()
{
	float x = sprite.getPosition().x + velocity.x;
	float y = sprite.getPosition().y + velocity.y;
	sprite.setPosition(x, y);
}
