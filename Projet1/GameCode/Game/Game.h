#pragma once
#include <string>
#include "./Manager/AssetManager.h";
#include "./Manager/InputManager.h"
#include "./Manager/TimeManager.h"
#include "GameState.h"
#include "Entity/BaseEntity.h"
#include "Entity/Player.h"
#include <TGUI/TGUI.hpp>
#include "Input/KeyboardMap.h"


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


		//Fonction test, � enlever
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


	protected:
		//ViewManager* camera;
		//GameState* currentState;

	};
}
