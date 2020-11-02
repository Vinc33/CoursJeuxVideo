#include "Player.h"

//Constructors
Player::Player()
{
	health = 100;
	velocity = new Vecteur(1.0, 1.0);
	acceleration = new Vecteur(0.0, 0.0);
	direction = DROITE;
	weapon = new Weapon();
	invincibleTimer = 0;
}

Player::Player(std::string nom)
{
	this->nom = nom;
	Player();
}

Player::~Player()
{
	delete weapon;
}

//Gets
Vecteur* Player::getVelocity()
{
	return velocity;
}

Vecteur* Player::getAcceleration()
{
	return acceleration;
}

int Player::getHealth()
{
	return health;
}

Direction Player::getDirection()
{
	return direction;
}

int Player::getInvincibleTimer(int reelTime)
{
	int timer = reelTime - invincibleTimer;
	timer < 0 ? timer = 0 : timer = timer;
	return timer;
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
	acceleration->x += addition;
	acceleration->y += addition;
}

void Player::setVelocity(Vecteur addition)
{
	velocity->x += addition.x;
	velocity->y += addition.y;
}

void Player::setDirection(Direction direction)
{
	this->direction = direction;
}

void Player::setInvincibleTimer(int value)
{
	invincibleTimer = value;
}

//Methods
void Player::move(Vecteur movement)
{
	float x = velocity->x + acceleration->x + movement.x + getPosition().x;
	float y = velocity->y + acceleration->y + movement.y + getPosition().y;
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

bool Player::getIsInvincible()
{
	if (invincibleTimer > 0)		//deviendra : si le temps est plus grand que le timer 
		return true;
	return false;
}
