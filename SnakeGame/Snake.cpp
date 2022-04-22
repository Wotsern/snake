#include <stdlib.h>
#include <Windows.h>

#include "Food.h"
#include "Snake.h"

Snake::Snake() //Constructor.
{
	m_pSnakeHead = new SnakeHead(); //SnakeHead pointer.
	m_pSnakeTail = new SnakeTail(); //SnakeTail pointer.
}

Snake::~Snake() //Deconstructor.
{
	delete m_pSnakeHead; //Delete pointer.
	delete m_pSnakeTail;
}

void Snake::render()
{
	m_pSnakeHead->render(); //Render snake head.
	m_pSnakeTail->render(); //Render snake tail.
}

void Snake::unrender()
{
	m_pSnakeHead->unrender(); //Unrender snake head.
	m_pSnakeTail->unrender(); //Unrender snake tail.
}

void Snake::update(RuntimeInterface* runtimeInterface) //Pass the runtimeInterface generated in game.
{
	m_pSnakeHead->update();
	m_pSnakeTail->update(m_pSnakeHead->getCurrentPosX(), m_pSnakeHead->getCurrentPosY(), runtimeInterface);
}

SnakeHead* Snake::getSnakeHead()
{
	return m_pSnakeHead;
}

SnakeTail* Snake::getSnakeTail()
{
	return m_pSnakeTail; //Grab the snake tail instance from 'Snake'.
}

int Snake::getSnakeHeadPosX()
{
	return m_pSnakeHead->getCurrentPosX(); //Grab the snake head X position.
}

int Snake::getSnakeHeadPosY()
{
	return m_pSnakeHead->getCurrentPosY(); //Grab the snake head Y position.
}
