#ifndef GAME_H
#define GAME_H

#include "Food.h"
#include "MapHandler.h"
#include "RuntimeInterface.h"
#include "Snake.h"
#include "SurvivalMode.h"

//cost int num play 2
//k_numplayers = 2

class Game
{
private:
	Snake*				m_pSnake;				//Pointer of class snake. Saves memory as a pointed as only one instance is needed.
	Snake				m_snakes[2];			//Array of snakes (used for multiplayer).
	Food				m_food;					//Create instance of food.
	MapHandler*			m_pMapHandler;			//Create instance of map handler.
	SurvivalMode		m_survival;				//Create instance of Survival Mode.
	RuntimeInterface*	m_pRuntimeInterface[1]; //Create instance of runtime interface.
	bool				m_mapLoaded;			//Bool used to stop map from loading twice.

public:
	Game();
	~Game();

	void run(int mapNumber);					//Run game with the desired map.
};


//If snakes position is equal to food pos.

#endif // #define GAME_H
