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
	Vector2f direction;
	Weapon* weapon;
	int invincibleTimer;

	//methods
private:

public:
	//Constructors/Desctructor
	Player(std::string nom, int health,Vector2f velocity, Vector2f acceleration, Vector2f direction, Weapon* weapon,std::string spriteName, int hauteur, int largeur, float boxWidth, float boxHeight);
	Player(std::string spriteName,int hauteur,int largeur, float boxWidth, float boxHeight);
	~Player();
	
	//gets
	inline Vector2f getAcceleration();
	inline Vector2f getVelocity();
	inline Vector2f getDirection();
	inline int getHealth();
	int getInvincibleTimer(int reelTime);
	
	//sets
	void setAcceleration(float addition);
	void setVelocity(Vector2f addition);
	void setHealth(int addition);
	void setDirection(Vector2f direction);
	void setInvincibleTimer(int value);
	void setPosition(float x, float y);
	void setWeapon(Weapon* weapon);
	
	//Methods
	void move(Vector2f movement);
	void substractHealth(int substract);
	void addHealth(int addition);
	bool getIsInvincible();
	void shoot(float bulletSpeed);
	void render(sf::RenderTarget& target) override;
};

