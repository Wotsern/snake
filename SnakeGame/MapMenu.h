#ifndef MAPMENU_H
#define MAPMENU_H

#include "Button.h"
#include "Cursor.h"
#include "Game.h"

class MapMenu 
{
private:
	Game		m_game;			//Create instance of Game class.

	Button		m_button[4];	//Create array of 4 buttons.
	Cursor		m_cursor;		//Create instance of cursor.
public:
	MapMenu();

	void update();

	void stateHandler(int currentState);
	void loadButtons(); //Load buttons on the map menu.
	void displayMapPreview(); //Showcase the hovered map.
};



#endif // !MAPMENU_H
