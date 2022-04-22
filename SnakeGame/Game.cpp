#include <ctime>
#include <iostream>
#include <Windows.h>

#include "Food.h"
#include "Game.h"
#include "MapHandler.h"

Game::Game()
{
	m_pSnake = new Snake(); //m_pSnake = new Snake[k_numPlayer];
	m_pMapHandler = new MapHandler();
	m_pRuntimeInterface[0] = new RuntimeInterface();
}

Game::~Game()
{
	delete m_pSnake; //delete[] m_pSnakes;
	delete m_pMapHandler;
}

void Game::run(int mapNumber)
{
	if (m_mapLoaded == false)
	{
		color(7); //Gold.
		m_pMapHandler->render(mapNumber); //Render the desired map.
		m_mapLoaded = true;	
	}

	while (true)
	{
		if (mapNumber == 4)
		{
			m_survival.update();
			m_survival.checkCollision(m_pSnake->getSnakeHeadPosX(), m_pSnake->getSnakeHeadPosY(), m_pRuntimeInterface[0]); //Check for collision with survival walls.
		}
		
		m_pSnake->unrender(); //Unrender snake.
		m_pSnake->update(m_pRuntimeInterface[0]); //Update snake position.
		m_pMapHandler->checkCollision(m_pSnake->getSnakeHeadPosX(), m_pSnake->getSnakeHeadPosY(), m_pRuntimeInterface[0]); //Check for wall collision.
		color(4);
		m_food.update(m_pSnake->getSnakeTail(), m_pSnake->getSnakeHeadPosX(), m_pSnake->getSnakeHeadPosY(), m_pRuntimeInterface[0]); //Update food location.
		color(15);
		m_pRuntimeInterface[0]->update(); //Update score text.
		color(10);
		m_pSnake->render(); //Render the snake after the food so it is rendered above the food.
		color(13);
		m_food.generateRandomPos(m_pMapHandler, mapNumber); //Generate food random position.

		Sleep(125); //Sleep the console for 0.125 seconds.
	}
}
