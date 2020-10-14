#pragma once
#include "SFML/Window/Event.hpp"

class Game;

class GameState
{
public :
	GameState(Game& game);

	virtual void updateEvent(sf::Event event) {}
	virtual void updateInput() {}
	virtual void update() {}
	virtual void draw() {}


protected:
	Game* myGame;

};

