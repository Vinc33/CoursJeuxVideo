#include "Barrel.h"


Barrel::Barrel(int hp, int damage, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png")
{
	this->hp = hp; // hp c'est celui de baseEntity
	this->damage = damage;
	this->isDestroyable = destroyable;
	objectName = "Barrel";
	//ne pas oublier de setter le box du collision
}

int Barrel::verifyHp()
{
	return hp;
}


string Barrel::iAm()
{
	return this->objectName;
}


