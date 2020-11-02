#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class BaseEntity
{
public:
	BaseEntity() {}
	BaseEntity(std::string spriteName);
	virtual ~BaseEntity() {}
			
	virtual void update() {}
	void render(sf::RenderTarget& target);

private:
	sf::Sprite sprite;
};

