#pragma once
#include <string>
#include "./Manager/AssetManager.h";
#include "./Manager/InputManager.h"
#include "./Manager/TimeManager.h"
#include "AnimFactory.h"
#include "GameState.h"
#include "Entity/BaseEntity.h"
#include "Entity/Player.h"
#include <TGUI/TGUI.hpp>
#include "Input/KeyboardMap.h"
#include "Map.h"
#include "Utils/Objects.h"

using namespace sf;

class Game
{

public:
	Game(int width, int height, string titleScreen);
	~Game();

	virtual void init();
	void startGame();

private://Fonctions
	void update();
	void updateInput();
	void updateLogic();
	void updateEvent();
	void render();
	void movePlayer(Event event);
	void playerCheckCollision();

	//Fonction test, à enlever
	static void signalHandler();

	//Variables
	Event event;
	TimeManager timeManager;
	const unsigned int FPS = 60;
	GameDef::GameDataRef data = std::make_shared<GameDef::GameData>();
	sf::Vector2f vecteurDeplacement;
	Player* player;
	Player* playerTest;
	KeyboardMap* keyboardMap = new KeyboardMap();
	Map* map;


protected:
	//ViewManager* camera;
	GameState* currentGameState = new GameState("MainMenu", data, &event, keyboardMap);

};
