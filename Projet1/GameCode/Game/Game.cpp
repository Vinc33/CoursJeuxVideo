#include "Game.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#ifdef NDEBUG
static bool debug = false;
#else
static bool debug = true;
#endif


//initialize static variables

namespace GameView
{
	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
	}

	Game::~Game()
	{
		delete myTest;
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
		AssetManager::init();
		InputManager::init();
		myTest = new BaseEntity("steamMan");
	}

	void Game::updateEvent()
	{
		Event event;
		// Passe tous les events avant de continuer 
		while (data->window.pollEvent(event))
		{
			if (debug)
			{
				if (event.type == Event::KeyPressed)
				{
					cout << InputManager::getPressedKeyCode(event) << endl;
				}
			}

			//currentState->updateEvent(event); //Gamestate
			if (event.type == Event::KeyPressed)
			{
				cout << InputManager::getPressedKeyChar(event) << endl; //Player va prendre valeur de la clé(getPressedKeyCode(event)) et définir son mouvement
				if (InputManager::getPressedKeyCode(event) == 36) //Si ESCAPE est appuyé, ferme le programme.
					data->window.close();
			}

			if (event.type == Event::MouseButtonPressed)
				std::cout << "Une touche a ete appuyee" << std::endl;
		}
	}

	void Game::updateLogic()
	{
		//mettre les collision ici 
	}

	void Game::update()
	{
		while (data->window.isOpen())
		{
			//boucle de jeu
			timeManager.update();
			myTest->update();
		//	currentState->updateInput();
		//	currentState->update();
			render();

			updateEvent();
		}
	}

	void Game::updateInput()
	{
		InputManager::update();
	}

	void Game::startGame()
	{
		update();
	}

	void Game::render()
	{
		data->window.clear(Color::Black);

		myTest->render(data->window);

		data->window.display();
	}
}