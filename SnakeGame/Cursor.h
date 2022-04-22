#ifndef CURSOR_H
#define CURSOR_H

#include "CharacterObject.h"

class Cursor : public CharacterObject {
private:	
	bool	m_canMove;			//Bool to allow for cursor movement or not.
	int		m_menuState;		//Used for menu navigation.
	int		m_currentState;		//Used for button navigation.
	int		m_maxKeyPress;		//Limits how much the player can move cursor along Y axis.
	int		m_x;				// Set pos X.
	int		m_y;				//Set pos Y.

public:
	Cursor();

	void positionCursor();

	void input();
	void render();
	void unrender();
	void update();

	int getMaxKeyPress();
	void setMaxKeyPress(int maxKeyPress); //Limits how much the player can move the cursor.
	int getCurrentState();

	void setMenuState(int menuState); //Set menu state based on class instantiated.
	int getMenuState();
};


#endif // !CURSOR_H
