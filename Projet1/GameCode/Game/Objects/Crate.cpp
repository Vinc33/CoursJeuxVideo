#include "Crate.h"

Crate::Crate(int hp, bool destroyable)
{
	//this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Crate::verifyHp()
{

	return hp;
}

void Crate::checkCollision()
{

}

