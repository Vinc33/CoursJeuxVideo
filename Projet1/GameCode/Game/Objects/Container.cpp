#include "Container.h"

Container::Container(int hp, bool destroyable)
{
	//this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Container::verifyHp()
{
	return hp;
}

void Container::checkCollision()
{

}

