#include "Weapon.h"
#include <string>

//Constructors/Destructor
Weapon::Weapon(string weaponSprite, int weaponHauteur, int weaponLargeur, string bulletSprite, int bulletHauteur, int bulletLargeur) : AnimateEntity(weaponSprite,weaponHauteur, weaponLargeur)
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
	for (auto it = listBullets.begin(); it != listBullets.end(); ++it)
	{
		(*it)->move();
		//supprime les balles qui sont hors map
		/*if ((*it)->getSprite()->getPosition().x < 10 || (*it)->getSprite()->getPosition().x > 600 || (*it)->getSprite()->getPosition().y < 10 || (*it)->getSprite()->getPosition().y > 600)
		{
			delete (*it);
			listBullets.remove(*it);
		}*/
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
