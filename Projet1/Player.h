#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <string>
#include <SFML\System\Vector2.hpp>
#include "enums.h"
#include "Weapon.h"
#include "Vecteur.h"

using namespace sf;

class Player : public Sprite
{
	//attributs
private:
	Vecteur* acceleration;
	Vecteur* velocity;
	int health;
	std::string nom;
	Direction direction;
	Weapon* weapon;
	int invincibleTimer;

	//methods
private:

public:
	//Constructors/Desctructor
	Player();
	Player(std::string nom);
	~Player();
	
	//gets
	Vecteur* getAcceleration();
	Vecteur* getVelocity();
	Direction getDirection();
	int getHealth();
	int getInvincibleTimer(int reelTime);
	
	//sets
	void setAcceleration(float addition);
	void setVelocity(Vecteur addition);
	void setHealth(int addition);
	void setDirection(Direction direction);
	void setInvincibleTimer(int value);
	
	//Methods
	void move(Vecteur movement);
	void substractHealth(int substract);
	void addHealth(int addition);
	Direction getDirection();
	void setDirection(Direction direction);
	bool getIsInvincible();
};

