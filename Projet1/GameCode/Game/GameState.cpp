#include "GameState.h"

GameState::GameState(std::string state, std::shared_ptr<GameDef::GameData> data, Event event, KeyboardMap* keyboardMap)
{
	this->state = state;
	this->data = data;
	this->event = event;
	this->keyboardMap = keyboardMap;
}

void GameState::changeGameState(std::string state)
{
	data->gui.removeAllWidgets();
	this->state = state;
	if (this->state == "MainMenu")
	{
#pragma region MainMenu
		tgui::BitmapButton::Ptr buttonStart = tgui::BitmapButton::create();
		data->gui.add(buttonStart, "StartButton");
		buttonStart = data->gui.get<tgui::BitmapButton>("StartButton");
		buttonStart->setSize(400, 100);
		buttonStart->setPosition(390, 50);
		buttonStart->setImage("GameCode/Images/Jouer.png");
		buttonStart->connect("Pressed", [&]() { GameState::changeGameState("Settings"); });
		tgui::BitmapButton::Ptr buttonSettings = tgui::BitmapButton::create();
		data->gui.add(buttonSettings, "SettingsButton");
		buttonSettings = data->gui.get<tgui::BitmapButton>("SettingsButton");
		buttonSettings->setSize(250, 100);
		buttonSettings->setPosition(390, 250);
		buttonSettings->setText("Paramètres");
		buttonSettings->connect("Pressed", [&]() { GameState::changeGameState("Settings"); });
		tgui::BitmapButton::Ptr buttonQuit = tgui::BitmapButton::create();
		data->gui.add(buttonQuit, "QuitterButton");
		buttonQuit = data->gui.get<tgui::BitmapButton>("QuitterButton");
		buttonQuit->setSize(450, 100);
		buttonQuit->setPosition(390, 450);
		buttonQuit->setImage("GameCode/Images/Quitter.png");
		buttonQuit->connect("Pressed", [&]() { data->window.close(); });
#pragma endregion MainMenu
	}
	else if (this->state == "Tycoon")
	{
#pragma region Tycoon
#pragma endregion Tycoon
	}
	else if (this->state == "Platformer")
	{
#pragma region Platformer
#pragma endregion Platformer
	}
	else if (this->state == "Pause")
	{
#pragma region Pause
#pragma endregion Pause
	}
	else if (this->state == "Settings")
	{
#pragma region Settings
		tgui::Panel::Ptr panelAtk = tgui::Panel::create();
		data->gui.add(panelAtk, "PanelAtk");
		panelAtk = data->gui.get<tgui::Panel>("PanelAtk");
		panelAtk->setSize(200, 100);
		panelAtk->setPosition(240, 100);
		tgui::Label::Ptr labelEditBoxAtk = tgui::Label::create();
		panelAtk->add(labelEditBoxAtk, "LabelEditBoxAtk");
		labelEditBoxAtk = panelAtk->get<tgui::Label>("LabelEditBoxAtk");
		labelEditBoxAtk->setText("Attaque:");
		labelEditBoxAtk->setTextSize(20);
		labelEditBoxAtk->setSize(132, 100);
		labelEditBoxAtk->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxAtk->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxAtk = tgui::EditBox::create();
		panelAtk->add(editBoxAtk, "EditBoxAttaque");
		editBoxAtk = panelAtk->get<tgui::EditBox>("EditBoxAttaque");
		editBoxAtk->setSize(68, 86);
		editBoxAtk->setPosition(120, 7);
		editBoxAtk->setTextSize(68);
		editBoxAtk->setDefaultText("J");
		editBoxAtk->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxAtk->setMaximumCharacters(1);
		editBoxAtk->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setAttackKey(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelJump = tgui::Panel::create();
		data->gui.add(panelJump, "PanelJump");
		panelJump = data->gui.get<tgui::Panel>("PanelJump");
		panelJump->setSize(200, 100);
		panelJump->setPosition(640, 100);
		tgui::Label::Ptr labelEditBoxJump = tgui::Label::create();
		panelJump->add(labelEditBoxJump, "LabelEditBoxJump");
		labelEditBoxJump = panelJump->get<tgui::Label>("LabelEditBoxJump");
		labelEditBoxJump->setText("Jump:");
		labelEditBoxJump->setTextSize(20);
		labelEditBoxJump->setSize(132, 100);
		labelEditBoxJump->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxJump->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxJump = tgui::EditBox::create();
		panelJump->add(editBoxJump, "EditBoxJump");
		editBoxJump = panelJump->get<tgui::EditBox>("EditBoxJump");
		editBoxJump->setSize(68, 86);
		editBoxJump->setPosition(120, 7);
		editBoxJump->setTextSize(68);
		editBoxJump->setDefaultText(" ");
		editBoxJump->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxJump->setMaximumCharacters(1);
		editBoxJump->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setJumpKey(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelSkill1 = tgui::Panel::create();
		data->gui.add(panelSkill1, "PanelSkill1");
		panelSkill1 = data->gui.get<tgui::Panel>("PanelSkill1");
		panelSkill1->setSize(200, 100);
		panelSkill1->setPosition(240, 300);
		tgui::Label::Ptr labelEditBoxSkill1 = tgui::Label::create();
		panelSkill1->add(labelEditBoxSkill1, "LabelEditBoxSkill1");
		labelEditBoxSkill1 = panelSkill1->get<tgui::Label>("LabelEditBoxSkill1");
		labelEditBoxSkill1->setText("Skill1:");
		labelEditBoxSkill1->setTextSize(20);
		labelEditBoxSkill1->setSize(132, 100);
		labelEditBoxSkill1->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxSkill1->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxSkill1 = tgui::EditBox::create();
		panelSkill1->add(editBoxSkill1, "EditBoxSkill1");
		editBoxSkill1 = panelSkill1->get<tgui::EditBox>("EditBoxSkill1");
		editBoxSkill1->setSize(68, 86);
		editBoxSkill1->setPosition(120, 7);
		editBoxSkill1->setTextSize(68);
		editBoxSkill1->setDefaultText("C");
		editBoxSkill1->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxSkill1->setMaximumCharacters(1);
		editBoxSkill1->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setSkill1Key(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelSkill2 = tgui::Panel::create();
		data->gui.add(panelSkill2, "PanelSkill2");
		panelSkill2 = data->gui.get<tgui::Panel>("PanelSkill2");
		panelSkill2->setSize(200, 100);
		panelSkill2->setPosition(640, 300);
		tgui::Label::Ptr labelEditBoxSkill2 = tgui::Label::create();
		panelSkill2->add(labelEditBoxSkill2, "LabelEditBoxSkill2");
		labelEditBoxSkill2 = panelSkill2->get<tgui::Label>("LabelEditBoxSkill2");
		labelEditBoxSkill2->setText("Skill2:");
		labelEditBoxSkill2->setTextSize(20);
		labelEditBoxSkill2->setSize(132, 100);
		labelEditBoxSkill2->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxSkill2->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxSkill2 = tgui::EditBox::create();
		panelSkill2->add(editBoxSkill2, "EditBoxSkill2");
		editBoxSkill2 = panelSkill2->get<tgui::EditBox>("EditBoxSkill2");
		editBoxSkill2->setSize(68, 86);
		editBoxSkill2->setPosition(120, 7);
		editBoxSkill2->setTextSize(68);
		editBoxSkill2->setDefaultText("F");
		editBoxSkill2->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxSkill2->setMaximumCharacters(1);
		editBoxSkill2->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setSkill2Key(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelUp = tgui::Panel::create();
		data->gui.add(panelUp, "PanelUp");
		panelUp = data->gui.get<tgui::Panel>("PanelUp");
		panelUp->setSize(200, 100);
		panelUp->setPosition(240, 500);
		tgui::Label::Ptr labelEditBoxUp = tgui::Label::create();
		panelUp->add(labelEditBoxUp, "LabelEditBoxUp");
		labelEditBoxUp = panelUp->get<tgui::Label>("LabelEditBoxUp");
		labelEditBoxUp->setText("Key Up:");
		labelEditBoxUp->setTextSize(20);
		labelEditBoxUp->setSize(132, 100);
		labelEditBoxUp->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxUp->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxUp = tgui::EditBox::create();
		panelUp->add(editBoxUp, "EditBoxUp");
		editBoxUp = panelUp->get<tgui::EditBox>("EditBoxUp");
		editBoxUp->setSize(68, 86);
		editBoxUp->setPosition(120, 7);
		editBoxUp->setTextSize(68);
		editBoxUp->setDefaultText("w");
		editBoxUp->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxUp->setMaximumCharacters(1);
		editBoxUp->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setUpKey(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelDown = tgui::Panel::create();
		data->gui.add(panelDown, "PanelDown");
		panelDown = data->gui.get<tgui::Panel>("PanelDown");
		panelDown->setSize(200, 100);
		panelDown->setPosition(640, 500);
		tgui::Label::Ptr labelEditBoxDown = tgui::Label::create();
		panelDown->add(labelEditBoxDown, "LabelEditBoxDown");
		labelEditBoxDown = panelDown->get<tgui::Label>("LabelEditBoxDown");
		labelEditBoxDown->setText("Key Down:");
		labelEditBoxDown->setTextSize(20);
		labelEditBoxDown->setSize(132, 100);
		labelEditBoxDown->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxDown->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxDown = tgui::EditBox::create();
		panelDown->add(editBoxDown, "EditBoxDown");
		editBoxDown = panelDown->get<tgui::EditBox>("EditBoxDown");
		editBoxDown->setSize(68, 86);
		editBoxDown->setPosition(120, 7);
		editBoxDown->setTextSize(68);
		editBoxDown->setDefaultText("S");
		editBoxDown->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxDown->setMaximumCharacters(1);
		editBoxDown->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setDownKey(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelLeft = tgui::Panel::create();
		data->gui.add(panelLeft, "PanelLeft");
		panelLeft = data->gui.get<tgui::Panel>("PanelLeft");
		panelLeft->setSize(200, 100);
		panelLeft->setPosition(240, 700);
		tgui::Label::Ptr labelEditBoxLeft = tgui::Label::create();
		panelLeft->add(labelEditBoxLeft, "LabelEditBoxLeft");
		labelEditBoxLeft = panelLeft->get<tgui::Label>("LabelEditBoxLeft");
		labelEditBoxLeft->setText("Key Left:");
		labelEditBoxLeft->setTextSize(20);
		labelEditBoxLeft->setSize(132, 100);
		labelEditBoxLeft->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxLeft->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxLeft = tgui::EditBox::create();
		panelLeft->add(editBoxLeft, "EditBoxLeft");
		editBoxLeft = panelLeft->get<tgui::EditBox>("EditBoxLeft");
		editBoxLeft->setSize(68, 86);
		editBoxLeft->setPosition(120, 7);
		editBoxLeft->setTextSize(68);
		editBoxLeft->setDefaultText("A");
		editBoxLeft->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxLeft->setMaximumCharacters(1);
		editBoxLeft->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setLeftKey(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Panel::Ptr panelRight = tgui::Panel::create();
		data->gui.add(panelRight, "PanelRight");
		panelRight = data->gui.get<tgui::Panel>("PanelRight");
		panelRight->setSize(200, 100);
		panelRight->setPosition(640, 700);
		tgui::Label::Ptr labelEditBoxRight = tgui::Label::create();
		panelRight->add(labelEditBoxRight, "LabelEditBoxRight");
		labelEditBoxRight = panelRight->get<tgui::Label>("LabelEditBoxRight");
		labelEditBoxRight->setText("Key Right:");
		labelEditBoxRight->setTextSize(20);
		labelEditBoxRight->setSize(132, 100);
		labelEditBoxRight->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);
		labelEditBoxRight->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
		tgui::EditBox::Ptr editBoxRight = tgui::EditBox::create();
		panelRight->add(editBoxRight, "EditBoxRight");
		editBoxRight = panelRight->get<tgui::EditBox>("EditBoxRight");
		editBoxRight->setSize(68, 86);
		editBoxRight->setPosition(120, 7);
		editBoxRight->setTextSize(68);
		editBoxRight->setDefaultText("D");
		editBoxRight->setAlignment(tgui::EditBox::Alignment::Center);
		editBoxRight->setMaximumCharacters(1);
		editBoxRight->connect("TextChanged", [&]() {
			if (InputManager::validateInput(event))
				keyboardMap->setRightKey(InputManager::getPressedKeyCodeInInput(event)); });

		tgui::Button::Ptr buttonBack = tgui::Button::create();
		data->gui.add(buttonBack, "ButtonBack");
		buttonBack = data->gui.get<tgui::Button>("ButtonBack");
		buttonBack->setSize(200, 100);
		buttonBack->setPosition(440, 900);
		buttonBack->setTextSize(68);
		buttonBack->setText("Back");
		buttonBack->connect("Pressed", [&]() { GameState::changeGameState("MainMenu"); });
#pragma endregion Settings
	}
}

