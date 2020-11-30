#pragma once
#include <string>
#include "./Entity/BaseEntity.h"

using namespace std;

class Crate : public BaseEntity
{
private:

public:
	Crate(int hp, int damage, bool destroyable);
	int verifyHp();
	string iAm();

};

