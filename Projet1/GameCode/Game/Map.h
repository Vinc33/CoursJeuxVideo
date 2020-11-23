#pragma once
#include <SFML/System/Vector2.hpp>
#include "Entity/collidable.h"
#include <list>

class Map
{
	//Attributs
private :
	sf::Vector2f playerStart;
	std::list<Collidable*> mapObjects;
	int tiles[30][30];

	//Gets
	sf::Vector2f getPlayerStart();
	
	//Sets
	void setPlayerStart(float x, float y);

	//Methode
public:
	Map();
	void loadMap(std::string filename);
	void render(sf::RenderWindow& window);
	void updateObjects();
};

