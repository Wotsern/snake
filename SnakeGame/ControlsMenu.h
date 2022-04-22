#ifndef CONTROLSMENU_H
#define CONTROLSMENU_H

#include <iostream>

#include "Cursor.h"
#include "Helpers.h"
#include "MainMenu.h"

class ControlsMenu
{
private:
	Cursor		m_cursor; //Create instance of cursor.

public:
	ControlsMenu();

	void update();

	void stateHandler(int currentState); //Function that handles UI.
	void loadControls(); //Displays the controls for the game.
};

#endif // !CONTROLSMENU_H