#include "./Game/Game.h"


using namespace sf;

int main()
{
<<<<<<< HEAD

    std::string gameName = "MyGame";

=======
	std::string gameName = "MyGame";
>>>>>>> 263e853ff384787486513e9080bf57f2087fbc78
	GameView::Game myGame(800, 600, gameName);
	myGame.init();
	myGame.startGame();



	return EXIT_SUCCESS;
}
