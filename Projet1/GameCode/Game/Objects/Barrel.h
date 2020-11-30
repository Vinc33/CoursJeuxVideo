#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Barrel : public BaseEntity
{
	private:

	public:
		Barrel(int hp, int damage, bool destroyable);
		int Barrel::verifyHp();
		string iAm();

};

