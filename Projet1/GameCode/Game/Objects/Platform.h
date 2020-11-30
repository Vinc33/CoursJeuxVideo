#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Platform : public BaseEntity
{
private:

public:
	Platform(int hp, int damage, bool destroyable);
	int verifyHp();
	string iAm();

};

