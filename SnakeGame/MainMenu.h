#ifndef MAINMENU_H
#define MAINMENU_H

#include "Button.h"
#include "ControlsMenu.h"
#include "Cursor.h"
#include "MapHandler.h"
#include "MapMenu.h"

class MainMenu
{
private:
	MapHandler		m_mapHandler;			//Create instance of mapHandler.
	Cursor			m_cursor;				//Create instance of cursor.
	Button			m_button[5];			//Create array of 5 button instances.
public:
	MainMenu();								//Constructor.

	void update();

	void stateHandler(int currentState);	//Used for state handling on key press 'enter'.
	void loadButtons();						//Function that handles UI.	
	
};

#endif // !MAINMENU_H