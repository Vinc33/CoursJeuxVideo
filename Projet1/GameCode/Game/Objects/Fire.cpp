#include "Fire.h"

Fire::Fire(int hp, bool destroyable)
{
	//this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Fire::verifyHp()
{
	return hp;
}

void Fire::checkCollision()
{

}

