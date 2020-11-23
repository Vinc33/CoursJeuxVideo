#include "Map.h"
#include <iostream>

Map::Map()
{
	for (int rows = 0; rows < sizeof(tiles)/sizeof(tiles[0]); rows++)
		for (int cols = 0; cols < sizeof(tiles[0])/sizeof(tiles[0][0]); cols++)
			tiles[rows][cols] = 0;
	playerStart = sf::Vector2f(0, 0);
}

void Map::loadMap(std::string filename)
{
	//code here;
}

void Map::render(sf::RenderWindow& window)
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		(*it)->render(window);
	for (auto it = mapEntities.begin(); it != mapEntities.end(); it++)
		(*it)->render(window);
	window.draw(background);
}

void Map::update()
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		(*it)->update();
	for (auto it = mapEntities.begin(); it != mapEntities.end(); it++)
		(*it)->update();
}

#pragma region Gets/sets
//Gets
sf::Vector2f Map::getPlayerStart()
{
	return playerStart;
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
