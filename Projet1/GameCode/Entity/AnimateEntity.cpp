#include "AnimateEntity.h"
#include "Manager/AssetManager.h"
#include "Entity/Animation.h"


AnimateEntity::AnimateEntity(std::string spriteName, int largeur, int hauteur,float boxWidth, float boxHeight) : BaseEntity(spriteName,boxWidth,boxHeight)
{
	currentAnim = 0;
}

#pragma region Gets
Sprite* AnimateEntity::getSprite()
{
	return &sprite;
}
#pragma endregion Gets

/*AnimateEntity::AnimateEntity()
{

}*/

/*void AnimateEntity::render(sf::RenderTarget& target)
{
	//sprite.setTextureRect(currentAnim->getFrame());
}*/