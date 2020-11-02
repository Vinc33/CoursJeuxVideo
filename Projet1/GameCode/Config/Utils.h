#pragma once
#include <vector>
#include <string>

#include <SFML/System/Vector2.hpp>

class Utils {
public :
	static std::vector<std::string> split(std::string s, char delim);
	static std::string readFromFile(const std::string& fileName);
	inline static float dotProduct(sf::Vecteur v1, sf::Vecteur v2){ return v1.x * v2.x + v1.y * v2.y; }
};
	

