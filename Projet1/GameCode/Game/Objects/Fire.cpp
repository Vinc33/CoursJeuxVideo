#include "Fire.h"

Fire::Fire(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->isDestroyable = destroyable;
	objectName = "Fire";
}

int Fire::verifyHp()
{
	return hp;
}


string Fire::iAm()
{
	return this->objectName;
}


