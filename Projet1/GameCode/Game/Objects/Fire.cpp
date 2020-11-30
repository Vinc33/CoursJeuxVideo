#include "Fire.h"


Fire::Fire(int hp, int damage, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->damage = damage;
	this->isDestroyable = destroyable;
	objectName = "Fire";
	//ne pas oublier de setter le box du collision
}

int Fire::verifyHp()
{
	return hp;
}


string Fire::iAm()
{
	return this->objectName;
}


