#include "GameState.h"

GameState::GameState(std::string state, std::shared_ptr<GameDef::GameData> data, Event* event, KeyboardMap* keyboardMap)
{
	this->state = state;
	this->data = data;
	this->event = event;
	this->keyboardMap = keyboardMap;
}

void GameState::update()
{
	;
}

void GameState::changeGameState(std::string state)
{
	data->gui.removeAllWidgets();
	this->state = state;
	if (this->state == "MainMenu")
	{
#pragma region MainMenu
		tgui::BitmapButton::Ptr mainTitle = tgui::BitmapButton::create();
		data->gui.add(mainTitle, "MainTitle");
		mainTitle = data->gui.get<tgui::BitmapButton>("MainTitle");
		mainTitle->setEnabled(false);
		mainTitle->setSize(800, 102);
		mainTitle->setPosition(100, 100);
		mainTitle->setImage("GameCode/Images/CyberRun.png");
		tgui::BitmapButton::Ptr buttonStart = tgui::BitmapButton::create();
		data->gui.add(buttonStart, "StartButton");
		buttonStart = data->gui.get<tgui::BitmapButton>("StartButton");
		buttonStart->setSize(345, 100);
		buttonStart->setPosition(350, 300);
		buttonStart->setImage("GameCode/Images/Jouer.png");
		buttonStart->connect("Pressed", [&]() { GameState::changeGameState("Tycoon"); });
		tgui::BitmapButton::Ptr buttonSettings = tgui::BitmapButton::create();
		data->gui.add(buttonSettings, "SettingsButton");
		buttonSettings = data->gui.get<tgui::BitmapButton>("SettingsButton");
		buttonSettings->setSize(200, 114);
		buttonSettings->setPosition(800, 886);
		buttonSettings->setImage("GameCode/Images/engrenages.png");
		buttonSettings->connect("Pressed", [&]() { GameState::changeGameState("Settings"); });
		tgui::BitmapButton::Ptr buttonQuit = tgui::BitmapButton::create();
		data->gui.add(buttonQuit, "QuitterButton");
		buttonQuit = data->gui.get<tgui::BitmapButton>("QuitterButton");
		buttonQuit->setSize(450, 100);
		buttonQuit->setPosition(300, 500);
		buttonQuit->setImage("GameCode/Images/Quitter.png");
		buttonQuit->connect("Pressed", [&]() { data->window.close(); });
#pragma endregion MainMenu
	}
	else if (this->state == "Tycoon")
	{
#pragma region Tycoon
		main->init();
		int value = 0;
		tgui::ChildWindow::Ptr window = tgui::ChildWindow::create();
		data->gui.add(window, "window");
		window = data->gui.get<tgui::ChildWindow>("window");
		window->setKeepInParent(true);
		window->setResizable(true);
		window->setSize(400, 600);

		//cr�e un titre pour la fenetre
		window->setTitle("Robot M�narger");
		window->setTextSize(15);
		//creation du bouton Balayage rapide;
		tgui::Button::Ptr button2 = tgui::Button::create(); //Cr�e un Bouton
		window->add(button2, "monBouton2");
		button2 = window->get<tgui::Button>("monBouton2"); //Relie le bouton au GUI principal
		button2->setSize(200, 50);
		button2->setPosition(100, 50);
		button2->setText("Balayage Rapide");
		button2->setTextSize(15);
		button2->setEnabled(main->standMenager[1]->getAcheter());
		button2->connect("Pressed", [&]() { value = 0; });
		//cr�ation bouton detecteur
		tgui::Button::Ptr button3 = tgui::Button::create(); //Cr�e un Bouton
		window->add(button3, "monBouton3");
		button3 = window->get<tgui::Button>("monBouton3"); //Relie le bouton au GUI principal
		button3->setSize(200, 50);
		button3->setPosition(100, 125);
		button3->setText("Detecteur de MPA");
		button3->setTextSize(15);
		button3->connect("Pressed", [&]() { value = 1; });
		//cr�ation bouton achat
		tgui::Button::Ptr button7 = tgui::Button::create(); //Cr�e un Bouton
		window->add(button7, "monBouton7");
		button7 = window->get<tgui::Button>("monBouton7"); //Relie le bouton au GUI principal
		button7->setSize(200, 50);
		button7->setPosition(100, 550);
		button7->setText("achetez");
		button7->setTextSize(15);
		button7->connect("Pressed", [&]() {main->ameliorer(value); });
		//cr�ation bouton balais
		tgui::Button::Ptr button4 = tgui::Button::create(); //Cr�e un Bouton
		window->add(button4, "monBouton4");
		button4 = window->get<tgui::Button>("monBouton4"); //Relie le bouton au GUI principal
		button4->setSize(200, 50);
		button4->setPosition(100, 200);
		button4->setText("Balais en Vibranium");
		button4->setTextSize(15);
		button4->connect("Pressed", [&]() { value = 2; });
		//cr�ation bouton CPU
		tgui::Button::Ptr button5 = tgui::Button::create(); //Cr�e un Bouton
		window->add(button5, "monBouton5");
		button5 = window->get<tgui::Button>("monBouton5"); //Relie le bouton au GUI principal
		button5->setSize(200, 50);
		button5->setPosition(100, 275);
		button5->setText("CPU Am�lior�");
		button5->setTextSize(15);
		button5->connect("Pressed", [&]() { value = 3; });
		//cr�ation bouton Aspirateur
		tgui::Button::Ptr button6 = tgui::Button::create(); //Cr�e un Bouton
		window->add(button6, "monBouton6");
		button6 = window->get<tgui::Button>("monBouton6"); //Relie le bouton au GUI principal
		button6->setSize(200, 50);
		button6->setPosition(100, 350);
		button6->setText("Aspirateur Quantique");
		button6->setTextSize(15);
		button6->connect("Pressed", [&]() { value = 4; });
		//cr�ation text
		tgui::TextBox::Ptr text = tgui::TextBox::create();
		window->add(text, "Text");
		text = window->get<tgui::TextBox>("Text");
		text->addText(main->AfficherUsine(value));
		text->setReadOnly(true);
		text->setFocusable(false);
		text->setPosition(100, 425);
		text->setSize(200, 110);
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
			if (InputManager::validateInput(*event))
				keyboardMap->setAttackKey(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setJumpKey(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setSkill1Key(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setSkill2Key(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setUpKey(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setDownKey(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setLeftKey(InputManager::getPressedKeyCodeInInput(*event)); });

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
			if (InputManager::validateInput(*event))
				keyboardMap->setRightKey(InputManager::getPressedKeyCodeInInput(*event)); });

		tgui::Button::Ptr buttonBack = tgui::Button::create();
		data->gui.add(buttonBack, "ButtonBack");
		buttonBack = data->gui.get<tgui::Button>("ButtonBack");
		buttonBack->setSize(200, 100);
		buttonBack->setPosition(440, 850);
		buttonBack->setTextSize(68);
		buttonBack->setText("Back");
		buttonBack->connect("Pressed", [&]() { GameState::changeGameState("MainMenu"); });
#pragma endregion Settings
	}
}

