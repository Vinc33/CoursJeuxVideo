#include "Vector2f.h"

//Constructors/Destructor
Vector2f::Vector2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2f::~Vector2f()
{

}

//Méthodes
void Vector2f::Add(Vector2f Vector2f)
{
	this->x += Vector2f.x;
	this->y += Vector2f.y;
}

void Vector2f::Substract(Vector2f Vector2f)
{
	this->x -= Vector2f.x;
	this->y -= Vector2f.y;
}

void Vector2f::Multiply(float scalair)
{
	this->x *= scalair;
	this->y *= scalair;
}

void Vector2f::Divide(float scalair)
{
	this->x /= scalair;
	this->y /= scalair;
}