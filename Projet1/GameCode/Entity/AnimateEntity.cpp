#include "AnimateEntity.h"
#include "Manager/AssetManager.h"
#include "Entity/Animation.h"


AnimateEntity::AnimateEntity(std::string spriteName,float boxWidth, float boxHeight) : BaseEntity(spriteName,boxWidth,boxHeight)
{
	currentAnim = 0;
}

#pragma region Gets
Sprite* AnimateEntity::getSprite()
{
	return &sprite;
}
#pragma endregion Gets


void AnimateEntity::render(sf::RenderTarget& target)
{
	if (currentAnim != nullptr)
	{
		sprite.setTextureRect(currentAnim->getFrame());
	}
	target.draw(sprite);
}

void AnimateEntity::setAnim(std::string animToPlay)
{ 
	currentAnim = AnimFactory::getAnim(animToPlay);
	sprite.setTexture( AssetManager::getTexture(currentAnim->getSpriteName()) );
}