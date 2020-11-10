#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Fire : BaseEntity
{
private:
	int hp;
	bool destroyable;
	string sprite;
	BaseEntity fire;

public:
	Fire::Fire(int hp, bool destroyable);
	int Fire::verifyHp();
	void Fire::checkCollision();

};

