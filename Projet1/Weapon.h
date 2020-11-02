#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <list>
#include "Bullet.h"


class Weapon : public sf::Sprite
{
	//Attributs
public:

private:
	std::list<Bullet*> listBullets;

	//Methodes
public:
	void updateBullets();
	void fire(float bulletVelocity);
private:
};

