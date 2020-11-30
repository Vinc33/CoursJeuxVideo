#include "Container.h"

Container::Container(int hp, bool destroyable) : BaseEntity("Asset/Sprite/container.png", "container", 100, 0, false)
{

}

int Container::verifyHp()
{
	if (this->hp <= 0 && this->isDestroyable)
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

string Container::iAm()
{
	return this->objectName;
}


