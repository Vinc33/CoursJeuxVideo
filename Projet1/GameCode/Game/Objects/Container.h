#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Container : BaseEntity
{
private:
	BaseEntity container;

public:
	Container(int hp, bool destroyable);
	int verifyHp();
	void checkCollision();
	string iAm();

};

