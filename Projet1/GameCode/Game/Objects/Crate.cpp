#include "Crate.h"

Crate::Crate(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->isDestroyable = destroyable;
	objectName = "Crate";
	//ne pas oublier de setter le box du collision
}

int Crate::verifyHp()
{
	return hp;
}

string Crate::iAm()
{
	return this->objectName;
}


