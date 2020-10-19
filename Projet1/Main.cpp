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
<<<<<<< HEAD
>>>>>>> 803c1bc7bf79907b62a978a6c539946013e25acc
=======
	7 - Jeremie Thiffault
	8 - Mathieu Bienvenu
	14.Billy Osmont
>>>>>>> 67868f36da41b44445c5fda7f78fffdfaad6e9a5
	*/
	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
