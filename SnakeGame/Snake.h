#ifndef SNAKE_H
#define SNAKE_H

#include "CharacterObject.h"
#include "Food.h"
#include "RuntimeInterface.h"
#include "SnakeHead.h"
#include "SnakeTail.h"
#include "Vector2.h"

class Snake
{
private:
	SnakeHead*		m_pSnakeHead; //Create single instance of SnakeHead.
	SnakeTail*		m_pSnakeTail; //Create single instance of SnakeTail.

public:
	Snake();
	~Snake();

	void render();
	void unrender();
	void update(RuntimeInterface* runtimeInterface);

	SnakeHead* getSnakeHead();  //Get the snake head within this Snake class.
	SnakeTail* getSnakeTail();  //Get the snake tail within this Snake class.
	int getSnakeHeadPosX();		//Get X pos of snake head within this Snake class.
	int getSnakeHeadPosY();		//Get Y pos of snake head within this Snake class.
};

#endif