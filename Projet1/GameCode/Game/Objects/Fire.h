#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Fire : BaseEntity
{
private:

public:
	Fire(int hp, bool destroyable);
	int verifyHp();
	string iAm();

};

