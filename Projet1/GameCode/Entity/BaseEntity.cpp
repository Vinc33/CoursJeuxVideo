#include "BaseEntity.h"
#include "Manager/AssetManager.h"

BaseEntity::BaseEntity(string spriteName, string objectName, int hp, bool isDestroyable)
{
	sprite.setTexture(AssetManager::getTexture(spriteName) );
	this->isDestroyable = isDestroyable;
	if (isDestroyable)
	{
		this->hp = hp;
	}
}

void BaseEntity::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

void BaseEntity::kill(BaseEntity entity)
{
	// listEntityOnMap[entity] = null;
	//cout << entity << "Has been destroyed";
}

bool BaseEntity::getCollision(BaseEntity entity)
{
	isCollided = false;
	/* if (entity est en collision)
	{
		isCollided = true;
	}*/

	return isCollided;
}