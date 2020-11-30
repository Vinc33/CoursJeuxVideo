#pragma once
#include <SFML/System/Vector2.hpp>
#include "Entity/collidable.h"
#include <list>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity/BaseEntity.h"

class Map
{
	//Attributs
private :
	sf::Vector2f playerStart;
	std::vector<std::list<BaseEntity*>> mapObjects;//mur,ladder,etc
	std::vector<std::list<BaseEntity*>> mapEntities;//enemies
	int tiles[32][40];//has to be changed
	sf::Texture backgroundTexture;
	sf::Sprite background;

public:
	//Gets
	sf::Vector2f getPlayerStart();
	std::vector<std::list<BaseEntity*>> getMapEntities();
	std::vector<std::list<BaseEntity*>> getMapObjects();
	
	//Sets
	void setPlayerStart(float x, float y);
	void setBackground(std::string background);

	//Methode
public:
	Map();
	~Map();
	void loadMap(std::string filename);
	void render(sf::RenderWindow& window);
	void update();
	void addMapObject(BaseEntity* object);
	void addMapEntity(BaseEntity* entity);  
};

