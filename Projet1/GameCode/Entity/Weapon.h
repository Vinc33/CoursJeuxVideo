#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "AnimateEntity.h"
#include <list>
#include "Bullet.h"


class Weapon : public AnimateEntity
{
	//Attributs
public:

private:
	std::list<Bullet*> listBullets;
	string bulletSprite;
	int bulletLargeur;
	int bulletHauteur;

	//Methodes
public:
	Weapon(string weaponSprite, string bulletSprite);
	~Weapon();
	void fire(sf::Vector2f bulletVelocity);
	void render(sf::RenderTarget& target) override;
private:
	void updateBullets();
};

