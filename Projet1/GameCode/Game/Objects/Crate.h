#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Crate : BaseEntity
{
private:
	BaseEntity crate;

public:
	Crate(int hp, bool destroyable);
	int verifyHp();
	void checkCollision();
	string iAm();

};

