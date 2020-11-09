#include "Game.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#ifdef NDEBUG
static bool debug = true;
#else
static bool debug = false;
#endif


//initialize static variables

namespace GameView
{
	Game::Game(int width, int height, string titleScreen)
	{
		data->window.setVerticalSyncEnabled(true);
		data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
		Vector2f vecteurDeplacement (0.0, 0.0);
	}

	Game::~Game()
	{
		delete player;
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
		AssetManager::init();
		InputManager::init();
		player = new Player("steamMan", 48, 48);
		player->setPosition(400, 400);
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
				//cout << InputManager::getPressedKeyChar(event) << endl; //Player va prendre valeur de la clé(getPressedKeyCode(event)) et définir son mouvement
				if (InputManager::getPressedKeyCode(event) == 36) //Si ESCAPE est appuyé, ferme le programme.
					data->window.close();
				else
					addDeplacement(event);
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (InputManager::isMouseButtonPressed(event, sf::Mouse::Button::Left))
					std::cout << "Le bouton gauche a ete appuyee" << std::endl;
				if (InputManager::isMouseButtonPressed(event, sf::Mouse::Button::Right))
					std::cout << "Le bouton droit a ete appuyee" << std::endl;
				if (InputManager::isMouseButtonPressed(event, sf::Mouse::Button::Middle))
					std::cout << "Le bouton milieu a ete appuyee" << std::endl;
			}
			if (InputManager::isMouseWheelScrolled(event))
				std::cout << "Le bouton milieu scroll a ete appuyee" << std::endl;


			data->gui.handleEvent(event); // Pass the event to the widgets

		}
	}


	void Game::updateLogic()
	{
		//mettre les collision ici 
	}

	//fonction test bouton
	void Game::signalHandler()
	{
		std::cout << "Button pressed" << std::endl;
	}

	void Game::update()
	{
		//Testing GUI below - NOD, à effacer au futur
		tgui::Button::Ptr button = tgui::Button::create(); //Crée un bouton
		auto editBox = tgui::EditBox::create();
		data->gui.add(button, "monBouton"); //Ajoute le bouton au GUI principal
		data->gui.add(editBox, "monBox"); 
		editBox = data->gui.get<tgui::EditBox>("monBox");
		button = data->gui.get<tgui::Button>("monBouton"); //Relie le bouton au GUI principal
		button->setPosition(50, 50);
		button->setSize(250, 100);
		button->setText("This is a button");
		button->setTextSize(28);
		button->connect("Pressed", Game::signalHandler); //Relier le bouton à une fonction(doit être statique si on utilise la classe et non une instance), le premier paramètre est prédéfinis
		button->connect("Pressed", [&]() { std::cout << "input2" << endl; }); //Exemple en lambda, notez que le bouton peut prendre deux fonctions

		//End of testing GUI
		while (data->window.isOpen())
		{
			//boucle de jeu
			timeManager.update();
		//	currentState->updateInput();
		//	currentState->update();
			render();
			//	currentState->updateInput();
			//	currentState->update();
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

		player->render(data->window);

		data->window.display();

	}

	void  Game::addDeplacement(Event event)
	{
		Vector2f deplacement(0, 0);
		if (InputManager::getPressedKeyCode(event) == 0)
			deplacement.x = -1;
	}
}