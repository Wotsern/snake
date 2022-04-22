#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <Windows.h>

#include "Helpers.h"
#include "MainMenu.h"
#include "SurvivalMode.h"
#include "MultiplayerMode.h"

MainMenu::MainMenu()
{
	m_cursor.setMenuState(0);
	m_mapHandler.render(5); //Render main menu image.
}

void MainMenu::update()
{
	loadButtons(); //Load buttons on the screen.
	m_cursor.positionCursor(); //Position cursor correctly.
	while (true) {
		m_cursor.input(); //Check for user input (key press).
		m_cursor.update(); //Update cursor position.
	}
}

void MainMenu::stateHandler(int currentState) //currentState parameter is gathered by user input up and down.
{
	system("CLS"); //Clear console.
	switch (currentState)
	{
	case 0: {
		MapMenu mapMenu; //Create instance of 'MapMenu' and run it.
		mapMenu.update();
		break;
	}
	case 1:
	{
		Game game; //Create instance of 'Game' and run it.
		game.run(4); //'4' is the survival map reference.
		break;
	}
	case 2:
	{
		MultiplayerMode mMode;
		mMode.update(4);
		break;
	}
	case 3: {
		ControlsMenu controlsMenu; //Create instance of 'ControlsMenu' and run it.
		controlsMenu.update();
		break;
	}
	case 4:
		exit(0); //Close the console.
		break;
	}	
}

void MainMenu::loadButtons()
{
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0:
			color(7); //Grey.
			m_button[i].setText("  Classic");
			break;
		case 1:
			color(8); //Dark grey.
			m_button[i].setText(" Survival");
			break;
		case 2:
			color(6); //Gold.
			m_button[i].setText("Multiplayer");
			break;
		case 3:
			color(12); //Red.
			m_button[i].setText("How to Play");
			break;
		case 4:
			color(4); //Dark red.
			m_button[i].setText("   Exit");
			break;
		}
		m_cursor.setMaxKeyPress(4); //Limit how many time the cursor can move up and down the Y axis.
		m_button[i].setCurrentPosY(26); //Position button on Y axis.
		m_button[i].setCurrentPosXY(20, m_button[i].getCurrentPosY() + i); //Position all buttons under eachother (+ i).
		m_button[i].render(); //Render buttons to screen.
	}
}

