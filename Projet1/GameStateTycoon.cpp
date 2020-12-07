#include "GameStateTycoon.h"
#include <TGUI/TGUI.hpp>
#include "MainTycoon.h"



void GameStateTycoon::init() // Initialiser tous l'interface du tycoon
{
	//Test Sulli
	tgui::ChildWindow::Ptr window = tgui::ChildWindow::create();
	data->gui.add(window, "window");
	window = data->gui.get<tgui::ChildWindow>("window");
	window->setKeepInParent(true);
	window->setResizable(true);
	window->setSize(400, 600);

	//button->connect("Pressed", Game::signalHandler); //Relier le bouton à une fonction(doit être statique si on utilise la classe et non une instance), le premier paramètre est prédéfinis
		//button->connect("Pressed", [&]() { std::cout << "input2" << endl; }); //Exemple en lambda, notez que le bouton peut prendre deux fonctions
	//crée un titre pour la fenetre
	window->setTitle("Robot Ménarger");
	window->setTextSize(15);
	//creation du bouton Balayage rapide
	tgui::Button::Ptr button2 = tgui::Button::create(); //Crée un Bouton
	window->add(button2, "monBouton2");
	button2 = window->get<tgui::Button>("monBouton2"); //Relie le bouton au GUI principal
	button2->setSize(200, 50);
	button2->setPosition(100, 50);
	button2->setText("Balayage Rapide");
	button2->setTextSize(15);
	button2->connect("Pressed", [&]() {MainTycoon::ameliorer(1); });
	//création bouton detecteur
	tgui::Button::Ptr button3 = tgui::Button::create(); //Crée un Bouton
	window->add(button3, "monBouton3");
	button3 = window->get<tgui::Button>("monBouton3"); //Relie le bouton au GUI principal
	button3->setSize(200, 50);
	button3->setPosition(100, 125);
	button3->setText("Detecteur de MPA");
	button2->setTextSize(15);

	//création bouton balais
	tgui::Button::Ptr button4 = tgui::Button::create(); //Crée un Bouton
	window->add(button4, "monBouton4");
	button4 = window->get<tgui::Button>("monBouton4"); //Relie le bouton au GUI principal
	button4->setSize(200, 50);
	button4->setPosition(100, 200);
	button4->setText("Balais en Vibranium");
	button4->setTextSize(15);
	//création bouton CPU
	tgui::Button::Ptr button5 = tgui::Button::create(); //Crée un Bouton
	window->add(button5, "monBouton5");
	button5 = window->get<tgui::Button>("monBouton5"); //Relie le bouton au GUI principal
	button5->setSize(200, 50);
	button5->setPosition(100, 275);
	button5->setText("CPU Amélioré");
	button5->setTextSize(15);
	//création bouton Aspirateur
	tgui::Button::Ptr button6 = tgui::Button::create(); //Crée un Bouton
	window->add(button6, "monBouton6");
	button6 = window->get<tgui::Button>("monBouton6"); //Relie le bouton au GUI principal
	button6->setSize(200, 50);
	button6->setPosition(100, 350);
	button6->setText("Aspirateur Quantique");
	button6->setTextSize(15);
	//création text
	tgui::TextBox::Ptr text = tgui::TextBox::create();
	window->add(text, "Text");
	text = window->get<tgui::TextBox>("Text");
	text->addText("\n Argent actuel : \n \n \n ");
	text->addText("Requis : \n ");
	text->setReadOnly(true);
	text->setFocusable(false);
	text->setPosition(100, 425);
	text->setSize(200, 110);
}

void GameStateTycoon::update()// Initialiser les variable du tycoon
{
	
}