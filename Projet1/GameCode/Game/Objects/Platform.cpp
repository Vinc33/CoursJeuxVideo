#include "Platform.h"

Platform::Platform(int hp, bool destroyable)
{
	//this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Platform::verifyHp()
{
	return hp;
}

void Platform::checkCollision()
{

}

