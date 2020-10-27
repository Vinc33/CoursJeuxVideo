#include "Player.h"

//Constructors
Player::Player()
{
	health = 100;
	velocity.x = 1.0;
	velocity.y = 1.0;
	acceleration.x = 0;
	acceleration.y = 0;
}

Player::Player(std::string nom)
{
	this->nom = nom;
	Player();
}

Player::~Player()
{

}

//Gets
Vector2f Player::getVelocity()
{
	return velocity;
}

Vector2f Player::getAcceleration()
{
	return acceleration;
}

int Player::getHealth()
{
	return health;
}

//Sets
void Player::setHealth(int addition)
{
	health += addition;
	health > 100 ? health = 100 : health = health;
	health < 0 ? health = 0 : health = health;
}

void Player::setAcceleration(float addition)
{
	acceleration.x += addition;
	acceleration.y += addition;
}

void Player::setVelocity(Vector2f addition)
{
	velocity.x += addition.x;
	velocity.y += addition.y;
}

//Methods
void Player::move(Vector2f movement)
{
	float x = velocity.x + acceleration.x + movement.x + getPosition().x;
	float y = velocity.y + acceleration.y + movement.y + getPosition().y;
	setPosition(x,y);
}

void Player::substractHealth(int substract)
{
	setHealth(health - substract);
}

void Player::addHealth(int addition)
{
	setHealth(health + addition);
}
