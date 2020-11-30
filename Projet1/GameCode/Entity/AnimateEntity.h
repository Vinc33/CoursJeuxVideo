#pragma once
#include <string>
#include <map>
#include <Entity/BaseEntity.h>
#include <SFML/Graphics.hpp>
#include "Entity/Animation.h"
#include "AnimFactory.h"

class AnimateEntity :public BaseEntity
{
public:
	AnimateEntity(std::string spriteName, int largeur, int hauteur, float boxWidth = 0, float boxHeight = 0);
	~AnimateEntity(){}//destructeur
	
	void updateAnimateEntity() {}
	void setAnim(std::string animToPlay);

	//Gets
	sf::Sprite* getSprite();

	virtual void render(sf::RenderTarget& target);

private:
	Animation* currentAnim;
	std::map<std::string, Animation*> animMap;
};

