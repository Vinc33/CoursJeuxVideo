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


using namespace sf;

namespace GameView
{
	struct GameData
	{
		sf::RenderWindow window;
		tgui::Gui gui{ window };
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
		void movePlayer(Event event);


		//Fonction test, à enlever
		static void signalHandler();

		//Variables
		TimeManager timeManager;
		const unsigned int FPS = 60;
		GameDataRef data = std::make_shared<GameData>();
		sf::Vector2f vecteurDeplacement;
		Player* player;
		//test
		Player* playerTest;
		KeyboardMap* keyboardMap;
		Map* map;


	protected:
		//ViewManager* camera;
		//GameState* currentState;

	};
}
