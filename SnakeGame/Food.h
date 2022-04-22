#ifndef FOOD_H
#define FOOD_H

#include "CharacterObject.h"
#include "MapHandler.h"
#include "RuntimeInterface.h"
#include "SnakeTail.h"

class Food : public CharacterObject {
private:
	int		m_foodCount;			//Checks for how much food has spawned.
	int		m_mapNumber;			//Checks for the current map.
	int		m_randX;				//Used for random positioning of the food.
	int		m_randY;				//* ^^
	bool	m_canRender;			//Determines whether to render or not based on position of food.
	bool	m_spawnFood;			//Check for if player eats food.
	bool	m_generateNewPosition;	//Check for if a new position is required.

public:
	Food();
	void update(SnakeTail* snakeTail, int xPos, int yPos, RuntimeInterface* runtimeInterface);	//Used to increase snake tail and check for head pos (xPos, yPos).
	void generateRandomPos(MapHandler* mapHandler, int mapNumber); //Generate random position for food to render to.
	void render();
	void unrender();
	void checkSnakeHeadPosition(SnakeTail* snakeTail, int xPos, int yPos, RuntimeInterface* runtimeInterface);
};

//Const is used when you want to access data but not change it.

#endif // !FOOD_H