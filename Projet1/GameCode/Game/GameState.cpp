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
		tgui::ChildWindow::Ptr menuStandMenager = tgui::ChildWindow::create();
		data->gui.add(menuStandMenager, "menuStandMenager");
		menuStandMenager = data->gui.get<tgui::ChildWindow>("menuStandMenager");
		menuStandMenager->setKeepInParent(true);
		menuStandMenager->setResizable(true);
		menuStandMenager->setSize(400, 600);

		//crée un titre pour la fenetre
		menuStandMenager->setTitle("Robot Ménarger");
		menuStandMenager->setTextSize(15);
		//creation du bouton Balayage rapide;
		tgui::Button::Ptr balayageRapide = tgui::Button::create(); //Crée un Bouton
		menuStandMenager->add(balayageRapide, "monBouton2");
		balayageRapide = menuStandMenager->get<tgui::Button>("monBouton2"); //Relie le bouton au GUI principal
		balayageRapide->setSize(200, 50);
		balayageRapide->setPosition(100, 50);
		balayageRapide->setText("Balayage Rapide");
		balayageRapide->setTextSize(15);
		balayageRapide->setEnabled(main->standMenager[1]->getAcheter());
		balayageRapide->connect("Pressed", [&]() { value = 0; });
		//création bouton detecteur
		tgui::Button::Ptr detecteurDeMPA = tgui::Button::create(); //Crée un Bouton
		menuStandMenager->add(detecteurDeMPA, "monBouton3");
		detecteurDeMPA = menuStandMenager->get<tgui::Button>("monBouton3"); //Relie le bouton au GUI principal
		detecteurDeMPA->setSize(200, 50);
		detecteurDeMPA->setPosition(100, 125);
		detecteurDeMPA->setText("Detecteur de MPA");
		detecteurDeMPA->setTextSize(15);
		detecteurDeMPA->connect("Pressed", [&]() { value = 1; });
		//création bouton achat
		tgui::Button::Ptr acheterRobotMenage = tgui::Button::create(); //Crée un Bouton
		menuStandMenager->add(acheterRobotMenage, "monBouton7");
		acheterRobotMenage = menuStandMenager->get<tgui::Button>("monBouton7"); //Relie le bouton au GUI principal
		acheterRobotMenage->setSize(200, 50);
		acheterRobotMenage->setPosition(100, 550);
		acheterRobotMenage->setText("achetez");
		acheterRobotMenage->setTextSize(15);
		acheterRobotMenage->connect("Pressed", [&]() {main->ameliorer(value); });
		//création bouton balais
		tgui::Button::Ptr balaisEnVibranium = tgui::Button::create(); //Crée un Bouton
		menuStandMenager->add(balaisEnVibranium, "monBouton4");
		balaisEnVibranium = menuStandMenager->get<tgui::Button>("monBouton4"); //Relie le bouton au GUI principal
		balaisEnVibranium->setSize(200, 50);
		balaisEnVibranium->setPosition(100, 200);
		balaisEnVibranium->setText("Balais en Vibranium");
		balaisEnVibranium->setTextSize(15);
		balaisEnVibranium->connect("Pressed", [&]() { value = 2; });
		//création bouton CPU
		tgui::Button::Ptr CpuRobotMenage = tgui::Button::create(); //Crée un Bouton
		menuStandMenager->add(CpuRobotMenage, "monBouton5");
		CpuRobotMenage = menuStandMenager->get<tgui::Button>("monBouton5"); //Relie le bouton au GUI principal
		CpuRobotMenage->setSize(200, 50);
		CpuRobotMenage->setPosition(100, 275);
		CpuRobotMenage->setText("CPU Amélioré");
		CpuRobotMenage->setTextSize(15);
		CpuRobotMenage->connect("Pressed", [&]() { value = 3; });
		//création bouton Aspirateur
		tgui::Button::Ptr aspirateurQuantique = tgui::Button::create(); //Crée un Bouton
		menuStandMenager->add(aspirateurQuantique, "monBouton6");
		aspirateurQuantique = menuStandMenager->get<tgui::Button>("monBouton6"); //Relie le bouton au GUI principal
		aspirateurQuantique->setSize(200, 50);
		aspirateurQuantique->setPosition(100, 350);
		aspirateurQuantique->setText("Aspirateur Quantique");
		aspirateurQuantique->setTextSize(15);
		aspirateurQuantique->connect("Pressed", [&]() { value = 4; });
		//création text
		tgui::TextBox::Ptr textMenager = tgui::TextBox::create();
		menuStandMenager->add(textMenager, "textMenager");
		textMenager = menuStandMenager->get<tgui::TextBox>("textMenager");
		textMenager->addText(main->AfficherUsine(value));
		textMenager->setReadOnly(true);
		textMenager->setFocusable(false);
		textMenager->setPosition(100, 425);
		textMenager->setSize(200, 110);

		//crée un titre pour la fenetre
		main->init();
		int value = 0;
		tgui::ChildWindow::Ptr menuStandSexuel = tgui::ChildWindow::create();
		data->gui.add(menuStandSexuel, "menuStandSexuel");
		menuStandSexuel = data->gui.get<tgui::ChildWindow>("menuStandSexuel");
		menuStandSexuel->setKeepInParent(true);
		menuStandMenager->setResizable(true);
		menuStandMenager->setSize(400, 600);
		menuStandSexuel->setTitle("Cyborg Sexuel");
		menuStandSexuel->setTextSize(15);
		//creation du bouton Vibrateur en Vibranium
		tgui::Button::Ptr vibrateurEnVibranium = tgui::Button::create(); //Crée un Bouton
		menuStandSexuel->add(vibrateurEnVibranium, "vibrateur");
		vibrateurEnVibranium = menuStandSexuel->get<tgui::Button>("vibrateur"); //Relie le bouton au GUI principal
		vibrateurEnVibranium->setSize(200, 50);
		vibrateurEnVibranium->setPosition(100, 50);
		vibrateurEnVibranium->setText("Vibrateur en Vibranium");
		vibrateurEnVibranium->setTextSize(15);
		//création bouton Electric Nips
		tgui::Button::Ptr electricNips = tgui::Button::create(); //Crée un Bouton
		menuStandSexuel->add(electricNips, "electric");
		electricNips = menuStandSexuel->get<tgui::Button>("electric"); //Relie le bouton au GUI principal
		electricNips->setSize(200, 50);
		electricNips->setPosition(100, 125);
		electricNips->setText("Electric Nips");
		electricNips->setTextSize(15);
		//création bouton Spank-Machine
		tgui::Button::Ptr spankMachine = tgui::Button::create(); //Crée un Bouton
		menuStandSexuel->add(spankMachine, "spank");
		spankMachine = menuStandSexuel->get<tgui::Button>("spank"); //Relie le bouton au GUI principal
		spankMachine->setSize(200, 50);
		spankMachine->setPosition(100, 200);
		spankMachine->setText("Spank-Machine");
		spankMachine->setTextSize(15);
		//création bouton SupraC0ck
		tgui::Button::Ptr supraC0ck = tgui::Button::create(); //Crée un Bouton
		menuStandSexuel->add(supraC0ck, "supraC0ck");
		supraC0ck = menuStandSexuel->get<tgui::Button>("supraC0ck"); //Relie le bouton au GUI principal
		supraC0ck->setSize(200, 50);
		supraC0ck->setPosition(100, 275);
		supraC0ck->setText("SupraC0ck");
		supraC0ck->setTextSize(15);
		//création bouton YAMETE 
		tgui::Button::Ptr YAMETE = tgui::Button::create(); //Crée un Bouton
		menuStandSexuel->add(YAMETE, "yamete");
		YAMETE = menuStandSexuel->get<tgui::Button>("yamete"); //Relie le bouton au GUI principal
		YAMETE->setSize(200, 50);
		YAMETE->setPosition(100, 350);
		YAMETE->setText("YAMETE");
		YAMETE->setTextSize(15);
		//création text
		tgui::TextBox::Ptr textSexuel = tgui::TextBox::create();
		menuStandSexuel->add(textSexuel, "textSexuel");
		textSexuel = menuStandSexuel->get<tgui::TextBox>("textSexuel");
		textSexuel->addText("\n Argent actuel : \n \n \n ");
		textSexuel->addText("Requis : \n ");
		textSexuel->setReadOnly(true);
		textSexuel->setFocusable(false);
		textSexuel->setPosition(100, 425);
		textSexuel->setSize(200, 110);

		//création bouton achat
		tgui::Button::Ptr acheterSexuel = tgui::Button::create(); //Crée un Bouton
		menuStandSexuel->add(acheterSexuel, "Acheter");
		acheterSexuel = menuStandSexuel->get<tgui::Button>("Acheter"); //Relie le bouton au GUI principal
		acheterSexuel->setSize(200, 50);
		acheterSexuel->setPosition(100, 550);
		acheterSexuel->setText("Acheter");
		acheterSexuel->setTextSize(15);


		//crée un titre pour la fenetre
		main->init();
		int value = 0;
		tgui::ChildWindow::Ptr menuStandMilitaire = tgui::ChildWindow::create();
		data->gui.add(menuStandMilitaire, "menuStandMilitaire");
		menuStandMilitaire = data->gui.get<tgui::ChildWindow>("menuStandMilitaire");
		menuStandMilitaire->setKeepInParent(true);
		menuStandMilitaire->setResizable(true);
		menuStandMilitaire->setSize(400, 600);
		menuStandMilitaire->setTitle("Cyborg Militaire");
		menuStandMilitaire->setTextSize(15);
		//creation du bouton Combat basique
		tgui::Button::Ptr combatBasique = tgui::Button::create(); //Crée un Bouton
		menuStandMilitaire->add(combatBasique, "basique");
		combatBasique = menuStandMilitaire->get<tgui::Button>("basique"); //Relie le bouton au GUI principal
		combatBasique->setSize(200, 50);
		combatBasique->setPosition(100, 50);
		combatBasique->setText("Combat basique");
		combatBasique->setTextSize(15);
		//création bouton Combat avancé
		tgui::Button::Ptr combatAvancer = tgui::Button::create(); //Crée un Bouton
		menuStandMilitaire->add(combatAvancer, "avancer");
		combatAvancer = menuStandMilitaire->get<tgui::Button>("avancer"); //Relie le bouton au GUI principal
		combatAvancer->setSize(200, 50);
		combatAvancer->setPosition(100, 125);
		combatAvancer->setText("Combat avancé");
		combatAvancer->setTextSize(15);
		//création bouton Armurie
		tgui::Button::Ptr armurie = tgui::Button::create(); //Crée un Bouton
		menuStandMilitaire->add(armurie, "armurie");
		armurie = menuStandMilitaire->get<tgui::Button>("armurie"); //Relie le bouton au GUI principal
		armurie->setSize(200, 50);
		armurie->setPosition(100, 200);
		armurie->setText("Armurie");
		armurie->setTextSize(15);
		//création bouton Seal Team Six
		tgui::Button::Ptr sealTeamSix = tgui::Button::create(); //Crée un Bouton
		menuStandMilitaire->add(sealTeamSix, "seal");
		sealTeamSix = menuStandMilitaire->get<tgui::Button>("seal"); //Relie le bouton au GUI principal
		sealTeamSix->setSize(200, 50);
		sealTeamSix->setPosition(100, 275);
		sealTeamSix->setText("Seal Team Six");
		sealTeamSix->setTextSize(15);
		//création bouton Terminator
		tgui::Button::Ptr terminator = tgui::Button::create(); //Crée un Bouton
		menuStandMilitaire->add(terminator, "terminator");
		terminator = menuStandMilitaire->get<tgui::Button>("terminator"); //Relie le bouton au GUI principal
		terminator->setSize(200, 50);
		terminator->setPosition(100, 350);
		terminator->setText("Terminator");
		terminator->setTextSize(15);
		//création text
		tgui::TextBox::Ptr textMilitaire = tgui::TextBox::create();
		menuStandMilitaire->add(textMilitaire, "textMilitaire");
		textMilitaire = menuStandMilitaire->get<tgui::TextBox>("textMilitaire");
		textMilitaire->addText("\n Argent actuel : \n \n \n ");
		textMilitaire->addText("Requis : \n ");
		textMilitaire->setReadOnly(true);
		textMilitaire->setFocusable(false);
		textMilitaire->setPosition(100, 425);
		textMilitaire->setSize(200, 110);

		//création bouton achat
		tgui::Button::Ptr acheterMilitaire = tgui::Button::create(); //Crée un Bouton
		menuStandMilitaire->add(acheterMilitaire, "Acheter");
		acheterMilitaire = menuStandMilitaire->get<tgui::Button>("Acheter"); //Relie le bouton au GUI principal
		acheterMilitaire->setSize(200, 50);
		acheterMilitaire->setPosition(100, 550);
		acheterMilitaire->setText("Acheter");
		acheterMilitaire->setTextSize(15);

		//crée un titre pour la fenetre
		main->init();
		int value = 0;
		tgui::ChildWindow::Ptr menuStandMedecin = tgui::ChildWindow::create();
		data->gui.add(menuStandMedecin, "menuStandMedecin");
		menuStandMedecin = data->gui.get<tgui::ChildWindow>("menuStandMedecin");
		menuStandMedecin->setKeepInParent(true);
		menuStandMedecin->setResizable(true);
		menuStandMedecin->setSize(400, 600);
		menuStandMedecin->setTitle("Cyborg de Recherche");
		menuStandMedecin->setTextSize(15);
		//creation du bouton Kid Science Kit
		tgui::Button::Ptr kidScienceKit = tgui::Button::create(); //Crée un Bouton
		menuStandMedecin->add(kidScienceKit, "science");
		kidScienceKit = menuStandMedecin->get<tgui::Button>("science"); //Relie le bouton au GUI principal
		kidScienceKit->setSize(200, 50);
		kidScienceKit->setPosition(100, 50);
		kidScienceKit->setText("Kid Science Kit");
		kidScienceKit->setTextSize(15);
		//création bouton Microscope
		tgui::Button::Ptr microscope = tgui::Button::create(); //Crée un Bouton
		menuStandMedecin->add(microscope, "microscope");
		microscope = menuStandMedecin->get<tgui::Button>("microscope"); //Relie le bouton au GUI principal
		microscope->setSize(200, 50);
		microscope->setPosition(100, 125);
		microscope->setText("Microscope");
		kidScienceKit->setTextSize(15);
		//création bouton bioLabs
		tgui::Button::Ptr bioLabs = tgui::Button::create(); //Crée un Bouton
		menuStandMedecin->add(bioLabs, "bio");
		bioLabs = menuStandMedecin->get<tgui::Button>("bio"); //Relie le bouton au GUI principal
		bioLabs->setSize(200, 50);
		bioLabs->setPosition(100, 200);
		bioLabs->setText("bioLabs");
		bioLabs->setTextSize(15);
		//création bouton R&D Laboratoire
		tgui::Button::Ptr rDLaboratoire = tgui::Button::create(); //Crée un Bouton
		menuStandMedecin->add(rDLaboratoire, "laboratoire");
		rDLaboratoire = menuStandMedecin->get<tgui::Button>("laboratoire"); //Relie le bouton au GUI principal
		rDLaboratoire->setSize(200, 50);
		rDLaboratoire->setPosition(100, 275);
		rDLaboratoire->setText("R&D Laboratoire");
		rDLaboratoire->setTextSize(15);
		//création bouton Matrix Simulation
		tgui::Button::Ptr matrixSimulation = tgui::Button::create(); //Crée un Bouton
		menuStandMedecin->add(matrixSimulation, "matrix");
		matrixSimulation = menuStandMedecin->get<tgui::Button>("matrix"); //Relie le bouton au GUI principal
		matrixSimulation->setSize(200, 50);
		matrixSimulation->setPosition(100, 350);
		matrixSimulation->setText("Matrix Simulation");
		matrixSimulation->setTextSize(15);
		//création text
		tgui::TextBox::Ptr textMedecin = tgui::TextBox::create();
		menuStandMedecin->add(textMedecin, "textMedecin");
		textMedecin = menuStandMedecin->get<tgui::TextBox>("textMedecin");
		textMedecin->addText("\n Argent actuel : \n \n \n ");
		textMedecin->addText("Requis : \n ");
		textMedecin->setReadOnly(true);
		textMedecin->setFocusable(false);
		textMedecin->setPosition(100, 425);
		textMedecin->setSize(200, 110);

		//création bouton achat
		tgui::Button::Ptr acheterMedecin = tgui::Button::create(); //Crée un Bouton
		menuStandMedecin->add(acheterMedecin, "Acheter");
		acheterMedecin = menuStandMedecin->get<tgui::Button>("Acheter"); //Relie le bouton au GUI principal
		acheterMedecin->setSize(200, 50);
		acheterMedecin->setPosition(100, 550);
		acheterMedecin->setText("Acheter");
		acheterMedecin->setTextSize(15);

		//crée un titre pour la fenetre
		main->init();
		int value = 0;
		tgui::ChildWindow::Ptr menuStandDivertissement = tgui::ChildWindow::create();
		data->gui.add(menuStandDivertissement, "menuStandDivertissement");
		menuStandDivertissement = data->gui.get<tgui::ChildWindow>("menuStandDivertissement");
		menuStandDivertissement->setKeepInParent(true);
		menuStandDivertissement->setResizable(true);
		menuStandDivertissement->setSize(400, 600);
		menuStandDivertissement->setTitle("Cyborg de Divertissement");
		menuStandDivertissement->setTextSize(15);
		//creation du bouton NES Classique intégré
		tgui::Button::Ptr nesClassiqueIntegre = tgui::Button::create(); //Crée un Bouton
		menuStandDivertissement->add(nesClassiqueIntegre, "NES");
		nesClassiqueIntegre = menuStandDivertissement->get<tgui::Button>("NES"); //Relie le bouton au GUI principal
		nesClassiqueIntegre->setSize(200, 50);
		nesClassiqueIntegre->setPosition(100, 50);
		nesClassiqueIntegre->setText("NES Classique");
		nesClassiqueIntegre->setTextSize(15);
		//création bouton Wii
		tgui::Button::Ptr buttonWii = tgui::Button::create(); //Crée un Bouton
		menuStandDivertissement->add(buttonWii, "Wii");
		buttonWii = menuStandDivertissement->get<tgui::Button>("Wii"); //Relie le bouton au GUI principal
		buttonWii->setSize(200, 50);
		buttonWii->setPosition(100, 125);
		buttonWii->setText("Wii");
		nesClassiqueIntegre->setTextSize(15);
		//création bouton Mario Kart
		tgui::Button::Ptr marioKart = tgui::Button::create(); //Crée un Bouton
		menuStandDivertissement->add(marioKart, "mario");
		marioKart = menuStandDivertissement->get<tgui::Button>("mario"); //Relie le bouton au GUI principal
		marioKart->setSize(200, 50);
		marioKart->setPosition(100, 200);
		marioKart->setText("Mario Kart");
		marioKart->setTextSize(15);
		//création bouton Gaming PC
		tgui::Button::Ptr gamingPC = tgui::Button::create(); //Crée un Bouton
		menuStandDivertissement->add(gamingPC, "gaming");
		gamingPC = menuStandDivertissement->get<tgui::Button>("gaming"); //Relie le bouton au GUI principal
		gamingPC->setSize(200, 50);
		gamingPC->setPosition(100, 275);
		gamingPC->setText("Gaming PC intégré");
		gamingPC->setTextSize(15);
		//création bouton VR Headset
		tgui::Button::Ptr vRHeadset = tgui::Button::create(); //Crée un Bouton
		menuStandDivertissement->add(vRHeadset, "vr");
		vRHeadset = menuStandDivertissement->get<tgui::Button>("vr"); //Relie le bouton au GUI principal
		vRHeadset->setSize(200, 50);
		vRHeadset->setPosition(100, 350);
		vRHeadset->setText("VR Headset");
		vRHeadset->setTextSize(15);
		//création text
		tgui::TextBox::Ptr textDivertissement = tgui::TextBox::create();
		menuStandDivertissement->add(textDivertissement, "textDivertissement");
		textDivertissement = menuStandDivertissement->get<tgui::TextBox>("textDivertissement");
		textDivertissement->addText("\n Argent actuel : \n \n \n ");
		textDivertissement->addText("Requis : \n ");
		textDivertissement->setReadOnly(true);
		textDivertissement->setFocusable(false);
		textDivertissement->setPosition(100, 425);
		textDivertissement->setSize(200, 110);

		//création bouton achat
		tgui::Button::Ptr acheterDivertissement = tgui::Button::create(); //Crée un Bouton
		menuStandDivertissement->add(acheterDivertissement, "Acheter");
		acheterDivertissement = menuStandDivertissement->get<tgui::Button>("Acheter"); //Relie le bouton au GUI principal
		acheterDivertissement->setSize(200, 50);
		acheterDivertissement->setPosition(100, 550);
		acheterDivertissement->setText("Acheter");
		acheterDivertissement->setTextSize(15);

		//crée un titre pour la fenetre
		main->init();
		int value = 0;
		tgui::ChildWindow::Ptr menuStandCuisinier = tgui::ChildWindow::create();
		data->gui.add(menuStandCuisinier, "menuStandCuisinier");
		menuStandCuisinier = data->gui.get<tgui::ChildWindow>("menuStandCuisinier");
		menuStandCuisinier->setKeepInParent(true);
		menuStandCuisinier->setResizable(true);
		menuStandCuisinier->setSize(400, 600);
		menuStandCuisinier->setTitle("Cyborg Cuisinier");
		menuStandCuisinier->setTextSize(15);
		//creation du bouton Touillage plus rapide
		tgui::Button::Ptr touillagePlusRapide = tgui::Button::create(); //Crée un Bouton
		menuStandCuisinier->add(touillagePlusRapide, "Touillage");
		touillagePlusRapide = menuStandCuisinier->get<tgui::Button>("Touillage"); //Relie le bouton au GUI principal
		touillagePlusRapide-> setSize(200, 50);
		touillagePlusRapide->setPosition(100, 50);
		touillagePlusRapide->setText("Touillage plus rapide");
		touillagePlusRapide->setTextSize(15);
		//création bouton Réfrigérateur intégré
		tgui::Button::Ptr frigoIntegre = tgui::Button::create(); //Crée un Bouton
		menuStandCuisinier->add(frigoIntegre, "Refrigerateur");
		frigoIntegre = menuStandCuisinier->get<tgui::Button>("Refrigerateur"); //Relie le bouton au GUI principal
		frigoIntegre->setSize(200, 50);
		frigoIntegre->setPosition(100, 125);
		frigoIntegre->setText("Réfrigérateur intégré");
		frigoIntegre->setTextSize(15);
		//création bouton Couteau en Vibranium
		tgui::Button::Ptr CouteauEnVibranium = tgui::Button::create(); //Crée un Bouton
		menuStandCuisinier->add(CouteauEnVibranium, "couteau");
		CouteauEnVibranium = menuStandCuisinier->get<tgui::Button>("couteau"); //Relie le bouton au GUI principal
		CouteauEnVibranium->setSize(200, 50);
		CouteauEnVibranium->setPosition(100, 200);
		CouteauEnVibranium->setText("Couteau en Vibranium");
		CouteauEnVibranium->setTextSize(15);
		//création bouton CPU
		tgui::Button::Ptr CpuCuisinier = tgui::Button::create(); //Crée un Bouton
		menuStandCuisinier->add(CpuCuisinier, "CPU");
		CpuCuisinier = menuStandCuisinier->get<tgui::Button>("CPU"); //Relie le bouton au GUI principal
		CpuCuisinier->setSize(200, 50);
		CpuCuisinier->setPosition(100, 275);
		CpuCuisinier->setText("CPU Amélioré");
		CpuCuisinier->setTextSize(15);
		//création bouton Gordon Ramsay Mode 
		tgui::Button::Ptr gordonRamsayMode = tgui::Button::create(); //Crée un Bouton
		menuStandCuisinier->add(gordonRamsayMode, "gordon");
		gordonRamsayMode = menuStandCuisinier->get<tgui::Button>("gordon"); //Relie le bouton au GUI principal
		gordonRamsayMode->setSize(200, 50);
		gordonRamsayMode->setPosition(100, 350);
		gordonRamsayMode->setText("Gordon Ramsay Mode");
		gordonRamsayMode->setTextSize(15);
		//création text
		tgui::TextBox::Ptr textCuisinier = tgui::TextBox::create();
		menuStandCuisinier->add(textCuisinier, "textCuisinier");
		textCuisinier = menuStandCuisinier->get<tgui::TextBox>("textCuisinier");
		textCuisinier->addText("\n Argent actuel : \n \n \n ");
		textCuisinier->addText("Requis : \n ");
		textCuisinier->setReadOnly(true);
		textCuisinier->setFocusable(false);
		textCuisinier->setPosition(100, 425);
		textCuisinier->setSize(200, 110);

		//création bouton achat
		tgui::Button::Ptr acheterCuisinier = tgui::Button::create(); //Crée un Bouton
		menuStandCuisinier->add(acheterCuisinier, "Acheter");
		acheterCuisinier = menuStandCuisinier->get<tgui::Button>("Acheter"); //Relie le bouton au GUI principal
		acheterCuisinier->setSize(200, 50);
		acheterCuisinier->setPosition(100, 550);
		acheterCuisinier->setText("Acheter");
		acheterCuisinier->setTextSize(15);
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

