#include "./Game/Game.h"

using namespace sf;

int main()
{
	/*Noms des étudiants
	1.Vincent Morin
	2 - Tanya
<<<<<<< HEAD
	12 - Fabrice LONTIO
=======
	3 - Maxime
	4 - Francis
	6 - Nicolas Occupation Double
>>>>>>> 803c1bc7bf79907b62a978a6c539946013e25acc
	*/
	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
