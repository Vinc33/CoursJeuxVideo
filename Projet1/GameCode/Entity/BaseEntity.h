#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "collidable.h"

using namespace std;
class BaseEntity : public Collidable
{
public:
	BaseEntity();
	BaseEntity(std::string spriteName);
	virtual ~BaseEntity() {}
			
	virtual void update() {}
	virtual void render(sf::RenderTarget& target);
	virtual void kill(BaseEntity* entity);
	virtual bool getCollision(BaseEntity* entity);
protected:
	sf::Sprite sprite;
	bool isCollided;
	virtual sf::Vector2f getPosition();
	virtual void onCollide(Collidable& other);
};

