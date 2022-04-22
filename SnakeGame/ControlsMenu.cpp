#include <iostream>

#include "ControlsMenu.h"
#include "MainMenu.h"

ControlsMenu::ControlsMenu()
{
	m_cursor.setMenuState(2); //Set menu state to 2.
}

void ControlsMenu::update()
{
	loadControls(); //Display controls on how to play.
	m_cursor.positionCursor(); //Position cursor correctly.
	while (true) {
		m_cursor.input(); //Check for user input.
		m_cursor.update(); //Render the cursor.
	}
}

void ControlsMenu::stateHandler(int currentState)
{
	system("CLS"); //Clear screen.
	switch (currentState)
	{
	case 0:	
		MainMenu m_mainMenu;
		m_mainMenu.update(); //Return to main menu.
		break;
	}
}

void ControlsMenu::loadControls()    //Write control instructions to the screen.
{	
#pragma region Text
	color(7);
	gotoxy(2, 1);
	std::cout << " Use the controls shown below to move the snake \n  around the map. Avoid colliding with yourself and \n    the walls. Find pieces of food located around \n   the map in order to grow your snake and increase \n                     your score.";
	color(8);
	gotoxy(2, 7);
	std::cout << " Feeling unstoppable? Survival is an endless wave \n   mode in which you will be faced with collapsing \n   walls. Be quick, fit through the gap and collect \n   food to increase your score; this challenge is a \n                true test of skill.";
	color(7);
	gotoxy(2, 13);
	std::cout << " Enjoy Snake with your friends with the multiplayer \n    mode. Work together to obtain as much food as \n     possible; however, be careful as you don't \n      want to get in eachothers way. Have fun!";
	color(1);
	gotoxy(1, 20);
	std::cout << "NUMPAD:                     Keyboard:";
	color(3);
	gotoxy(10, 20);	
	std::cout << "UP";
	gotoxy(43, 20);
	std::cout << "W";
	gotoxy(9, 24);
	std::cout << "DOWN";
	gotoxy(43, 24);
	std::cout << "S";
	gotoxy(1, 24);
	std::cout << "LEFT";
	gotoxy(35, 24);
	std::cout << "A";
	gotoxy(18, 24);
	std::cout << "RIGHT";
	gotoxy(52, 24);
	std::cout << "D";
	color(4);
	gotoxy(17, 27);
	std::cout << "Return to Main Menu";
#pragma endregion
}