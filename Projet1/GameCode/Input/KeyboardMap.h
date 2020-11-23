#pragma once
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#define myKey sf::Keyboard::Key


class KeyboardMap
{
public:

	KeyboardMap();
	KeyboardMap(myKey keyUp, myKey keyDown, myKey keyLeft, myKey keyRight, myKey keyAttack, myKey keyJump, myKey keySkill1, myKey keySkill2);
	~KeyboardMap();

	sf::Keyboard::Key getUpKey();
	sf::Keyboard::Key getDownKey();
	sf::Keyboard::Key getLeftKey();
	sf::Keyboard::Key getRightKey();

	sf::Keyboard::Key getAttackKey();
	sf::Keyboard::Key getJumpKey();
	sf::Keyboard::Key getSkill1Key();
	sf::Keyboard::Key getSkill2Key();

private:

	sf::Keyboard::Key keyUp;
	sf::Keyboard::Key keyDown;
	sf::Keyboard::Key keyLeft;
	sf::Keyboard::Key keyRight;

	sf::Keyboard::Key keyAttack;
	sf::Keyboard::Key keyJump;
	sf::Keyboard::Key keySkill1;
	sf::Keyboard::Key keySkill2;

};

