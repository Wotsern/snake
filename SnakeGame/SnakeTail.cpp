#include <iostream>

#include "EndingScene.h"
#include "Helpers.h"/
#include "SnakeTail.h"
#include "Settings.h"

SnakeTail::SnakeTail()
{
	m_totalSnakeSegments = c_startingTailLength;
	m_currentMove = 0;
}

void SnakeTail::update(int xPos, int yPos, RuntimeInterface* runtimeInterface)
{	
	setNewPosition(xPos, yPos);	//Constantly update tail positions based on xPos, yPos parameters.
	checkTailCollision(xPos, yPos, runtimeInterface); //Check for collision.
}

void SnakeTail::setNewPosition(int xPos, int yPos)
{
	m_previousPositions[m_currentMove].setCurrentPosXY(xPos, yPos); //Store most recent X, Y.
	m_currentMove++;

	for (int i = 0; i < m_totalSnakeSegments; i++)
	{
		m_segments[i].setCharacter(c_snakeTail); //Set character of snake tail to 'o'.
		m_segments[i].setCurrentPosXY(m_previousPositions[m_currentMove - (i + 2)].getCurrentPosX(), m_previousPositions[m_currentMove - (i + 2)].getCurrentPosY()); //Set position of all tails.
	}
}

void SnakeTail::checkTailCollision(int xPos, int yPos, RuntimeInterface* runtimeInterface) //Runtime interface parameter used for setting the score.
{
	for (int i = 0; i < m_totalSnakeSegments; i++) //Loop through the total amount of snake segments.
	{
		if (m_segments[i].getCurrentPosX() == xPos && m_segments[i].getCurrentPosY() == yPos) //Check for the position of the snake head and the tail segments to see if there is a collision between the two.
		{
			system("CLS"); //Clear screen.
			EndingScene endingScene; //Create an instance of EndingScene.
			endingScene.update(runtimeInterface); //Run ending cutscene, while passing the runtime interface instance to get the score to display.
		}
	}
}

void SnakeTail::render()
{
	for (int i = 0; i < m_totalSnakeSegments; i++)
	{
		drawChar(m_segments[i].getCharacter(), m_segments[i].getCurrentPosX(), m_segments[i].getCurrentPosY()); //Render tail segments to screen.
	}
}

void SnakeTail::unrender() 
{
	for (int i = 0; i < m_totalSnakeSegments; i++)
	{
		drawChar(' ', m_segments[i].getCurrentPosX(), m_segments[i].getCurrentPosY()); //Unrender tail segments.
	}
}

int SnakeTail::getTailLength()
{
	return m_totalSnakeSegments; //Getter for total tail segments.
}

void SnakeTail::setTailLength(int tailLength)
{
	m_totalSnakeSegments = tailLength; //Setter for total tail segments.
}
