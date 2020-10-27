#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <string>
#include <SFML\System\Vector2.hpp>

using namespace sf;

class Player : public Sprite
{
	//attributs
private:
	Vector2f acceleration;
	Vector2f velocity;
	int health;
	std::string nom;

public:

	//methods
private:

public:
	Player();
	Player(std::string nom);
	~Player();
	Vector2f getAcceleration();
	Vector2f getVelocity();
	int getHealth();
	void setAcceleration(float addition);
	void setVelocity(Vector2f addition);
	void setHealth(int addition);
	void move(Vector2f movement);
	void substractHealth(int substract);
	void addHealth(int addition);
};

