#include "Game.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Utils/Objects.h" // Include des objets/entités
#ifdef NDEBUG
bool debug = true;
#else
bool debug = false;
#endif
#include <Game\Tycoon\MainTycoon.h>

//initialize static variables
//je veux update

Game::Game(int width, int height, string titleScreen)
{
	data->window.setVerticalSyncEnabled(true);
	data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
	Vector2f vecteurDeplacement(0.0, 0.0);
}


Game::~Game()
{
	delete player;
	delete playerTest;
	delete map;
}

void Game::init()
{
	data->window.setFramerateLimit(FPS);
	AssetManager::init();
	InputManager::init();
	AnimFactory::initFactory();

	player = new Player("steamMan", 24, 40);
	player->setWeapon(new Weapon("steamMan", "steamMan"));
	player->setPosition(400, 400);
	player->setVelocity(Vector2f(20, 20));//exemple pour augmenter la vitesse
	player->setAnim("anim_steamman_idle");

	cout << player->getSprite()->getTextureRect().width;
	cout << player->getSprite()->getTextureRect().height;

	map = new Map();
	map->setBackground("Assets/Background/placeholder.jpg");
	//testing map
	map->addMapEntity(new Ladder(100, 0, false));
}

void Game::updateEvent()
{
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

		if (InputManager::isMouseWheelScrolled(event))
			std::cout << "Le bouton milieu scroll a ete appuyee" << std::endl;
		if (InputManager::isMouseHover(event)) {
			std::cout << "Vous etes entrez dans l'objet" << std::endl;
		}
		if (InputManager::isMouseNotHover(event)) {
			std::cout << "Vous avez quitter l'objet" << std::endl;
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
	currentGameState->changeGameState("MainMenu");

	while (data->window.isOpen())
	{
		map->update();

		while (data->window.isOpen())
		{
			//boucle de jeu
			timeManager.update();

			//	currentState->updateInput();
			//	currentState->update();
			updateEvent();

			render(); //Animations
		}
	}
}

void Game::updateInput()
{
	InputManager::update();
}

void Game::startGame()
{
	/* TESTING
	Barrel* barrel = new Barrel(100, 0, false);
	barrel->setPosition(1, 2);
	map->addMapObject(barrel);

	Barrel* barrel4 = new Barrel(100, 0, false);
	barrel4->setPosition(100, 2);
	map->addMapObject(barrel4);

	Barrel* barrel1 = new Barrel(100, 0, false);
	barrel1->setPosition(1, 201);
	map->addMapObject(barrel1);

	Barrel* barrel2 = new Barrel(100, 0, false);
	barrel2->setPosition(1, 401);
	map->addMapObject(barrel2);

	Barrel* barrel3 = new Barrel(100, 0, false);
	barrel3->setPosition(1, 601);
	map->addMapObject(barrel3);
	*/// FIN TESTING

	update();
}

void Game::render()
{
	data->window.clear(Color::Black);

	map->render(data->window);
	player->render(data->window);
	player->render(data->window);
	data->gui.draw(); // Draw all widgets

	data->window.display();

}

void Game::movePlayer(Event event)		//Deplace le joueur en fonction de la touche
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


	/*while (keyPressed && moved)
	{
		data->window.pollEvent(event);				//À ne jamais remettre!!!  Ordre de Vincent.
		if (event.type == Event::KeyReleased)
			keyPressed = false;
		player->move(deplacement);
		//player->render(data->window);
		render();
	}*/

	if (moved)
		player->move(deplacement);
	playerCheckCollision();

}

void Game::playerCheckCollision()
{
	// Pour tester, les objets ont été créés dans startGame
	std::vector<std::list<BaseEntity*>> mapObjects = map->getMapObjects();
	int i = 0;
	for (auto it = mapObjects[player->getPalier()].begin(); it != mapObjects[player->getPalier()].end(); it++)
	{
		i++;
	}
	cout << "\nVous etes sur le palier #" << player->getPalier() << " et il y a " << i << " objets\n";

	/*if (player->getPalier() == unBaseEntity->getPalier())
	{
		if (player->getCollision(unBaseEntity))
		{
			player->substractHealth(unBaseEntity->getDamage());
		}
	}*/
}
