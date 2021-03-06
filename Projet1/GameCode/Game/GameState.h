#pragma once
#include "SFML/Window/Event.hpp"
#include "./Manager/AssetManager.h";
#include "./Manager/InputManager.h"
#include "./Manager/TimeManager.h"
#include "Input/KeyboardMap.h"
#include "GameDef.h"
#include "Game/Tycoon/MainTycoon.h"

class GameState
{
public:

	GameState(std::string state, std::shared_ptr<GameDef::GameData> data, Event* event, KeyboardMap* keyboardMap);

	void AfficherMenuStand(int valeurStand); // test alex

	enum State { Pause, Platformer, Tycoon, MainMenu, Settings };

	virtual void updateEvent(sf::Event event) {}
	virtual void updateInput() {}
	void update();
	void AfficherEvent(bool eventNow);
	virtual void draw() {}
	void ajouterArgent();
	void changeGameState(std::string state);

private:

	tgui::TextBox::Ptr TextPortefeuille = tgui::TextBox::create();
	tgui::Button::Ptr ButtonEvent = tgui::Button::create();
	MainTycoon* main = new MainTycoon();
	std::string state;
	std::shared_ptr<GameDef::GameData> data;
	Event* event;
	KeyboardMap* keyboardMap;	

};

