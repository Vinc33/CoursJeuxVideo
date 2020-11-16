#include "BaseEntity.h"
#include "Manager/AssetManager.h"

BaseEntity::BaseEntity(string spriteName)
{
	sprite.setTexture(AssetManager::getTexture(spriteName) );
}

BaseEntity::BaseEntity():Collidable()
{
	isDestroyable = false;
	hp = 0;
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