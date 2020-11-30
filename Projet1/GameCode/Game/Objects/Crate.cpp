#include "Crate.h"

Crate::Crate(int hp, int damage, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp;
	this->damage = damage;
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


