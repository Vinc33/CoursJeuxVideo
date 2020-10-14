#include "./Game/Game.h"

using namespace sf;

int main()
{

	/*Noms des étudiants
	
	1.Vincent Morin
	
	*/

	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
