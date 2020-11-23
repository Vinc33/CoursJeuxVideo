#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Platform : BaseEntity
{
private:

public:
	Platform(int hp, bool destroyable);
	int verifyHp();
	string iAm();

};

