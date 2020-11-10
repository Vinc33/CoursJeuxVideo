#include "Player.h"

//Constructors
Player::Player(std::string spriteName, int hauteur,int largeur):AnimateEntity(spriteName, hauteur, largeur)
{
	health = 100;
	velocity = Vector2f(1.0, 1.0);
	acceleration = Vector2f(0.0, 0.0);
	direction = DROITE;
	weapon = new Weapon();
	invincibleTimer = 0;
}

Player::Player(std::string nom, int health,Vector2f velocity,Vector2f acceleration, Direction direction, Weapon* weapon,std::string spriteName, int hauteur, int largeur) :AnimateEntity(spriteName, hauteur, largeur)
{
	this->nom = nom;
	this->health = health;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->direction = direction;
	this->weapon = weapon;
}

Player::~Player()
{
	delete weapon;
}

//Gets
#pragma region Gets
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
#pragma endregion Gets

//Sets
#pragma region Sets
void Player::setHealth(int addition)
{
	health += addition;
	health > 100 ? health = 100 : health = health;
	health < 0 ? health = 0 : health = health;
}

void Player::setAcceleration(float value)
{
	acceleration.x = value;
	acceleration.y = value;
}

void Player::setVelocity(Vector2f value)
{
	velocity.x = value.x;
	velocity.y = value.y;
}

void Player::setDirection(Direction direction)
{
	this->direction = direction;
}

void Player::setInvincibleTimer(int value)
{
	invincibleTimer = value;
}

void Player::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}
#pragma endregion Sets

//Methods
void Player::move(Vector2f movement)
{
	float x = ((velocity.x + acceleration.x) * movement.x) + sprite.getPosition().x;
	float y = ((velocity.y + acceleration.y) * movement.y) + sprite.getPosition().y;
	sprite.setPosition(x,y);
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
