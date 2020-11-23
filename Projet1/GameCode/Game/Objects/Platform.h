#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Platform : public BaseEntity
{
private:

public:
	Platform(int hp, bool destroyable);
	int verifyHp();
	string iAm();

};

