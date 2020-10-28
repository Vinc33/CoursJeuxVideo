#include "Weapon.h"

//Constructors/Destructor
Weapon::Weapon()
{

}

Weapon::Weapon()
{

}

//Methods
void Weapon::updateBullets()
{
	for (auto it = listBullets.begin(); it != listBullets.end(); ++it)
		(*it)->move();
}

void Weapon::fire(float velocity) 
{
	listBullets.push_back(new Bullet(getPosition().x, getPosition().y, velocity));
}


