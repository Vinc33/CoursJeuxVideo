#include "Platform.h"

Platform::Platform(int hp, bool destroyable) : BaseEntity("Asset/Sprite/barrel.png", "platform", 100, 0, false)
{

}

int Platform::verifyHp()
{
	if (this->hp <= 0 && this->isDestroyable)
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

string Platform::iAm()
{
	return this->objectName;
}


