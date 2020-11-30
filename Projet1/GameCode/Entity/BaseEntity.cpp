#include "BaseEntity.h"
#include "Manager/AssetManager.h"

BaseEntity::BaseEntity(string spriteName, float boxWidth, float boxHeight) : Collidable(boxWidth, boxHeight)
{
	sprite.setTexture(AssetManager::getTexture(spriteName) );
	hp = 0;
	isDestroyable = false;
	setPalier(sprite.getPosition().y / Consts::PALIERHEIGHT);
}

void BaseEntity::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

int BaseEntity::update()
{
	if (checkPalier() == 1)
		return 1;//has to change lists
	return 0;
	//std::cout << palier << endl;
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

int BaseEntity::checkPalier()
{
	int palier = sprite.getPosition().y / Consts::PALIERHEIGHT;
	if(palier != this->palier)
	{
		setPalier(sprite.getPosition().y / Consts::PALIERHEIGHT);
		return 1;	//has to change lists
	}
	return 0;
}

#pragma region Gets/Sets
//Gets

int BaseEntity::getDamage()
{
	return damage;
}

int BaseEntity::getHealth()
{
	return hp;
}

Sprite* BaseEntity::getSprite()
{
	return &sprite;
}

int BaseEntity::getPalier()
{
	return palier;
}
//Sets
void BaseEntity::setPalier(int palier)
{
	this->palier = palier;
}

void BaseEntity::setPosition(float x , float y)
{
	sprite.setPosition(x, y);
	checkPalier();
}
#pragma endregion