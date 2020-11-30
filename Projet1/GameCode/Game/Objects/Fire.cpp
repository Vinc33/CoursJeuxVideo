#include "Fire.h"

Fire::Fire(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png", "fire", 100, 10, false)
{

}

int Fire::verifyHp()
{
	if (this->hp <= 0 && this->isDestroyable)
	{
		fire.kill(fire);
	}
	return hp;
}

void Fire::checkCollision()
{
	if (fire.getCollision(fire))
	{
		verifyHp();
	}
}

string Fire::iAm()
{
	return this->objectName;
}


