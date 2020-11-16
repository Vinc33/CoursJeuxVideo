#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Barrel : BaseEntity
{
	private:
		BaseEntity barrel;

	public:
		Barrel(int hp, bool destroyable);
		int verifyHp();
		void checkCollision();
		string iAm();

};

