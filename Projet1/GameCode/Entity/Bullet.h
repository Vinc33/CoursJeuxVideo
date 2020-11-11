#pragma once
#include "AnimateEntity.h"
#include <SFML/System/Vector2.hpp>

class Bullet : public AnimateEntity
{
	//Attributs
private:
	sf::Vector2f velocity;
public:

	//Methods
public:
	Bullet(float posX, float posY, float velocity,std::string spriteName,int hauteur, int largeur);
	~Bullet();
	void move();
private:
};

