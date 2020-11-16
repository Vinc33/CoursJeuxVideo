#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Container : BaseEntity
{
private:
	int hp;
	bool destroyable;

public:
	Container::Container(int hp, bool destroyable);
	int Container::verifyHp();
	void Container::checkCollision();

};

