#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Barrel : BaseEntity
{
	private:

	public:
		Barrel(int hp, bool destroyable);
		int Barrel::verifyHp();
		string iAm();

};

