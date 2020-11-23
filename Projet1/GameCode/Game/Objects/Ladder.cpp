#include "Ladder.h"

Ladder::Ladder(int hp, bool destroyable) : BaseEntity("steamMan")
{
	this->hp = hp;
	this->isDestroyable = destroyable;
	objectName = "Ladder";
	//ne pas oublier de setter le box du collision
}

int Ladder::verifyHp()
{
	return hp;
}

string Ladder::iAm()
{
	return this->objectName;
}


