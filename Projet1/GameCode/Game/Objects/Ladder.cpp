#include "Ladder.h"

Ladder::Ladder(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->isDestroyable = destroyable;
	objectName = "Ladder";
}

int Ladder::verifyHp()
{
	return hp;
}

string Ladder::iAm()
{
	return this->objectName;
}


