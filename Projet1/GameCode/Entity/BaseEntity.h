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
	virtual bool getCollision(BaseEntity* entity);
protected:
	sf::Sprite sprite;
	string objectName;
	bool isCollided;

	virtual sf::Vector2f getPosition();
	virtual void onCollide(Collidable& other);

	int hp;
	bool isDestroyable;
};

