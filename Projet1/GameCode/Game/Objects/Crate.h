#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Crate : BaseEntity
{
private:

public:
	Crate(int hp, bool destroyable);
	int verifyHp();
	string iAm();

};

