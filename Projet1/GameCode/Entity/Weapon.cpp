#include "Weapon.h"
#include <string>

//Constructors/Destructor
Weapon::Weapon(string weaponSprite, string bulletSprite) : AnimateEntity(weaponSprite)
{
	this->bulletHauteur = bulletHauteur;
	this->bulletLargeur = bulletHauteur;
	this->bulletSprite = bulletSprite;
}

Weapon::~Weapon()
{

}

//Methods
void Weapon::updateBullets()
{
	auto it = listBullets.begin();
	while (it != listBullets.end())
		if ((*it)->getSprite()->getPosition().x < 0 || (*it)->getSprite()->getPosition().x > 1280 || (*it)->getSprite()->getPosition().y < 0 || (*it)->getSprite()->getPosition().y > 1024)
			listBullets.erase(it++);
		else
		{
			(*it)->move();
			++it;
		}
}

void Weapon::fire(sf::Vector2f velocity) 
{
	listBullets.push_back(new Bullet(sprite.getPosition().x, sprite.getPosition().y, velocity,bulletSprite,bulletHauteur,bulletLargeur));
}

void Weapon::render(sf::RenderTarget& target)
{
	updateBullets();
	for(auto it = listBullets.begin(); it != listBullets.end(); ++it)
		(*it)->render(target);
	target.draw(sprite);
}
