#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Crate : BaseEntity
{
private:
	int hp;
	bool destroyable;
	string sprite;
	BaseEntity crate;

public:
	Crate::Crate(int hp, bool destroyable);
	int Crate::verifyHp();
	void Crate::checkCollision();

};
