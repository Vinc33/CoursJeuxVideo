#include "Ladder.h"

Ladder::Ladder(int hp, bool destroyable)
{
	this->sprite = "Assets/Objects/barrel.png";
	this->hp = hp;
	this->destroyable = destroyable;
}

int Ladder::verifyHp()
{
	if (hp <= 0 && destroyable) // Si l'hp de l'objet est inférieure à 0 et que l'objet peut être détruit
	{
		ladder.kill(ladder); // Call de la fonction kill dans BaseEntity qui supprime l'objet du jeu
	}
	return hp;
}

void Ladder::checkCollision()
{
	/*sf::Event event;
	if (ladder.getCollision(ladder)) // Call le getCollision de BaseEntity qui est un bool qui return une valeur
	{
		verifyHp(); // Pas utile, mais je le laisse, car tous les objets auront une vérification d'hp
		if (InputManager::getPressedKeyCode(event) == keyboardMap->getUpKey()) // Si la KeyUp est appuyer (KeyUp, et non W, car le joueur à la possibilité de changer la touche
		{
			climb(); // Call climb
		}

	}*/
}

void Ladder::climb()
{

}

