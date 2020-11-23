#include "./Game/Game.h"


using namespace sf;

int main()
{

    std::string gameName = "MyGame";

	GameView::Game myGame(1280, 1024, gameName);
	myGame.init();
	myGame.startGame();


	return EXIT_SUCCESS;
}
