#pragma once
#include "./Manager/TimeManager.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Event.hpp"
#include <vector>

using namespace std;

class InputManager
{
public:
	InputManager();
	~InputManager();

	static void init();

	static void update();

	static char getPressedKeyChar(sf::Event event); //Retourne le charactère en char des lettres A-Z et numéros 0-9(pas numpad)[Affichage]

	static sf::Keyboard::Key getPressedKeyCode(sf::Event event); //Retourne la clé des lettres A-Z et numéros 0-9(pas numpad)[Logique]

	static bool isMouseButtonPressed(sf::Event event, sf::Mouse::Button button); //Retourne true ou false si le bouton demandé est appuyé

	static bool isMouseWheelScrolled(sf::Event event); //Retourne true ou false si la roue de la souris a été scrolled

	static bool isMouseHover(sf::Event event); //Retrourne true ou false si la souris passe sur l'objet

	static bool isMouseNotHover(sf::Event event); //Retrourne true ou false si la souris quitte l'objet

};

