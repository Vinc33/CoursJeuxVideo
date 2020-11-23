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
		delete playerTest;
	}

	void Game::init()
	{
		data->window.setFramerateLimit(FPS);
		AssetManager::init();
		InputManager::init();
		player = new Player("steamMan",24,40);
		player->setWeapon(new Weapon("steamMan", "steamMan"));
		player->setPosition(400, 400);
		player->setVelocity(Vector2f(20, 20));//exemple pour augmenter la vitesse

		//testing
		playerTest = new Player("steamMan", 24, 40);
		playerTest->setWeapon(new Weapon("steamMan","steamMan"));
		playerTest->setPosition(200, 400);
		cout << player->getSprite()->getTextureRect().width;
		cout << player->getSprite()->getTextureRect().height;
		map = new Map();
		map->setBackground("Assets/Background/placeholder.jpg");
		
		keyboardMap = new KeyboardMap();
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
				bool keyPressed = true;
				if (InputManager::getPressedKeyCode(event) == 36) //Si ESCAPE est appuyé, ferme le programme.
					data->window.close();
				else
					movePlayer(event);
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

			if (event.type == Event::MouseEntered)
			{
				std::cout << "a" << std::endl;
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

		map->update();
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

			//currentState->updateInput();
			//currentState->update();
			//render(); //Animations
			//updateEvent();

			//Widgets v
			/*data->window.clear();
			data->gui.draw(); // Draw all widgets
			data->window.display();*/

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

		map->render(data->window);
		player->render(data->window);

		//testing
		playerTest->render(data->window);

		data->window.display();

	}

	void  Game::movePlayer(Event event)		//Deplace le joueur en fonction de la touche
	{
		Vector2f deplacement(0, 0);
		bool keyPressed = true;
		bool moved = true;

		if (InputManager::getPressedKeyCode(event) == keyboardMap->getUpKey())
			deplacement.y = -1;
		else if (InputManager::getPressedKeyCode(event) == keyboardMap->getLeftKey())
			deplacement.x = -1;
		else if (InputManager::getPressedKeyCode(event) == keyboardMap->getDownKey())
			deplacement.y = 1;
		else if (InputManager::getPressedKeyCode(event) == keyboardMap->getRightKey())
			deplacement.x = 1;
		else if (InputManager::getPressedKeyCode(event) == keyboardMap->getAttackKey()) 
		{
			player->shoot(5);	//evite d'entrer dans la boucle suivante fait pour les déplacement sans s'être déplacé
			moved = false;		//si on enleve ca, les balles ne marcheront pas lorsque l'on shoot sans se déplacer
		}						
		if(moved)
			player->move(deplacement);

		if (player->tryCollideWith((*playerTest)))
			cout << "Colision" << endl;
		
		/*while (keyPressed && moved)
		{
			data->window.pollEvent(event);				//À ne jamais remettre!!!  Ordre de Vincent.
			if (event.type == Event::KeyReleased)
				keyPressed = false;
			player->move(deplacement);
			//player->render(data->window);
			render();
		}*/
	}
}