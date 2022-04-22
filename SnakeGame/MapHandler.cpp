#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <tchar.h>
#include <Windows.h>
#include "MapHandler.h"

#include "AudioHandler.h"
#include "EndingScene.h"
#include "Settings.h"

MapHandler::MapHandler()
{
	initialise();
}

void MapHandler::initialise() {
	m_x = 2;
	m_y = 1;
	m_currentWall = 0;
	m_wallCollided = false;
	m_rows = m_mapHeight;
	m_columns = m_mapWidth;
}

void MapHandler::render(int mapNumber)
{
	color(4); //Dark red.
	loadMap(mapNumber); //Load desired map.
	buildMap(); //Build the map.
	for (int i = 0; i < c_totalWallSegments; i ++)
	{
		drawChar(m_wallSegments[i].getCharacter(), m_wallSegments[i].getCurrentPosX(), m_wallSegments[i].getCurrentPosY()); //Draw wall segments to the console.
	}
}

void MapHandler::drawScore(int score)
{
	std::cout << score; //Draw score to the console.
}

void MapHandler::loadMap(int mapNumber) {

	std::string mapChoice;
	
	switch (mapNumber) { //Map number as argument.
	case 0:
		color(6);
		mapChoice = "snakeMap1.txt"; //Load this text file if the desired map is '0'.
		break;
	case 1:
		color(9);
		mapChoice = "snakeMap2.txt";
		break;
	case 2:
		color(2);
		mapChoice = "snakeMap3.txt";
		break;
	case 3:
		mapChoice = "returnArrow.txt";
		break;
	case 4:
		color(7);
		mapChoice = "snakeMap4.txt";
		break;
	case 5:
		color(10);
		mapChoice = "menuPicture.txt"; //Main menu image.
		break;
	case 6:
		color(7);
		mapChoice = "snakeMap4.txt";
		break;
	}

	std::ifstream mapFile(mapChoice); //Grab text file.

	for (int mapRow = 0; mapRow < m_rows; mapRow++) //Loop for the amount of rows.
	{
		std::string fileRow; //Grab current file row in the text file.
		std::getline(mapFile, fileRow);

		std::stringstream stringstream(fileRow); //Grab strings within the current row.

		for (int mapColumn = 0; mapColumn < m_columns; mapColumn++) //Loop for the amount of columns.
		{
			std::string mapElement;
			std::getline(stringstream, mapElement, ','); //Seperate strings vis ','.

			std::stringstream converter(mapElement); //Convert data gathered, ready to input into an array.
			converter >> m_mapGrid[mapRow][mapColumn]; //Store the converted values into a 2D array.
		}
	}
}

void MapHandler::buildMap()
{
	for (int r = 0; r < m_rows; r++)
	{
		for (int c = 0; c < m_columns; c++)
		{		
			switch (m_mapGrid[r][c]) //Argument 2D array.
			{
			case 0:
				m_wallSegments[m_currentWall].setCharacter(' '); //If the string value is 0, print an empty string.
				break;
			case 1:
				m_wallSegments[m_currentWall].setCharacter('='); //If the string value is 1, print a '-=' character.
				break;
			}
			m_wallSegments[m_currentWall].setCurrentPosXY(m_x, m_y); //Set the position of the wall segment.
			if ((m_x % 25) == 0) { //If the 'm_x' value is equal to 25 then go to a new line.
				m_x = 0; //Set 'm_x' back to 0.
				m_y++; //Increase Y axis each loop.
			}
			m_x = m_x + 2; 
			m_currentWall++; //Increase current wall.
		}
	}
}

void MapHandler::checkCollision(int xPos, int yPos, RuntimeInterface* runtimeInterface)
{
	for (int i = 0; i < c_totalWallSegments; i++)
	{
		if (m_wallSegments[i].getCurrentPosX() == xPos && m_wallSegments[i].getCurrentPosY() == yPos && m_wallSegments[i].getCharacter() == '=') { //Check to see if the snake head collides with a '=' character.
			system("CLS"); //Clear console.
			PLAY_SOUND(1); //Macro to play music.
			EndingScene endingScene; //Create ending scene instance.
			endingScene.update(runtimeInterface); //Run the desired function within 'EndingScene'.
		}
	}
}

CharacterObject MapHandler::getSegmentArray(int i)
{
	return m_wallSegments[i]; //Get array of 'wallSegments'.
}

void MapHandler::setMapNumber(int mapNumber)
{
	m_mapToLoad = mapNumber; //Setter for the 'm_mapToLoad'.
}

int MapHandler::getMapNumber()
{
	return m_mapToLoad; //Get map number.
}
