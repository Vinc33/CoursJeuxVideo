#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class Bullet : public Sprite
{
	//Attributs
private:
	Vecteur velocity;
public:

	//Methods
public:
	Bullet(float posX, float posY, float velocity);
	~Bullet();
	void move();
private:
};

