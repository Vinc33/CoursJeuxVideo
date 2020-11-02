#include "Vecteur.h"

//Constructors/Destructor
Vecteur::Vecteur(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vecteur::~Vecteur()
{

}

//Méthodes
void Vecteur::Add(Vecteur vecteur)
{
	this->x += vecteur.x;
	this->y += vecteur.y;
}

void Vecteur::Substract(Vecteur vecteur)
{
	this->x -= vecteur.x;
	this->y -= vecteur.y;
}

void Vecteur::Multiply(float scalair)
{
	this->x *= scalair;
	this->y *= scalair;
}

void Vecteur::Divide(float scalair)
{
	this->x /= scalair;
	this->y /= scalair;
}