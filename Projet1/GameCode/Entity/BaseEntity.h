#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "collidable.h"
#include "Utils/Consts.h"
#include <iostream>

using namespace std;
class BaseEntity : public Collidable
{
private:
	int palier;

public:
	BaseEntity(std::string spriteName, float boxWidth = 0, float boxHeight = 0);
	virtual ~BaseEntity() {}
			
	virtual int update();
	virtual void render(sf::RenderTarget& target);
	virtual bool getCollision(BaseEntity* entity);

	int checkPalier();

	//Gets
	int getPalier();
	int getDamage();
	int getHealth();
	sf::Sprite* getSprite();

	//Sets
	void setPalier(int palier);
protected:
	sf::Sprite sprite;
	string objectName;
	bool isCollided;

	virtual sf::Vector2f getPosition();
	virtual void onCollide(Collidable& other);

	int hp;
	int damage;
	bool isDestroyable;
};

