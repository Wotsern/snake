#include <conio.h>
#include <Windows.h>

#include "Cursor.h"
#include "ControlsMenu.h"
#include "Helpers.h"
#include "MainMenu.h"
#include "AudioHandler.h"


Cursor::Cursor()
{	
	m_canMove = true;
	m_currentState = 0;
	keybd_event(72, 0, 0, 0); //This is a keyboard event that is used to fix a bug that was happening.
}

void Cursor::positionCursor() //This function is used to position the cursor based on the current menu it is in.
{
	setCharacter('>'); //Set the cursor character to '>'.
	switch (m_menuState) { //Switch argument set to menu state to check for which menu is currently loaded.
	case 0:
		m_x = 18; //Set the X position to 18 if current menu value is 0.
		m_y = 26; //Set the Y position to 26 if current menu value is 0.
		break;
	case 2:
		m_x = 14;
		m_y = 27;
		break;
	case 3:
		m_x = 15;
		m_y = 27;
		break;
	case 5:
		m_x = 14;
		m_y = 25;
		break;
	}
}

void Cursor::input()
{
	color(15);
	char key = _getch();
	if (_kbhit) {		
		switch (key) {
		case 72: //Down key.
			if (m_currentState > 0 && m_canMove == true)
			{ //The 'm_canMove' check is for menus with only one button.
				m_y--;
				m_currentState--; //Decrease 'm_currentState' value.
				PLAY_SOUND(4);
			}
			break;
		case 80: //Up key.
			if (m_currentState < m_maxKeyPress && m_canMove == true)
			{
				m_y++;
				m_currentState++; //Increase 'm_currentState' value.
				PLAY_SOUND(4);
			}
			break;
		case 13: //Enter key.
			system("CLS");
			PLAY_SOUND(2);
			switch (m_menuState) //Check for menu state.
			{
			case 0:
			{
				MainMenu m_mainMenu; //Create instance of 'MainMenu'.
				m_mainMenu.stateHandler(getCurrentState()); //Call required function.
				break;
			}
			case 1: 
			{
				SurvivalMode m_survivalMode;
				m_survivalMode.update();
			}
			case 2: {
				ControlsMenu m_controlsMenu;
				m_controlsMenu.stateHandler(getCurrentState());
				break;
			}
			case 3: {
				MapMenu m_mapMenu;
				m_mapMenu.stateHandler(getCurrentState());
				break;
			}
			case 4:
				exit(0); //Exit the program.
				break;
			case 5:
			{
				MainMenu main;
				main.update();
				break;
			}
			}
		break;
		}
		unrender();
	}	
	setCurrentPosX(m_x); //Update X position of cursor.
	setCurrentPosY(m_y); //Update Y position of cursor.
}

void Cursor::render()
{
	switch (m_menuState) {
	case 2: case 5: //2: Controls Menu. 5: Game Over Menu.
		m_canMove = false; //Disable cursor movement.
		break;
	default:
		m_canMove = true; //Enable cursor movement.
		break;
	}
	drawChar(getCharacter(), getCurrentPosX(), getCurrentPosY()); //Draw the cursor to the screen.
}

void Cursor::unrender()
{
	drawChar(' ', getCurrentPosX(), getCurrentPosY()); //Unrender the cursor.
}

void Cursor::update()
{	
	render();
}

int Cursor::getMaxKeyPress()
{
	return m_maxKeyPress; //Get how many key presses the player can do.
}

void Cursor::setMaxKeyPress(int maxKeyPress)
{
	m_maxKeyPress = maxKeyPress; //Set max key presses.
}

int Cursor::getCurrentState()
{
	return m_currentState; //Get current state.
}

void Cursor::setMenuState(int menuState)
{
	m_menuState = menuState; //Set current menu state.
}

int Cursor::getMenuState()
{
	return m_menuState; //Get current menu state.
}
