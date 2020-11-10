#include "Platform.h"

Platform::Platform(int hp, bool destroyable)
{
	this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Platform::verifyHp()
{
	if (hp <= 0 && destroyable)
	{
		platform.kill(platform);
	}
	return hp;
}

void Platform::checkCollision()
{
	if (platform.getCollision(platform))
	{
		verifyHp();
	}
}

