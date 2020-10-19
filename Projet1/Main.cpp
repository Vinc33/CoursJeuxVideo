#include "./Game/Game.h"

using namespace sf;

int main()
{
	/*Noms des étudiants
	1.Vincent Morin
	2 - Tanya
	3 - Maxime
	4 - Francis
	5 - Alex
	6 - Nicolas Occupation Double
	7 - Jeremie Thiffault
	8 - Mathieu Bienvenu
	9 - Matis
	11 - Sulli
	14.Billy Osmont
	12 - Fabrice LONTIO
	13 - Nicolas B-G
	14 . Billy Osmont 
	20. Michael PP

	
	*/
	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
