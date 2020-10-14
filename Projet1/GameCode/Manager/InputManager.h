#pragma once
#include "./Manager/TimeManager.h"
#include "./Input/InputMap.h"
#include "./Input/EnumInput.h"
#include <vector>

using namespace std;

class InputManager
{
public:
	InputManager();
	~InputManager();

	static void init();

	static void update();

	static bool getKeyState(int playerID, INPUT key);

private:
	static vector<InputMap*> players;
};

