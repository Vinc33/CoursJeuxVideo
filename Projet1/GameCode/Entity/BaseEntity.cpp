#include "BaseEntity.h"
#include "Manager/AssetManager.h"

BaseEntity::BaseEntity(string spriteName, float boxWidth, float boxHeight) : Collidable(boxWidth, boxHeight)
{
	sprite.setTexture(AssetManager::getTexture(spriteName) );
	hp = 0;
	isDestroyable = false;
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

bool BaseEntity::getCollision(BaseEntity* entity)
{
	isCollided = false;
	/* if (entity est en collision)
	{
		isCollided = true;
	}*/

	return isCollided;
}