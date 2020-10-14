#include "./Game/Game.h"

using namespace sf;

int main()
{
	//2 - Tanya
	std::string gameName = "MyGame";
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();

	return EXIT_SUCCESS;
}
