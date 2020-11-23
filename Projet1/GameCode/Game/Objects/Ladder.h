#pragma once
#include <string>
#include "./Entity/BaseEntity.h"
#include "./Input/KeyboardMap.h"
#include "./Manager/InputManager.h"
#include "SFML/Window/Event.hpp"

using namespace std;

class Ladder : public BaseEntity
{
private:

public:
	Ladder(int hp, bool destroyable);
	int verifyHp();
	string iAm();

};

