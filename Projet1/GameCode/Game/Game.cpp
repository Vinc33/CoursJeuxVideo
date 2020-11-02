#include "Game.h"
#include <cstdlib>
#include <vector>
#include <iostream>


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
		// passe tous les events avant de continuer 
		while (data->window.pollEvent(event))
		{
			//currentState->updateEvent(event);
			if (event.type == Event::Closed)
				data->window.close();
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