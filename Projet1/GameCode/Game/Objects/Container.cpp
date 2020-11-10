#include "Container.h"

Container::Container(int hp, bool destroyable)
{
	this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Container::verifyHp()
{
	if (hp <= 0 && destroyable)
	{
		container.kill(container);
	}
	return hp;
}

void Container::checkCollision()
{
	if (container.getCollision(container))
	{
		verifyHp();
	}
}

