#pragma once
#include <SFML/System/Vector2.hpp>
#include "Entity/collidable.h"
#include <list>
#include <SFML/Graphics.hpp>

class Map
{
	//Attributs
private :
	sf::Vector2f playerStart;
	std::list<Collidable*> mapObjects;
	std::list<Collidable*> mapEntities;
	int tiles[32][40];//has to be changed
	sf::Texture backgroundTexture;
	sf::Sprite background;

public:
	//Gets
	sf::Vector2f getPlayerStart();
	
	//Sets
	void setPlayerStart(float x, float y);
	void setBackground(std::string background);

	//Methode
public:
	Map();
	void loadMap(std::string filename);
	void render(sf::RenderWindow& window);
	void update();
};

