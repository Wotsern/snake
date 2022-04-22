#include <Windows.h>

#include "EndingScene.h"
#include "Helpers.h"
#include "Settings.h"
#include "SurvivalMode.h"

SurvivalMode::SurvivalMode()
{
	m_y = 3;
	m_generateWall = true;
	generateRandomNum();
}

void SurvivalMode::update()
{
	generateNewWall();
}

void SurvivalMode::checkCollision(int xPos, int yPos, RuntimeInterface* runtimeInterface)
{
	for (int i = 0; i < c_totalWallSegments; i++) {
		if (m_wallSegments[i].getCurrentPosX() == xPos && m_wallSegments[i].getCurrentPosY() == yPos && m_wallSegments[i].getCharacter() == '*') //Check collision between snake head and '*' character (wall).
		{
			system("CLS"); //Clear system if collision occurred.
			EndingScene endingScene; //Load ending cut scene.
			endingScene.update(runtimeInterface); //Run desired function.
		}
	}
}

void SurvivalMode::render()
{
	for (int i = 0; i < c_totalSurvivalSegments; i++)
	{
		drawChar(m_wallSegments[i].getCharacter(), m_wallSegments[i].getCurrentPosX(), m_wallSegments[i].getCurrentPosY()); //Draw wall to screen.	
	}

#pragma region Magic
	color(7); //Gold.
	drawChar('=', 50, 5);
	drawChar('=', 50, 23);
	drawChar('=', 2, 24);
#pragma endregion
}

void SurvivalMode::unrender()
{
	for (int i = 0; i < c_totalSurvivalSegments; i++)
	{
		m_wallSegments[i].setCharacter(' ');
		drawChar(m_wallSegments[i].getCharacter(), m_wallSegments[i].getCurrentPosX(), m_wallSegments[i].getCurrentPosY()); //Unrender wall from console.
	}
}

void SurvivalMode::generateNewWall()
{
	color(6); //Set color.
	unrender(); //Unrender wall.
	m_x = 3; //Reset X pos.
	m_y++;
	for (int i = 0; i < c_totalSurvivalSegments; i++)
	{
		m_x++;

		if (i == 45) { //If top wall is at the furthest position, reset X position.
			m_x = 4;
		}

		m_wallSegments[i].setCurrentPosX(m_x);
		m_wallSegments[i].setCurrentPosY(m_y);
		m_wallSegments[i].setCharacter('*');

		if (i >= 45) {
			m_wallSegments[i].setCurrentPosY(m_wallSegments[5].getCurrentPosY() + 1); //Set second wall Y above the other wall (2 layered wall).
		}
	}

	for (int i = 0; i < 5; i++) { 
		m_wallSegments[m_randNum + i].setCharacter(' '); //Generate a hole in the wall so the player can go through it.
		m_wallSegments[(m_randNum + i) + 45].setCharacter(' ');
	}

	resetWallPosition(); //Reset wall position function.
	render(); //Render the wall after update of wall segment positions occur.	
}

void SurvivalMode::resetWallPosition() {
	if (m_y > 21) { //If the Y pos of the wall is at value 21, reset the wall position to the top of the screen.
		unrender();
		m_x = 3;
		m_y = 3;
		generateRandomNum(); //Generate new number (used for creating a hole in the wall for player access to survive).
		for (int i = 0; i < c_totalSurvivalSegments; i++)
		{
			m_wallSegments[i].setCurrentPosX(m_x);
			m_x++;
		}
	}
}

void SurvivalMode::generateRandomNum() {
	m_randNum = rand() % 40; //Generate random number between 0 and 39.
}
