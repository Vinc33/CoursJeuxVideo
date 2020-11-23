#pragma once
#include <string>
#include "./Manager/AssetManager.h";
#include "./Manager/InputManager.h"
#include "./Manager/TimeManager.h"
#include "AnimFactory.h"
#include "GameState.h"
#include "Entity/BaseEntity.h"

using namespace sf;

namespace GameView
{
	struct GameData
	{
		sf::RenderWindow window;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

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

		//Variables
		TimeManager timeManager;
		const unsigned int FPS = 60;
		GameDataRef data = std::make_shared<GameData>();
		BaseEntity* myTest;

	protected:
		//ViewManager* camera;
		GameState* currentState;

	};
}
