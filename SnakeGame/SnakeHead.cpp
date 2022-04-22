#include <conio.h>
#include <iostream>

#include "Food.h"
#include "Helpers.h"
#include "SnakeHead.h"

SnakeHead::SnakeHead()
{
	m_c = 'O';
	m_x = 46;
	m_y = 24;
	m_currentKey = 2;
}

void SnakeHead::update()
{
	inputManager(); //Check for player input (key presses).
	playerMovement(); //Move the player head.
}

void SnakeHead::render()
{
	drawChar(m_c, getCurrentPosX(), getCurrentPosY()); //Render the snake head.
}

void SnakeHead::unrender() 
{
	drawChar(' ', getCurrentPosX(), getCurrentPosY()); //Unrender the snake head.
}

void SnakeHead::inputManager() {
	if (_kbhit()) { //Check if keyboard is clicked.
		char ch = _getch();
		switch (ch) //Check the button pressed as switch argument.
		{
		case 0x48: case 'w'://Up key.
			m_currentKey = 0; //Set movement direction.
			break;
		case 0x50: case 's'://Down key.
			m_currentKey = 1;
			break;
		case 0x4b: case 'a'://Left key.
			m_currentKey = 2;
			break;
		case 0x4d: case 'd'://Right key.
			m_currentKey = 3;
			break;
		}
	}
}

void SnakeHead::playerMovement()
{
		switch (m_currentKey) { //m_currentKey as argument.
		case 0:
			m_y--; //If down pressed, move down the Y axis.
			break;
		case 1:
			m_y++;
			break;
		case 2:
			m_x = m_x - 2;
			break;
		case 3:
			m_x = m_x + 2;
			break;
		}
	setCurrentPosX(m_x); //Update X pos.
	setCurrentPosY(m_y); //Update Y pos.
}
