#include "BaseEntity.h"
#include "Manager/AssetManager.h"

BaseEntity::BaseEntity(string spriteName)
{
	sprite.setTexture(AssetManager::getTexture(spriteName) );
}

BaseEntity::BaseEntity():Collidable()
{

}

void BaseEntity::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

sf::Vector2f BaseEntity::getPosition()
{
	return sprite.getPosition();
}

void BaseEntity::onCollide(Collidable& other)
{

}

void BaseEntity::kill(BaseEntity* entity)
{
	// listEntityOnMap[entity] = null;
	//cout << entity << "Has been destroyed";
}

bool BaseEntity::getCollision(BaseEntity* entity)
{
	isCollided = false;
	/* if (entity est en collision)
	{
		isCollided = true;
	}*/

	return isCollided;
}