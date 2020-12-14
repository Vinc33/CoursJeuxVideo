#pragma once
#include "SFML/Window/Event.hpp"
#include "./Manager/AssetManager.h";
#include "./Manager/InputManager.h"
#include "./Manager/TimeManager.h"
#include "Input/KeyboardMap.h"
#include "GameDef.h"
#include "Game/Tycoon/MainTycoon.h"

class GameState
{
public:

	GameState(std::string state, std::shared_ptr<GameDef::GameData> data, Event* event, KeyboardMap* keyboardMap);

	enum State { Pause, Platformer, Tycoon, MainMenu, Settings };

	virtual void updateEvent(sf::Event event) {}
	virtual void updateInput() {}
	void update();
	virtual void draw() {}

	void changeGameState(std::string state);

private:

	MainTycoon* main = new MainTycoon();
	std::string state;
	std::shared_ptr<GameDef::GameData> data;
	Event* event;
	KeyboardMap* keyboardMap;

};

