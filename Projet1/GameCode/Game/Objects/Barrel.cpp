#include "Barrel.h"

Barrel::Barrel(int hp, bool destroyable)
{
	this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Barrel::verifyHp()
{
	if (hp <= 0 && destroyable)
	{
		barrel.kill(barrel);
	}
	return hp;
}

void Barrel::checkCollision()
{
	if (barrel.getCollision(barrel))
	{
		verifyHp();
	}
}

