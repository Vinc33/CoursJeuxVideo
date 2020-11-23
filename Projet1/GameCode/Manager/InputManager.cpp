﻿#include "./Manager/InputManager.h"
#include "./Input/KeyboardMap.h"
#include <SFML/Window/Joystick.hpp>
#include <iostream>


InputManager::InputManager()
{

}

InputManager::~InputManager()
{
}

void InputManager::init()
{
	KeyboardMap keyboardMap();
}

void InputManager::update()
{
	sf::Joystick::update();
}

char InputManager::getPressedKeyChar(sf::Event event) //Retourner le char d'une touche
{
	if (event.key.code >= 0 && event.key.code <= 25)
		return (char)(event.key.code + 65); // Lettres de A - Z
	else if (event.key.code >= 26 && event.key.code <= 35)
		return (char)(event.key.code + 22); // Chiffres de 0 - 9
	else if (event.key.code == 57) // Barre espace
		return ' ';
	else if (event.key.code >= 71 && event.key.code <= 74)
	{
		switch (event.key.code)
		{
		case 71: return '<'; //Arrow left
			break;
		case 72: return '>'; //Arrow right
			break;
		case 73: return '^'; //Arrow up
			break;
		case 74: return '.'; //Arrow down
			break;
		}
	}
	else return '?';
}

sf::Keyboard::Key InputManager::getPressedKeyCode(sf::Event event) //Retourner la touche
{
	return static_cast<sf::Keyboard::Key>(event.key.code);
}

bool InputManager::isMouseButtonPressed(sf::Event event, sf::Mouse::Button button)
{
	if (event.mouseButton.button == button)
		return true;
	return false;
}

bool InputManager::isMouseWheelScrolled(sf::Event event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
		return true;
	return false;
}
bool InputManager::isMouseHover(sf::Event event) {
	if (event.type == sf::Event::MouseEntered)
		return true;
	return false;
}
bool InputManager::isMouseNotHover(sf::Event event) {
	if (event.type == sf::Event::MouseLeft)
		return true;
	return false;
}