#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
class BaseEntity
{
public:
	BaseEntity() {}
	BaseEntity(string spriteName, string objectName, int hp, int damage, bool isDestroyable);
	virtual ~BaseEntity() {}
			
	virtual void update() {}
	virtual void render(sf::RenderTarget& target);
	virtual void kill(BaseEntity entity);
	virtual bool getCollision(BaseEntity entity);
protected:
	sf::Sprite sprite;
	string objectName;
	bool isCollided;
	int hp;
	int damage;
	bool isDestroyable;
};

