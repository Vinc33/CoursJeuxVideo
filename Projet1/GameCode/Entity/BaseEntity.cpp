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

void BaseEntity::update()
{
	checkPalier();
	std::cout << palier << endl;
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

void BaseEntity::checkPalier()
{
	setPalier(sprite.getPosition().y / Consts::PALIERHEIGHT);
}

#pragma region Gets/Sets
//Gets
int BaseEntity::getPalier()
{
	return palier;
}
//Sets
void BaseEntity::setPalier(int palier)
{
	this->palier = palier;
}
#pragma endregion