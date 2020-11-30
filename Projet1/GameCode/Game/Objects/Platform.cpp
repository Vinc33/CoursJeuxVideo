#include "Platform.h"

Platform::Platform(int hp, int damage, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->damage = damage;
	this->isDestroyable = destroyable;
	objectName = "Platform";
	//ne pas oublier de setter le box du collision
}

int Platform::verifyHp()
{
	return hp;
}

string Platform::iAm()
{
	return this->objectName;
}


