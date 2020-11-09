#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <string>
#include <SFML\System\Vector2.hpp>
#include "Utils/enums.h"
#include "Weapon.h"
#include "AnimateEntity.h"

using sf::Vector2f;

class Player : public AnimateEntity
{
	//attributs
private:
	Vector2f acceleration;
	Vector2f velocity;
	int health;
	std::string nom;
	Direction direction;
	Weapon* weapon;
	int invincibleTimer;

	//methods
private:

public:
	//Constructors/Desctructor
	Player(std::string nom, int health,Vector2f velocity, Vector2f acceleration, Direction direction, Weapon* weapon,std::string spriteName, int hauteur, int largeur);
	Player(std::string spriteName,int hauteur,int largeur);
	~Player();
	
	//gets
	inline Vector2f getAcceleration();
	inline Vector2f getVelocity();
	inline Direction getDirection();
	inline int getHealth();
	int getInvincibleTimer(int reelTime);
	
	//sets
	void setAcceleration(float addition);
	void setVelocity(Vector2f addition);
	void setHealth(int addition);
	void setDirection(Direction direction);
	void setInvincibleTimer(int value);
	
	//Methods
	void move(Vector2f movement);
	void substractHealth(int substract);
	void addHealth(int addition);
	bool getIsInvincible();
};

