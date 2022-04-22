#include <iostream>
#include <stdlib.h>
#include <Windows.h>

#include "Button.h"
#include "Cursor.h"
#include "EndingScene.h"
#include "Helpers.h"

EndingScene::EndingScene()
{
	m_cursor.setMenuState(5); //Set the current menu state.
	m_cursor.positionCursor(); //Position the cursor correctly.
	m_button.setCurrentPosXY(17, 25);
	m_button.setText("Return to Main Menu"); //Set text of button.
}

void EndingScene::update(RuntimeInterface* runtimeInterface)
{
	loadGameOverScene(); //'GAME OVER!' Text typewriter.
	while (true) {		
		color(15); //White.
		m_cursor.input(); //Check for user input.
		m_cursor.render(); //Display cursor on screen.
		m_button.render(); //Display 'Return to Main Menu' button.
		color(4); //Red.
		drawScore(runtimeInterface->getCurrentScore(), 22, 17);	//Display score on screen.
		color(15); //White.
	}
}

void EndingScene::loadGameOverScene()
{
	color(4); //Red.
	gotoxy(21, 15);
	int i;
	char words[] = "GAME OVER!"; //Text to display.
	for (i = 0; i < strlen(words); i++) { //Step through the character array for as many characters in it there are.
		Sleep(200); //0.2 seconds.
		putchar(words[i]); //putchar prints the current character in the array based on 'i' value.
		fflush(stdout);
	}
}