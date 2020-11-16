#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Barrel : BaseEntity
{
	private:
		int hp;
		bool destroyable;

	public:
		Barrel(int hp, bool destroyable);
		int Barrel::verifyHp();
		void Barrel::checkCollision();

};

