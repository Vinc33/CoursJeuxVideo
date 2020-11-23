#include "Platform.h"

Platform::Platform(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
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


