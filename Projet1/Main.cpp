#include "./Game/Game.h"

using namespace sf;

int main()
{
	/*Noms des étudiants
	
	1.Vincent Morin
	2 - Tanya
	3 - Maxime
	4 - Francis
	6 - Nicolas Occupation Double
	7 - Jeremie Thiffault
	14.Billy Osmont
	20. Michael PP
	*/
	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
