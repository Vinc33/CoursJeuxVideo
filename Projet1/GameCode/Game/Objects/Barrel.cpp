#include "Barrel.h"

Barrel::Barrel(int hp, bool destroyable)
{
	//this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Barrel::verifyHp()
{
	return this->hp;
}

void Barrel::checkCollision()
{

}

