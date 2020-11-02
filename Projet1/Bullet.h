#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Bullet : public sf::Sprite
{
	//Attributs
private:
	sf::Vector2f velocity;
public:

	//Methods
public:
	Bullet(float posX, float posY, float velocity);
	~Bullet();
	void move();
private:
};

