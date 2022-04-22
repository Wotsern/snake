#include <Windows.h>
#include "MultiplayerMode.h"

MultiplayerMode::MultiplayerMode()
{
	m_pMapHandler = new MapHandler();
	m_pSnakes[0] = new Snake();
	m_pSnakes[1] = new Snake();
	m_pRuntimeInterface = new RuntimeInterface();
}

MultiplayerMode::~MultiplayerMode()
{
	delete m_pMapHandler;
	delete[] m_pSnakes;
	delete m_pRuntimeInterface;
}

void MultiplayerMode::update(int mapNumber)
{
	if (m_mapLoaded == false)
	{
		color(7); //Gold.
		m_pMapHandler->render(mapNumber); //Render the desired map.
		m_mapLoaded = true; //Stop map from reloading over the top of the snake.
	}

	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			color(i + 3); //Color the different snakes differently.
			m_pSnakes[i]->unrender(); //Unrender both snakes.
			m_pMapHandler->checkCollision(m_pSnakes[i]->getSnakeHeadPosX(), m_pSnakes[i]->getSnakeHeadPosY(), m_pRuntimeInterface); //Check for wall collision.
			m_food.update(m_pSnakes[i]->getSnakeTail(), m_pSnakes[i]->getSnakeHeadPosX(), m_pSnakes[i]->getSnakeHeadPosY(), m_pRuntimeInterface); //Update food location.
			m_pRuntimeInterface->update(); //Update score text.
			m_pSnakes[i]->update(m_pRuntimeInterface); //Update runtime interface.
			m_pSnakes[i]->render(); //Render both snakes.
		}
		m_food.generateRandomPos(m_pMapHandler, mapNumber); //Generate food random position.
		
		Sleep(125); //Sleep console.
	}
}