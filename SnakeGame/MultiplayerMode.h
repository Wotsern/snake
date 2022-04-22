#ifndef MULTIPLAYERMODE_H
#define MULTIPLAYERMODE_H

#include "RuntimeInterface.h"
#include "Snake.h"

class MultiplayerMode {
private:
	Snake*				m_pSnakes[2];			//Pointer array of snakes.
	RuntimeInterface*	m_pRuntimeInterface;	//Pointer array of runtime interface to display score.
	MapHandler*			m_pMapHandler;			//Create instance of map handler.
	Food				m_food;					//Create instance of food.

	bool m_mapLoaded;
public:
	MultiplayerMode();  //Constructor.
	~MultiplayerMode(); //Deconstructor.

	void update(int mapNumber);

};

#endif // !MULTIPLAYERMODE_H
