#include "Container.h"

Container::Container(int hp, bool destroyable) : BaseEntity("Asset/Sprite/container.png")
{
	this->hp = hp;
	this->isDestroyable = destroyable;
	objectName = "Container";
	//ne pas oublier de setter le box du collision
}

int Container::verifyHp()
{
	return hp;
}

void Container::checkCollision()
{

}

string Container::iAm()
{
	return this->objectName;
}


