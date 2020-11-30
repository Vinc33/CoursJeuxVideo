#include "Barrel.h"

Barrel::Barrel(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png", "barrel", 100, 0, false)
{

}

int Barrel::verifyHp()
{
	if (this->hp <= 0 && this->isDestroyable)
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

string Barrel::iAm()
{
	return this->objectName;
}


