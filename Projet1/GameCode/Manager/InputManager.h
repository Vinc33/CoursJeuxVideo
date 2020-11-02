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

};

