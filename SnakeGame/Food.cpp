#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "AudioHandler.h"
#include "Food.h"
#include "Helpers.h"
#include "Settings.h"

Food::Food()
{	
	m_foodCount = 0;
	srand((int)time(0)); //srand is used for random number generation.
	setCharacter('x'); //Set character to 'x'.
}

void Food::update(SnakeTail* snakeTail, int xPos, int yPos, RuntimeInterface* runtimeInterface) //Parameters are used to grab the SnakeHead X/Y from "Snake.cpp".
{ 
	if (m_canRender == true) 
	{
		render(); //Draw food to console.
	}
	else
	{
		unrender(); //Remove food from console.
	}
	checkSnakeHeadPosition(snakeTail, xPos, yPos, runtimeInterface); //Pass through the values retrieved from the update function in "Snake.cpp".
}

void Food::generateRandomPos(MapHandler* mapHandler, int mapNumber)
{
	m_randX = rand() % 51; //Generate random X position.
	m_randY = rand() % 26; //Generate random Y position.

	if (m_randX % 2 != 0 || m_randX == 1 || mapNumber == 4 && m_randY < 15) { //If the randomY is less that 15 while on survival, generate new number.
		m_spawnFood = false;
	}
	else
	{
		m_spawnFood = true;
	}

	if (m_spawnFood == true && m_foodCount < 1) { //Spawn food at set position.
		for (int i = 0; i < c_totalWallSegments; i++)
		{
			if (m_randX == mapHandler->getSegmentArray(i).getCurrentPosX() && m_randY == mapHandler->getSegmentArray(i).getCurrentPosY() && mapHandler->getSegmentArray(i).getCharacter() == ' ')
			{
				m_foodCount = 1;
				setCurrentPosX(m_randX); //Set X position.
				setCurrentPosY(m_randY); //Set Y position.
				m_canRender = true; //Render food to screen.
			}
			else
			{
				m_spawnFood = false;
			}
		}
	}
}

void Food::checkSnakeHeadPosition(SnakeTail* snakeTail, int xPos, int yPos, RuntimeInterface* runtimeInterface)
{
	if (getCurrentPosX() == xPos && getCurrentPosY() == yPos) 
	{ //Check parameters against current Food position.
		if (m_mapNumber != 4) //If the map isn't the survival map then the snake tail will increase.
		{
			snakeTail->setTailLength(snakeTail->getTailLength() + 1); //Increase the snake tail.
		}
		PLAY_SOUND(3); //Macro to play a sound (found in 'Helpers.h').
		runtimeInterface->setCurrentScore(runtimeInterface->getCurrentScore() + 1); //Increase players score.
		m_canRender = false;
		m_foodCount = 0;
	}
}

void Food::render() 
{
	drawChar(getCharacter(), getCurrentPosX(), getCurrentPosY()); //Draw food to screen.
}

void Food::unrender()
{
	drawChar(' ', getCurrentPosX(), getCurrentPosY()); //Unrender food.
}
