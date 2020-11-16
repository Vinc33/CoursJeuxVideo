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
	Fire(int hp, bool destroyable);
	int verifyHp();
	void checkCollision();
	string iAm();

};

