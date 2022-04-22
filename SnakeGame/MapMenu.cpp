#include "Helpers.h"
#include "MapHandler.h"
#include "MapMenu.h"
#include "MainMenu.h"

MapMenu::MapMenu()
{
	m_cursor.setMenuState(3);
}

void MapMenu::update()
{
	loadButtons(); //Load buttons on the Map Menu.
	m_cursor.positionCursor(); //Position cursor correctly.
	while (true) {
		displayMapPreview(); //Call the map preview function.
		m_cursor.input(); //Check for user input (key presses).
		m_cursor.update(); //Update cursor.
	}
}

void MapMenu::stateHandler(int currentState)
{
	system("CLS"); //Clear console.
	if (currentState == 3) 
	{
		MainMenu m_mainMenu; //Create instance of main menu.
		m_mainMenu.update(); //Load up the main menu.
	}
	else
	{
		m_game.run(currentState); //Run the correct map based on current state of the cursor.
	}
}

void MapMenu::loadButtons()
{	
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			color(6); //Gold.
			m_button[i].setText("   Castle"); //Set text of each button.
			break;
		case 1:
			color(9); //Blue.
			m_button[i].setText("Solar System");
			break;
		case 2:
			color(2); //Dark green.
			m_button[i].setText("   Jungle");
			break;
		case 3:
			color(4);
			m_button[i].setText("Return to Main Menu");
			break;
		}
		m_cursor.setMaxKeyPress(4); //Limit Y axis movement.
		m_button[i].setCurrentPosY(27);
		m_button[i].setCurrentPosXY(20, m_button[i].getCurrentPosY() + i);
		m_button[3].setCurrentPosX(17);
		m_button[i].render(); //Render buttons to console.
	}
}

void MapMenu::displayMapPreview() 
{
	MapHandler mapHandler; //Create map handler instance.
	mapHandler.render(m_cursor.getCurrentState()); //Generate map preview based on the current state of the cursor.
}
