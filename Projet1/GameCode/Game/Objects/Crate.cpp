#include "Crate.h"

Crate::Crate(int hp, bool destroyable)
{
	this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Crate::verifyHp()
{
	if (hp <= 0 && destroyable)
	{
		crate.kill(crate);
	}
	return hp;
}

void Crate::checkCollision()
{
	if (crate.getCollision(crate))
	{
		verifyHp();
	}
}

