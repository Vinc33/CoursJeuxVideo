#include "AnimateEntity.h"
#include "Manager/AssetManager.h"
#include "Entity/Animation.h"


AnimateEntity::AnimateEntity(std::string spriteName, int largeur, int hauteur) : BaseEntity(spriteName)
{
	currentAnim = 0;
}

void AnimateEntity::render(sf::RenderTarget& target)
{
	sprite.setTextureRect(currentAnim->getFrame());
}