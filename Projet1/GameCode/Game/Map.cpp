#include "Map.h"
#include <iostream>

Map::Map()
{
	list<BaseEntity*> emptyList;
	for (int rows = 0; rows < sizeof(tiles)/sizeof(tiles[0]); rows++)
		for (int cols = 0; cols < sizeof(tiles[0])/sizeof(tiles[0][0]); cols++)
			tiles[rows][cols] = 0;
	for (int i = 0; i < Consts::NBPALIERSMAX; i++)
		mapEntities.push_back(emptyList);
	playerStart = sf::Vector2f(0, 0);
}

Map::~Map()
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
			delete *it2;
	for (auto it = mapEntities.begin(); it != mapEntities.end(); it++)
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
			delete *it2;
}

void Map::loadMap(std::string filename)
{
	//code here;
}

void Map::render(sf::RenderWindow& window)
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
			(*it2)->render(window);
	for (auto it = mapEntities.begin(); it != mapEntities.end(); it++)
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
			(*it2)->render(window);
	window.draw(background);
}

void Map::update()
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
		{
			int oldPalier = (*it2)->getPalier();
			if ((*it2)->update() == 1)
			{
				mapObjects[(*it2)->getPalier()].push_back(*it2);
				mapObjects[oldPalier].remove(*it2);
			}
		}
	for (auto it = mapEntities.begin(); it != mapEntities.end(); it++)
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
		{
			int oldPalier = (*it2)->getPalier();
			if ((*it2)->update() == 1)
			{
				mapEntities[(*it2)->getPalier()].push_back(*it2);
				mapEntities[oldPalier].remove(*it2);
			}
		}
}

void Map::addMapEntity(BaseEntity* entity)
{ 
	mapEntities[entity->getPalier()].push_back(entity);
}

void Map::addMapObject(BaseEntity* object)
{
	mapObjects[object->getPalier()].push_back(object);
}

#pragma region Gets/sets
//Gets
sf::Vector2f Map::getPlayerStart()
{
	return playerStart;
}

std::vector<std::list<BaseEntity*>> Map::getMapEntities()
{
	return mapEntities;
}

std::vector<std::list<BaseEntity*>> Map::getMapObjects()
{
	return mapObjects;
}

//Sets
void Map::setPlayerStart(float x, float y)
{
	playerStart.x = x;
	playerStart.y = y;
}

void Map::setBackground(std::string background)
{
	if (!backgroundTexture.loadFromFile(background))
		;
	else
		this->background.setTexture(backgroundTexture);
}
#pragma endregion
