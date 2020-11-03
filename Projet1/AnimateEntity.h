#pragma once
#include <string>
#include <map>
#include <Entity/BaseEntity.h>
#include <SFML/Graphics.hpp>
#include "Entity/Animation.h"

class AnimateEntity :public BaseEntity
{
public:
	AnimateEntity(std::string spriteName, int largeur, int hauteur);
	~AnimateEntity(){}//destructeur
	
	void updateAnimateEntity() {}

	void addAnim(Animation* anim, std::string animName) { animMap[animName] = anim; }
	void setAnim(std::string animToPlay) { currentAnim = animMap[animToPlay]; }

	virtual void render(sf::RenderTarget& target);

private:
	Animation* currentAnim;
	map<string, Animation*> animMap;
};

