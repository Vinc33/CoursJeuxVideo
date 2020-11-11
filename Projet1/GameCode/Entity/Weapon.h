#pragma once
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
	Weapon(string weaponSprite, int weaponHauteur, int weaponLargeur, string bulletSprite, int bulletHauteur, int bulletLargeur);
	~Weapon();
	void fire(float bulletVelocity);
	void render(sf::RenderTarget& target) override;
private:
	void updateBullets();
};

