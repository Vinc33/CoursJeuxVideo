#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Platform : BaseEntity
{
private:
	int hp;
	bool destroyable;
	string sprite;
	BaseEntity platform;

public:
	Platform(int hp, bool destroyable);
	int verifyHp();
	void checkCollision();
	string iAm();

};

