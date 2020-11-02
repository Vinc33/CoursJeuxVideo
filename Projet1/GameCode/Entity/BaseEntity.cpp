#include "BaseEntity.h"
#include "Manager/AssetManager.h"

BaseEntity::BaseEntity(std::string spriteName)
{
	sprite.setTexture(AssetManager::getTexture(spriteName) );
}

void BaseEntity::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}