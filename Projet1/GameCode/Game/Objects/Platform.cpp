#include "Platform.h"

Platform::Platform(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->isDestroyable = destroyable;
	objectName = "Platform";
}

int Platform::verifyHp()
{
	return hp;
}

string Platform::iAm()
{
	return this->objectName;
}


