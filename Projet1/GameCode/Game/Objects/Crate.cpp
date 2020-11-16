#include "Crate.h"

Crate::Crate(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png", "crate", 100, false)
{

}

int Crate::verifyHp()
{
	if (this->hp <= 0 && this->isDestroyable)
	{
		crate.kill(crate);
	}
	return hp;
}

void Crate::checkCollision()
{
	if (crate.getCollision(crate))
	{
		verifyHp();
	}
}

string Crate::iAm()
{
	return this->objectName;
}


