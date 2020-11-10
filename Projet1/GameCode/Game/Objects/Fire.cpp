#include "Fire.h"

Fire::Fire(int hp, bool destroyable)
{
	this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Fire::verifyHp()
{
	if (hp <= 0 && destroyable)
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

