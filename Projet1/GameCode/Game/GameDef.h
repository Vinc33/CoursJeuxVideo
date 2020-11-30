#pragma once
#include <string>
#include <TGUI/TGUI.hpp>

class GameDef
{
public:

	struct GameData
	{
		sf::RenderWindow window;
		tgui::Gui gui{ window };
	};

	typedef std::shared_ptr<GameData> GameDataRef;


	GameDef();

};