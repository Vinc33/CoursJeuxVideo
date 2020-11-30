#include "Game.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#ifdef NDEBUG
bool debug = true;
#else
bool debug = true;
#endif


//initialize static variables

Game::Game(int width, int height, string titleScreen)
{
	data->window.setVerticalSyncEnabled(true);
	data->window.create(VideoMode(width, height), titleScreen, Style::Close | Style::Titlebar);
	Vector2f vecteurDeplacement(0.0, 0.0);
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
	player->setWeapon(new Weapon("steamMan", 48, 48, "steamMan", 48, 48));
	player->setPosition(400, 400);
	player->setVelocity(Vector2f(20, 20));//exemple pour augmenter la vitesse
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
				cout << keyboardMap->getAttackKey() << endl;
			}
		}

		//currentState->updateEvent(event); //Gamestate
		if (event.type == Event::KeyPressed)
		{
			//cout << InputManager::getPressedKeyChar(event) << endl; //Player va prendre valeur de la cl�(getPressedKeyCode(event)) et d�finir son mouvement
			bool keyPressed = true;
			if (InputManager::getPressedKeyCode(event) == 36) //Si ESCAPE est appuy�, ferme le programme.
				data->window.close();
			//else
			//	movePlayer(event);
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
	//Testing GUI below - NOD, � effacer au futur
	/*tgui::Button::Ptr button = tgui::Button::create(); //Cr�e un bouton
	auto editBox = tgui::EditBox::create();
	data->gui.add(button, "monBouton"); //Ajoute le bouton au GUI principal
	data->gui.add(editBox, "monBox");
	editBox = data->gui.get<tgui::EditBox>("monBox");
	button = data->gui.get<tgui::Button>("monBouton"); //Relie le bouton au GUI principal
	button->setPosition(50, 50);
	button->setSize(250, 100);
	button->setText("This is a button");
	button->setTextSize(28);
	button->connect("Pressed", Game::signalHandler); //Relier le bouton � une fonction(doit �tre statique si on utilise la classe et non une instance), le premier param�tre est pr�d�finis
	button->connect("Pressed", [&]() { std::cout << "input2" << endl; }); //Exemple en lambda, notez que le bouton peut prendre deux fonctions
	tgui::ChildWindow::Ptr window = tgui::ChildWindow::create();
	data->gui.add(window, "window");
	window = data->gui.get<tgui::ChildWindow>("window");
	window->setResizable(true);
	tgui::ChildWindow::Ptr window2 = tgui::ChildWindow::create();
	window->add(window2, "window2");
	window = window2->get<tgui::ChildWindow>("window2");
	window2->setResizable(true);*/

	//Start menu

	currentGameState->changeGameState("MainMenu");

	//End of start menu

	//Start of settings menu


	//End of settings menu

	//End of testing GUI
	while (data->window.isOpen())
	{
		//boucle de jeu
		timeManager.update();
		//	currentState->updateInput();
		//	currentState->update();
			//render();
			//	currentState->updateInput();
			//	currentState->update();
		updateEvent();

		//currentState->updateInput();
		//currentState->update();
		//render(); //Animations
		//updateEvent();

		//Widgets v
		data->window.clear();
		data->gui.draw(); // Draw all widgets
		data->window.display();

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
		player->shoot(5);
		moved = false;		//evite d'entrer dans la boucle suivante fait pour les d�placement
	}						//si on enleve ca, les balles ne marcheront pas lorsque l'on shoot sans se d�placer

	while (keyPressed && moved)
	{
		data->window.pollEvent(event);
		if (event.type == Event::KeyReleased)
			keyPressed = false;
		player->move(deplacement);
		//player->render(data->window);
		render();
	}
}
