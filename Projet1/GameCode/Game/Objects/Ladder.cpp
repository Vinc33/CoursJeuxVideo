#include "Ladder.h"

Ladder::Ladder(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png", "ladder", 100, 0, false)
{

}

int Ladder::verifyHp()
{
	if (this->hp <= 0 && this->isDestroyable)
	{
		ladder.kill(ladder);
	}
	return hp;
}

void Ladder::checkCollision()
{
	if (ladder.getCollision(ladder))
	{
		verifyHp();
	}
}

string Ladder::iAm()
{
	return this->objectName;
}


