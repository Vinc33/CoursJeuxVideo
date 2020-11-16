#pragma once
#include <string>
#include "./Entity/BaseEntity.h"
#include "./Input/KeyboardMap.h"
#include "./Manager/InputManager.h"
#include "SFML/Window/Event.hpp"

using namespace std;

class Ladder : BaseEntity
{
private:
	int hp;
	bool destroyable;
	string sprite;
	BaseEntity ladder;

public:
	Ladder(int hp, bool destroyable);
	int verifyHp();
	void checkCollision();
	string iAm();

};

