#include "RuntimeInterface.h"
#include "Helpers.h"
#include <iostream>

RuntimeInterface::RuntimeInterface()
{
	setCurrentScore(0);
	m_x = 37;
	m_y = 27;
	setCurrentPosX(m_x);
	setCurrentPosY(m_y);
}

void RuntimeInterface::update()
{	
		drawScore(m_playerScore, m_x, m_y); //Draw the players score to the screen.
}

void RuntimeInterface::setCurrentScore(int currentScore)
{
	m_playerScore = currentScore; //Set the 'currentScore'.
}

int RuntimeInterface::getCurrentScore()
{
	return m_playerScore; //Get m_playerScore.
}
