#pragma once
#include <String>
#include "./Entity/BaseEntity.h"

using namespace std;

class Barrel : BaseEntity
{
	private:
		int hp;
		bool destroyable;
		string sprite;
		BaseEntity barrel;

	public:
		Barrel::Barrel(int hp, bool destroyable);
		int Barrel::verifyHp();
		void Barrel::checkCollision();

};

