#include "Utils.h"
#include <iostream>
#include <fstream>
#include <SFML/System/FileInputStream.hpp>


std::vector<std::string> Utils::split(std::string s, char delim)
{
	std::vector<std::string> elems;
	std::string current = "";
	for (char& c : s)
	{
		if (c != delim)
		{
			current += c;
		}
		else
		{
			elems.push_back(current);
			current = "";
		}
	}
	elems.push_back(current);
	return elems;
}
std::string Utils::readFromFile(const std::string& fileName)
{
	std::string inputFile = "";
	std::string line = "";
	std::ifstream fileStream;
	try
	{
		fileStream.open(fileName);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	if (fileStream.is_open())
	{
		while (getline(fileStream, line))
		{
			inputFile.append(line);
		}
		fileStream.close();
	}
	return inputFile;
}
