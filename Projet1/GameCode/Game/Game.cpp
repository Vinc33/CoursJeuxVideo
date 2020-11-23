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
		player = new Player("steamMan", 48, 48,24,40);
		player->setWeapon(new Weapon("steamMan", 48, 48, "steamMan", 48, 48));
		player->setPosition(400, 400);
		player->setVelocity(Vector2f(20, 20));//exemple pour augmenter la vitesse

		//testing
		playerTest = new Player("steamMan", 48, 48, 24, 40);
		playerTest->setWeapon(new Weapon("steamMan", 48, 48, "steamMan", 48, 48));
		playerTest->setPosition(200, 400);
		map = new Map();
		
		keyboardMap = new KeyboardMap();
		

		//Test Sulli
		tgui::ChildWindow::Ptr window = tgui::ChildWindow::create();
		data->gui.add(window, "window");
		window = data->gui.get<tgui::ChildWindow>("window");
		window->setKeepInParent(true);
		window->setResizable(true);
		window->setSize(400,600);
		
		//crée un titre pour la fenetre
		window->setTitle("Robot Ménarger");
		window->setTextSize(15);
		//creation du bouton Balayage rapide
		tgui::Button::Ptr button2 = tgui::Button::create(); //Crée un Bouton
		window->add(button2, "monBouton2");
		button2 = window->get<tgui::Button>("monBouton2"); //Relie le bouton au GUI principal
		button2->setSize(200, 50);
		button2->setPosition(100,50);
		button2->setText("Balayage Rapide");
		button2->setTextSize(15);
		//création bouton detecteur
		tgui::Button::Ptr button3 = tgui::Button::create(); //Crée un Bouton
		window->add(button3, "monBouton3");
		button3 = window->get<tgui::Button>("monBouton3"); //Relie le bouton au GUI principal
		button3->setSize(200, 50);
		button3->setPosition(100, 125);
		button3->setText("Detecteur de MPA");
		button2->setTextSize(15);
		//création bouton balais
		tgui::Button::Ptr button4 = tgui::Button::create(); //Crée un Bouton
		window->add(button4, "monBouton4");
		button4 = window->get<tgui::Button>("monBouton4"); //Relie le bouton au GUI principal
		button4->setSize(200, 50);
		button4->setPosition(100, 200);
		button4->setText("Balais en Vibranium");
		button4->setTextSize(15);
		//création bouton CPU
		tgui::Button::Ptr button5 = tgui::Button::create(); //Crée un Bouton
		window->add(button5, "monBouton5");
		button5 = window->get<tgui::Button>("monBouton5"); //Relie le bouton au GUI principal
		button5->setSize(200, 50);
		button5->setPosition(100, 275);
		button5->setText("CPU Amélioré");
		button5->setTextSize(15);
		//création bouton Aspirateur
		tgui::Button::Ptr button6 = tgui::Button::create(); //Crée un Bouton
		window->add(button6, "monBouton6");
		button6 = window->get<tgui::Button>("monBouton6"); //Relie le bouton au GUI principal
		button6->setSize(200, 50);
		button6->setPosition(100, 350);
		button6->setText("Aspirateur Quantique");
		button6->setTextSize(15);
		//création text
		tgui::TextBox::Ptr text = tgui::TextBox::create();
		window->add(text, "Text");
		text = window->get<tgui::TextBox>("Text");
		text->addText("\n Argent actuel : \n \n \n ");
		text->addText("Requis : \n ");
		text->setReadOnly(true);
		text->setFocusable(false);
		text->setPosition(100, 425);
		text->setSize(200, 110);
		//tgui::Text text1;
		//window->add(text1, "monText");
		//text1 = window->get<tgui::Text>("monText");
		//text1.setString("Requis : ");
		//text1.setPosition(75, 475);
		//text1.setCharacterSize(15);
		
		//création bouton achat
		tgui::Button::Ptr button7 = tgui::Button::create(); //Crée un Bouton
		window->add(button7, "monBouton7");
		button7 = window->get<tgui::Button>("monBouton7"); //Relie le bouton au GUI principal
		button7->setSize(200, 50);
		button7->setPosition(100,550);
		button7->setText("Quittez");
		button7->setTextSize(15);
		
		//crée une classe MenuManager
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
			if (InputManager::isMouseHover(event)) {
				std::cout << "Vous êtes entrez dans l'objet" << std::endl;
			}
			if (InputManager::isMouseNotHover(event)) {
				std::cout << "Vous avez quitter l'objet" << std::endl;
			}

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
		//tgui::Button::Ptr button = tgui::Button::create(); //Crée un bouton
		//auto editBox = tgui::EditBox::create();
		//data->gui.add(button, "monBouton"); //Ajoute le bouton au GUI principal
		//data->gui.add(editBox, "monBox"); 
		//editBox = data->gui.get<tgui::EditBox>("monBox");
		//button = data->gui.get<tgui::Button>("monBouton"); //Relie le bouton au GUI principal
		//button->setPosition(50, 50);
		//button->setSize(250, 100);
		//button->setText("This is a button");
		//button->setTextSize(28);
		//button->connect("Pressed", Game::signalHandler); //Relier le bouton à une fonction(doit être statique si on utilise la classe et non une instance), le premier paramètre est prédéfinis
		//button->connect("Pressed", [&]() { std::cout << "input2" << endl; }); //Exemple en lambda, notez que le bouton peut prendre deux fonctions
		

		



		//End of testing GUI

		map->updateObjects();
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
		map->render(data->window);

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