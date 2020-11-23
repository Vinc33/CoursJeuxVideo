#include "Map.h"

Map::Map()
{
	for (int rows = 0; rows < sizeof(tiles); rows++)
		for (int cols = 0; cols < sizeof(tiles[0]); cols++)
			tiles[rows][cols] = 0;
	playerStart = sf::Vector2f(0, 0);
}

void Map::loadMap(std::string filename)
{
	//code here;
}

void Map::render(sf::RenderWindow &window)
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		//(*it)->render();
		;
}

void Map::updateObjects()
{
	for (auto it = mapObjects.begin(); it != mapObjects.end(); it++)
		//(*it)->update();
		;
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
#pragma endregion
