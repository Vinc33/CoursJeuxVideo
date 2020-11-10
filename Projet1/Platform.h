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
	Platform::Platform(int hp, bool destroyable);
	int Platform::verifyHp();
	void Platform::checkCollision();

};
