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
	11 - Sulli
	7 - Jeremie Thiffault
	8 - Mathieu Bienvenu
	14.Billy Osmont
	*/
	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
