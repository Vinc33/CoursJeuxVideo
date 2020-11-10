#include "KeyboardMap.h"

KeyboardMap::KeyboardMap()
{

	keyUp = sf::Keyboard::W;
	keyDown = sf::Keyboard::S;
	keyLeft = sf::Keyboard::A;
	keyRight = sf::Keyboard::D;

	keyAttack = sf::Keyboard::X;
	keyJump = sf::Keyboard::Space;
	keySkill1 = sf::Keyboard::C;
	keySkill2 = sf::Keyboard::F;

}

// Constructeur utilisé pour changer les contrôles dans un menu de paramètres
KeyboardMap::KeyboardMap(myKey keyUp = myKey::W, myKey keyDown = myKey::S, myKey keyLeft = myKey::A, myKey keyRight = myKey::D, myKey keyAttack = myKey::X, myKey keyJump = myKey::Space, myKey keySkill1 = myKey::C, myKey keySkill2 = myKey::F)
{

	this->keyUp = keyUp;
	this->keyDown = keyDown;
	this->keyLeft = keyLeft;
	this->keyRight = keyRight;

	this->keyAttack = keyAttack;
	this->keyJump = keyJump;
	this->keySkill1 = keySkill1;
	this->keySkill2 = keySkill2;

}

#pragma region Getters

sf::Keyboard::Key KeyboardMap::getUpKey()
{
	return keyUp;
}

sf::Keyboard::Key KeyboardMap::getDownKey()
{
	return keyDown;
}

sf::Keyboard::Key KeyboardMap::getLeftKey()
{
	return keyLeft;
}

sf::Keyboard::Key KeyboardMap::getRightKey()
{
	return keyRight;
}

sf::Keyboard::Key KeyboardMap::getAttackKey()
{
	return keyAttack;
}

sf::Keyboard::Key KeyboardMap::getJumpKey()
{
	return keyJump;
}

sf::Keyboard::Key KeyboardMap::getSkill1Key()
{
	return keySkill1;
}

sf::Keyboard::Key KeyboardMap::getSkill2Key()
{
	return keySkill2;
}

#pragma endregion Getters
