//Projet Rabidja - SDL 2.0
//Partie2_06Rabidja_LvlEditor
//structs.h


#define _CRT_SECURE_NO_WARNINGS /*Pour �viter les warnings d�s � l'ins�curit� de la
                                  fonction sprintf lors de la compilation avec l'option c++ */


#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include "defs.h"

/* Structures qui seront utilis�es pour g�rer le jeu */

/* Structure pour g�rer l'input (clavier puis joystick) */

typedef struct Input
{
	int left, right, up, down, add, remove;
	int previous, next, load, save, copy, reinit;
	int copyMap, pasteMap;
	int mouseX, mouseY;
	int leveldown, levelup;
	int layerDrawn, changeLayer;
	int Tactileleft, Tactileright, Tactileup, Tactiledown;
	int deleteTile;

	// Ajout/Suppression de lignes/colonnes
	int addColumn, deleteColumn, addRow, deleteRow, fillWith;

	// Inversement des Tiles dans la zone s�lectionn�e
	int flipVertical, flipHorizontal;

	// Cestion du Copy/Paste
	int shortcutCopy, shortcutPaste, shortcutCut;
	int ctrl;

	// Gestion du CRTL+Z et CTRL+Y
	int ctrl_Z, ctrl_Y;

	// Zoom
	int modeZoom;

} Input;


/* Structure pour g�rer le niveau (� compl�ter plus tard) */

typedef struct Gestion
{

    SDL_Window *screen;
	SDL_Renderer *renderer;

	// Gestion de la grille
	SDL_Texture *grille32;
	int displayGrille;

	// Information sur les fonctionnalit�s
	SDL_Texture *information_Img;
	int displayInformation;

	int level;
	int placeBegin;

	int message, message_timer; //Vaut 1 s'il y a un message � afficher
	char messageText[200];

	//Boite de dialogue
	int messageBox, messageBoxResult, doMessageBoxAction, messageBoxAction;
	char messageBoxText[200];

	// Gestion de la s�lection
	SDL_Texture *select_Img;
	SDL_Texture *selectZone_Img;
	int selectActivated, selectZoneActivated;
	int selectFirstX, selectFirstY, selectLastX, selectLastY;
	int zoneMemFromX, zoneMemFromY, zoneMemToX, zoneMemToY;
	int zoneMemFromX_CP, zoneMemFromY_CP, zoneMemToX_CP, zoneMemToY_CP;
	int selectCopyTab_L[MAX_MAP_Y][MAX_MAP_X];	// 1 layer
	int selectCopyTab_B[MAX_MAP_Y][MAX_MAP_X];	// Pour les 3 Layers
	int selectCopyTab_A[MAX_MAP_Y][MAX_MAP_X];
	int selectCopyTab_F[MAX_MAP_Y][MAX_MAP_X];
	int selectCopyAll;		// Pour indiquer qu'on copie tous les layers en m�me temps

	// Mode Zoom
	SDL_Texture *ModeZoomActivated, *ModeZoomDesactivated;;
	int ModeZoom_X, ModeZoom_Y;


} Gestion;


/* Structure pour g�rer la map � afficher (� compl�ter plus tard) */

typedef struct Map
{

	SDL_Texture *background_full, *background, *tileSet, *tileSetTransparent, *fond, *scrollbarDown, *scrollbarUp, *startpoint, *onglets, *messageBox;

    //Num�ro du tileset � utiliser
	int tilesetAffiche;

	//Numero de la partie du tileset � afficher � droite
	int tilesetPart;

	/* Coordonn�es de d�part du h�ros, lorsqu'il commence le niveau */
	int beginx, beginy;

	/* Coordonn�es de d�but, lorsqu'on doit dessiner la map */
	int startX, startY;

	/* Coordonn�es max de fin de la map */
	int maxX, maxY;

	/* Tableau � double dimension repr�sentant la map de tiles */
	int tileAction[MAX_MAP_Y][MAX_MAP_X];

	//Deuxi�me couche de tiles
    int tileBackground[MAX_MAP_Y][MAX_MAP_X];

    //Deuxi�me couche de tiles
    int tileForeground[MAX_MAP_Y][MAX_MAP_X];

	// Zoom
	int zoom;
	int newTileSize;

} Map;


typedef struct Cursor
{
	int x, y, tileID;
} Cursor;

enum layers{
	LAYER_ACTION = 1,
	LAYER_BACKGROUD, 	 
	LAYER_FOREGROUD, 
	LAYER_ALL,
};

#endif




