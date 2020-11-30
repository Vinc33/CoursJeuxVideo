#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Fire : public BaseEntity
{
private:

public:
	Fire(int hp, int damage, bool destroyable);
	int verifyHp();
	string iAm();

};

